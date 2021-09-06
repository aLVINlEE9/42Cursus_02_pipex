/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:13:18 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/23 17:05:23 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	c_a;

	i = 0;
	ptr = b;
	while (i++ < len)
	{
		c_a = c;
		*ptr = c_a;
		ptr++;
	}
	return (b);
}
