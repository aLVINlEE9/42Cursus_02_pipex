/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:08:38 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/06 16:03:42 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char **paths;
	char *path_push;
	char *path;
	int	i;

	i = 0;
	while (!strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	while (paths[i++])
	{
		path_push = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_push, cmd);
		//printf("%s\n", path);
		if (access(path, F_OK))
			return path;
	}
	return (0);
}

int	execute(char *cmd, char **envp)
{
	char	**cmd_arr;

	cmd_arr = ft_split(cmd, ' ');
	execve(find_path(cmd_arr[0], envp), cmd_arr, 0);
	return (0);
}

int cmd_child(int *fd_pipe, char *cmd, char **envp)
{
	//printf("cmd_child\n");
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[0]);
	execute(cmd, envp);
	return (0);
}

int	cmd_parent(int *fd_pipe, char *cmd, char **envp)
{
	dup2(fd_pipe[0], STDIN_FILENO);
	close(fd_pipe[1]);
	execute(cmd, envp);
	return (0);
}

int redirect_in(char **argv)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY);
	dup2(file_in, STDIN_FILENO);
	//printf("red_in\n");
	return (0);
}

int	redirect_out(char **argv)
{
	int file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(file_out, STDOUT_FILENO);
	printf("red_out\n");
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	int	fd_pipe[2]; // pipe array
	int	pid;

	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
	{
		//printf("child process\n");
		redirect_in(argv);
		cmd_child(fd_pipe, argv[2], envp);
	}
	waitpid(pid, NULL, 0);
	//printf("parent process\n");
	redirect_out(argv);
	cmd_parent(fd_pipe, argv[3], envp);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
}
