# PIPEX 정리

## 문제

 ```{.bash}
 ./pipex file1 cmd1 cmd2 file2
 ```
위와 같이 실행했을 때, 아래 쉘 명령어와 같은 동작을 하도록 하는 프로그램 `pipex` 만들기.
 ```{.bash}
 < file1 cmd1 | cmd2 > file2 
 ```
<br>

## Objects

### Redirection

#### `<` : 지정된 파일의 내용을 표준 입력으로 넘겨줌.

#### `>` : 반대로 표준 출력에 전달된 내용을 지정된 파일로 넘겨줌. 

#### 에시

```{.bash}
 < in wc > out
 ```
> in 의 내용을 wc 명령어 한테 표준 입력으로 넘겨줌 

> 그 출력된 표준 출력을 out파일에 넘겨줌

> 결과 : [in(내용) wc ] 의 표준 출력이 out 파일에 저장됨


### Pipe

#### `|` : 파이프 명령어로, 여러 프로그램을 묶어주는 역할을 함. 
<br>

`cmd1 | cmd2`를 실행하면 `cmd1`과 `cmd2`가 동시에 실행되며, `cmd1`의 표준 출력이 `cmd2`표준 입력으로 넘어감.

따라서 파이프라인 `< file1 cmd1 | cmd2 > file2`를 실행하면 `file1`의 내용이 표준입력으로 `cmd1` 프로세스에 전달되고, `cmd1`의 처리 결과는 표준출력을 통해 `cmd2`로, `cmd2`의 처리 결과는 표준 출력 대신 `file2`로 전달되는 데이터 흐름임.

```c
file1 ------> cmd1 -----------> cmd2 -----> file2
             ^    ^            ^    ^
        (stdin)  (stdout) (stdin)  (stdout)
```

- 참고
```{.bash}
cmd1 | cmd2
```
```{.bash}
cmd1 > temp_file && cmd2 < temp_file
```
> 둘은 같은 역할

> https://rottk.tistory.com/entry/Redirection과-Pipe의-차이가-무엇인가요


## Implementing

### file1 to stdin

`file1`을 열어서 표준 입력으로 보내는 단계. `open()`으로 얻은 `fd`를 `dup2()`를 이용해 표준입력(`STDIN_FILENO` = `0`)으로 복사하고, `file1`을 닫음.

```c
int	redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}
```
테스트를 위해 표준 입력의 내용을 `cat`하도록 `main()` 함수를 구성함.
```c
int main(int argc, char const *argv[])
{
	redirect_in(argv[1]);
	execve("/bin/cat", 0, 0);
	return (0);
}
```

### stdout to file2

표준 출력에 있는 스트림을 `file2`로 보내는 단계. 표준 출력의 내용이 파일에 기록되도록 `file2`의 `fd`를 `STDOUT_FILENO`(= `1`)에 복사하고, `file2`를 닫음.

```c
int	redirect_out(const char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
```
테스트 `main()` 함수
```c
int main(int argc, char const *argv[])
{
	redirect_in(argv[1]);
	redirect_out(argv[2]);
	return (0);
}
```
