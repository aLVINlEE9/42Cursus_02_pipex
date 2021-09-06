/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:07:44 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/06 16:11:12 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_in()
{

}

int	redirect_out()
{

}

int	parent_process()
{
	redirect_out();
}

int	child_process()
{
	redirect_in();
}

int main(int argc, char **argv, char **envp)
{
	int	pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		child_process();
	}
	waitpid(pid, NULL, 0);
	parent_process();
}
