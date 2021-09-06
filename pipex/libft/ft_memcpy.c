/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:12:55 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/19 14:32:52 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_u;
	unsigned char	*src_u;

	i = 0;
	dst_u = (unsigned char *)dst;
	src_u = (unsigned char *)src;
	if (dst_u == NULL && src_u == NULL)
		return (NULL);
	while (n--)
	{
		dst_u[i] = src_u[i];
		i++;
	}
	return (dst);
}
