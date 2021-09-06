/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:05:20 by seungsle          #+#    #+#             */
/*   Updated: 2021/05/23 16:02:50 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_1;
	size_t	size_2;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (size_1 + size_2 + 1));
	if (!(ret))
		return (NULL);
	ret = ft_memcpy(ret, s1, sizeof(char) * size_1 + 1);
	ft_strlcat(ret, s2, size_1 + size_2 + 1);
	ret[size_1 + size_2] = '\0';
	return (ret);
}
