#include<stdio.h>
#include<unistd.h>

int main()
{
	int fd[2];
	int fd1[2];
	int temp;
	char buff[100];
	char buff_1[100];
	char str[] = "abcdef";

	pipe(fd);
	pipe(fd1);

	temp = dup2(fd[1], fd1[1]);

	write(fd1[1], str, sizeof(str));
	read(fd1[0], buff, sizeof(buff));
	read(fd[0], buff_1, sizeof(buff_1));

	printf("fd[0] : %s, fd1[0] : %s", buff_1, buff);
}
