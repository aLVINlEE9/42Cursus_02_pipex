#include<stdio.h>
#include <unistd.h>

int main()
{
	int fd[2];
	int	temp;
	char buff[] = "hey";
	char read_buff[100];

	pipe(fd);
	temp = dup(fd[1]);
	printf("fd[1] : %d temp : %d\n", fd[1], temp);

	write(temp, buff, sizeof(buff));
	read(fd[0], read_buff, sizeof(read_buff));
	printf("%s", read_buff);
}
