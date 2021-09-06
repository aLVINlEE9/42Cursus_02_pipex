/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:25:00 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/20 20:16:16 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char *s1, char *set)
{
	int		i;
	int		len;

	len = ft_strlen(s1);
	i = -1;
	while (++i < len)
		if (!ft_strchr(set, s1[i]))
			break ;
	return (i);
}

int	ft_end(char *s1, char *set)
{
	int		i;
	int		len;

	len = ft_strlen(s1);
	i = -1;
	while (++i < len)
		if (!ft_strchr(set, s1[len - (i + 1)]))
			break ;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup((char *)s1));
	start = ft_start((char *)s1, (char *)set);
	end = ft_end((char *)s1, (char *)set);
	if (start >= end)
		return (ft_strdup(""));
	ptr = (char *)malloc(end - start + 1);
	if (!(ptr))
		return (0);
	ft_strlcpy(ptr, (char *)s1 + start, end - start + 1);
	return (ptr);
}
