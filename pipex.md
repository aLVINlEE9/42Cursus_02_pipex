# PIPEX 정리

## Subject

 ```{.bash}
 ./pipex file1 cmd1 cmd2 file2
 ```
위와 같이 실행했을 때, 아래 쉘 명령어와 같은 동작을 하도록 하는 프로그램 `pipex` 만들기.
 ```{.bash}
 < file1 cmd1 | cmd2 > file2 
 ```
### 사전지식

- 멀티 프로세스 프로그래밍


- 파이프 시스템 콜


- file descriptor 관리 시스템


- 여러 함수들의 사용 방법
	- fork

		- 의존성
		```c
		#include <unistd.h>
		```
		- 함수원형
		```c
		pid_t fork(void);
		```
		- 작동방식
		> fork()를 실행하면 fork 함수가 실행 된 직후에 자식 프로세스 부모 프로레스와 동일한 주소 공간의 복사본을 가지게 됩니다.
		
		> 부모 프로세스에서는 자식 프로세스의 PID값을 반환 받음
		
		> 부모 프로세스가 끝나면 자식프로세스 실행

		> 참고 : https://codetravel.tistory.com/23
	- pipe

		- 의존성
		```c
		#include <unistd.h>
		```
		- 함수원형
		```c
		int pipe(int fd[2]);		
		```
		> 파일디스크립터 fd[1]은 쓰기용 파이프, fd[0]은 읽기용 파이프
	
		> ![R1280x0](https://user-images.githubusercontent.com/74805318/130620962-3455ba4f-9ad5-4d04-8f87-7eb75746aaaa.png)

		
		> 참고 : https://reakwon.tistory.com/80
	- dup, dup2

		- 의존성
		```c
		#include <unistd.h>
		```
		- 함수원형
		```c
		int dup(int fd);
		```
		```c
		int dup2(int fd, int fd2);
		```

		- 작동방식 (dup)
		> fd로 전달받은 파일 서술자를 복제하여 반환합니다. dup가 돌려주는 파일 서술자는 가장 낮은 서술자를 반환합니다. 성공시 새 파일 서술자, 오류시 -1을 반환합니다.
		
		> dup 함수에 넣은 fd 의 File descriptor를 복사하여 새로운 File desciptor의 가장 낮은 FD Table 의 index로 반환

		- 작동방식 (dup2)
		> 새 서술자의 값을 fd2로 지정합니다. 만일 fd2가 이미 열려있으면 fd2를 닫은 후 복제가 됩니다. 역시 성공시 새 파일 서술자, 오류시 -1을 반환합니다.
		
		> fd2 를 fd의 File Table의 inode를 가르키도록 만듬 <br>

		> 예시
		```c
		ret = dup2(fd, STDOUT_FILENO);
		write(fd, str, strlen(str));
		```
			fd = 3 <br>
			ret = 1 <br>
			fd파일의 내용 출력

		> 참고 https://reakwon.tistory.com/104

	- execve


		- 의존성
		```c
		#include <unistd.h>
		```
		- 함수원형
		```c
		int execve(const char *filename, char * const *argv, char * const *envp);
		```
		
		> execve는 filename이 가리키는 파일을 실행한다. 이 파일은 바이너리 실행파일이거나 스크립트 파일이여야 한다. argv와 envp는 포인터 배열로 filename의 인자로 들어간다. 마지막에 NULL문자열을 저장해야 한다.
		
		> 유닉스, 리눅스 시스템 콜 중 하나
		=덮어씌움
		exec() 시스템 콜을 호출한 현재 프로세스 공간의 TEXT, DATA, BSS 영역을 새로운 프로세스의 이미지로 덮어씌운다.
		별도의 프로세스 공간을 만들지 않는다.

		> 프로세스 안에 있는 exec() 시스템 콜 실행을 하면 새로운 프로세스를 만드는 것이 아니라 
		현재 만들어진 exec 인자에 들어가 있는 프로그램 실행 파일을 읽어서  
		현재 부모 프로세스 공간의 exec 인자에 있는 실행파일에 대한  
		TEXT, DATA, BSS 영역을 덮어 씌운다. (HEAP, STACK 은 동적영역이기 때문) 
		새로운 정보가 덮어씌워진다.
		exec 계열 함수는 현재 프로세스 이미지를 별도 메모리 공간에 복사하지 않는다.
		
	- wait, waitpid
		- 의존성
		```c
		#include <sys/wait.h>
		```
		- 함수원형
		```c
		pid_t wait(int *status);
		```
		```c
		pid_t waitpid(pid_t pid, int *status, int options);
		```
		
		wait : 자식 프로세스의 종료를 부모 프로세스에서 기다리는 함수

		watipid : 자식 프로세스의 종료를 부모 프로세스에서 기다리는 함수 + 옵션
		> 참고 : https://codetravel.tistory.com/30?category=993122 https://codetravel.tistory.com/42
		


<br>
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

<br>

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

<br>
<br>

## Implementing

### Redirection

#### file1 to stdin

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

#### stdout to file2

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

##### <perror 함수>

오류 상황을 표준오류스트림(stderr)에 출력하기 위한 라이브러리 함수다

- 의존성
```c
#include <stdio.h>
```
- 함수원형
```c
void perror(const char *str);
```

- 작동방식
> 시스템 호출이 실패하면 오류 코드를 전역변수 errno에 저장한다.

> 그리고 역시 전역변수 sys_errlist[errno]에 적절한 오류 메시지가 저장되어 있다.

> 그것을 인수로 받은 str과 함께 출력해줌
 



<br>

### Pipe
