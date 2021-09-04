#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	redirect_in(char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return 0;
}

int redirect_out(char **argv)
{
	int fd;
	return (0);
}

int main(int argc, char **argv)
{
	char buff[100];

	redirect_in(argv);
	read(STDIN_FILENO, buff, sizeof(buff));
	printf("%s", buff);
}
