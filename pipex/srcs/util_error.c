/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:44:36 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/06 19:52:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_util(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i++])
		free(cmd[i]);
	free(cmd);
}

void	error(char **cmd, char *path, char *str, int f)
{
	if (f == 1)
		ft_putstr_fd(str, 2);
	else if (f == 2)
	{
		free(path);
		free_util(cmd);
		perror(str);
	}
	exit(EXIT_FAILURE);
}
