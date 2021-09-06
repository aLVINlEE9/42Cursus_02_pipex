/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:01:03 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/06 17:44:13 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *argv, char **envp)
{
	int		i;
	char	**paths;
	char	*path_join;
	char	*path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i++])
	{
		path_join = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_join, argv);
		free(path_join);
		if (access(path, F_OK) == 0)
			return (path);
	}
	return (0);
}

char	**get_cmd(char *argv)
{
	return (ft_split(argv, ' '));
}

void	error(char *str, int f)
{
	if (f == 1)
		ft_putstr_fd(str, 2);
	else if (f == 2)
		perror(str);
}
