/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:45:42 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/19 13:48:55 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen((const char *)dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (src_len + size);
	while (dst[i])
		i++;
	while (*src && i + 1 < size)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (src_len + dst_len);
}
