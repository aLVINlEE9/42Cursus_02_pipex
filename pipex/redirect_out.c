#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int redirect_out(const char *file)
{
	int	fd;

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
