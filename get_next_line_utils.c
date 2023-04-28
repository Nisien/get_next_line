/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:16:21 by nrossa            #+#    #+#             */
/*   Updated: 2023/04/28 15:17:37 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s, ssize_t nb)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * (nb + 1));
	if (!dst)
		return (NULL);
	while (s[i] && i < nb)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t nb)
{
	char	*dst;
	ssize_t	i;
	ssize_t	c;

	if (!s2)
		return (NULL);
	s2[nb] = '\0';
	if (!s1)
		return (ft_strdup(s2, nb));
	dst = malloc(sizeof(char) * (ft_strlen(s1) + nb + 1));
	if (!dst)
		return (NULL);
	i = 0;
	c = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (c < nb)
		dst[i++] = s2[c++];
	dst[i] = '\0';
	if (s1)
		free(s1);
	return (dst);
}
