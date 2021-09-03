#include <stdio.h>
#include <unistd.h>

int main()
{
	int	fd1[2];
	int	fd2[2];
	char p_c[] = "hey child";
	char c_p[] = "hey parent";
	char buff[100];
	pid_t pid;


	pipe(fd1);
	pipe(fd2);
	pid = fork();
	if (pid == 0)
	{
		printf("%s", "자식 프로세스\n");
		read(fd1[0], buff, sizeof(buff));
		printf("자식이 받은 메시지: %s\n", buff);

		write(fd2[1], c_p, sizeof(c_p));
	}
	else
	{
		printf("%s", "부모 프로세스\n");
		write(fd1[1], p_c, sizeof(c_p));

		read(fd2[0], buff, sizeof(buff));
		printf("부모가 받은 메시지: %s\n", buff);
		sleep(5);
	}
}
