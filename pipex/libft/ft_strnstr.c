/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:52:05 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/20 12:31:24 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)hst);
	while (i < len && *hst)
	{
		h = (char *)hst;
		n = (char *)needle;
		j = i;
		if (*hst == *needle)
			while (*++h == *++n && *h && *n)
				if (!(++j < len))
					return (NULL);
		if (!*n)
			return ((char *)hst);
		hst++;
		i++;
	}
	return (NULL);
}
