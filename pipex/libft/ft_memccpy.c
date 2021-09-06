/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:12:40 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/19 14:33:01 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c_u;
	unsigned char	*dst_u;
	unsigned char	*src_u;

	i = 0;
	c_u = (unsigned char)c;
	dst_u = (unsigned char *)dst;
	src_u = (unsigned char *)src;
	if (dst_u == NULL && src_u == NULL)
		return (NULL);
	while (i < n)
	{
		dst_u[i] = src_u[i];
		if (c_u == src_u[i])
			return (dst_u + i + 1);
		i++;
	}
	return (NULL);
}
