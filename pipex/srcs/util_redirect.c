/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:01:50 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/06 17:01:52 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_in(char *argv, int *fd_pipe)
{
	int	fd_filein;

	fd_filein = open(argv, O_RDONLY);
	dup2(fd_filein, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[0]);
	return (0);
}

int	redirect_out(char *argv, int *fd_pipe)
{
	int	fd_fileout;

	fd_fileout = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	dup2(fd_fileout, STDOUT_FILENO);
	dup2(fd_pipe[0], STDIN_FILENO);
	close(fd_pipe[1]);
	return (0);
}
