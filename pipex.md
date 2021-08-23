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

## Redirection

#### `<` : 지정된 파일의 내용을 표준 입력으로 넘겨줌.

#### `>` : 반대로 표준 출력에 전달된 내용을 지정된 파일로 넘겨줌. 

#### 에시

```{.bash}
 < in wc > out
 ```
> in 의 내용을 wc 명령어 한테 표준 입력으로 넘겨줌 

> 그 출력된 표준 출력을 out파일에 넘겨줌

> 결과 : [in(내용) wc ] 의 표준 출력이 out 파일에 저장됨


## Pipe

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
