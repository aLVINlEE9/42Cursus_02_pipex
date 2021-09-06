/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:43:32 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/19 14:06:12 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		size;
	char		*ptr;

	i = -1;
	size = ft_strlen(s1);
	ptr = malloc(size + 1);
	if (!(ptr))
		return (NULL);
	while (++i < size)
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}
