#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("error");
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}
