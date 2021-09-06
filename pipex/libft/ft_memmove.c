/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:13:08 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/18 17:02:09 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	size_t			i;
	size_t			f;
	unsigned char	*buffer_s;
	unsigned char	*buffer_d;

	i = 0;
	f = 1;
	buffer_d = (unsigned char *)dst;
	buffer_s = (unsigned char *)src;
	if (buffer_d == NULL && buffer_s == NULL)
		return (NULL);
	if (buffer_d > buffer_s)
	{
		f = -1;
		buffer_d += (num - 1);
		buffer_s += (num - 1);
	}
	while (i++ < num)
	{
		*buffer_d = *buffer_s;
		buffer_d += f;
		buffer_s += f;
	}
	return ((unsigned char *)dst);
}
