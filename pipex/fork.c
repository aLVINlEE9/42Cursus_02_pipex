#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int x;
    x = 0;
		printf("start\n");
    pid = fork();
		printf("fork\n");
    if(pid > 0) {  // 부모 코드
        x = 1;
        printf("부모 PID : %ld,  x : %d , pid : %d\n",(long)getpid(), x, pid);
    }
    else if(pid == 0){  // 자식 코드
        x = 2;
        printf("자식 PID : %ld,  x : %d\n",(long)getpid(), x);
    }
    else {  // fork 실패
        printf("fork Fail! \n");
        return -1;
    }
		printf("공통\n");
    return 0;
}

