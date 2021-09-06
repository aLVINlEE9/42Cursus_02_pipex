#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int i;
	char **path;

	i = 0;
	while(!ft_strnstr(envp[i], "PATH", 4))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while(path[i++])
		printf("%s\n", path[i]);
}
