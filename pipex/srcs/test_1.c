#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int i;
	char **path;
	char *path_slash;
	char *cur_path;
	char *cmd;

	i = 0;
	while(!ft_strnstr(envp[i], "PATH", 4))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	cmd = argv[1];
	while(path[i++])
	{
		path_slash = ft_strjoin(path[i], "/");
		cur_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(cur_path, F_OK))
			break;
	}
	execve(cur_path, cmd, 0);
}
