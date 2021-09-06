#include "pipex.h"

int redirect_in(char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int redirect_out(char **argv)
{
	int fd;

	fd = open(argv[2], O_WRONLY | O_CREAT, 0777);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return(0);
}

int main(int argc, char **argv, char **envp)
{
	char buff[100];
	char *str[2];

	redirect_in(argv);
	redirect_out(argv);
	printf("%s", *envp);
	//execve(str[0], str, 0);
}
