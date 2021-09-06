/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:44:34 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/20 20:18:00 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nmal_itoa(long num, int fd)
{
	char		ret;

	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	ret = '0' + (num % 10);
	num /= 10;
	if (num == 0)
	{
		write(fd, &ret, 1);
		return ;
	}
	ft_nmal_itoa(num, fd);
	write(fd, &ret, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_nmal_itoa(n, fd);
	return ;
}
