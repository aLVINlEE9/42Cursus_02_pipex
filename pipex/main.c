#include <unistd.h>

int	redirect_in(const char *file);
int	redirect_out(const char *file);

int main(int argc, char const *argv[])
{
	redirect_in(argv[1]);
	redirect_out(argv[2]);
	execve("/bin/cat", 0, 0);
	return (0);
}
