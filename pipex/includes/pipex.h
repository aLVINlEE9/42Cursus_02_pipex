/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:15:53 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/07 16:17:36 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

int		redirect_in(char *argv, int *fd_pipe);
int		redirect_out(char *argv, int *fd_pipe);
char	*get_cmd_path(char *argv, char **envp);
char	**get_cmd(char *argv);
void	error(char **cmd, char *path, char *str, int f);
void	free_util(char **cmd);

#endif
