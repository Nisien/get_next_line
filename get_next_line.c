/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:16:03 by nrossa            #+#    #+#             */
/*   Updated: 2023/04/28 15:15:34 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_setbuf(size_t n)
{
	char	*result;

	result = malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	*ft_clean_stash(char *stash)
{
	char	*temp;
	char	*search;

	if (!stash)
		return (NULL);
	search = ft_strchr(stash, '\n') + 1;
	temp = ft_strdup(search, ft_strlen(search));
	free(stash);
	return (temp);
}

char	*ft_get_line(char *stash)
{
	char	*search;
	char	*result;
	size_t	size;

	if (!stash)
		return (NULL);
	search = ft_strchr(stash, '\n');
	if (!search)
		return (NULL);
	else
	{
		size = search - stash + 2;
		result = malloc(sizeof(char) * (size));
		if (!result)
			return (NULL);
		ft_strlcpy(result, stash, size);
		return (result);
	}
}

char	*ft_get_stash(char **stash)
{
	char	*result;

	if (!*stash[0])
	{
		free(*stash);
		stash = NULL;
		return (NULL);
	}
	result = ft_get_line(*stash);
	if (result)
	{
		*stash = ft_clean_stash(*stash);
		return (result);
	}
	else
	{
		result = ft_strdup(*stash, ft_strlen(*stash));
		free(*stash);
		*stash = NULL;
		return (result);
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*result;
	static char	*stash;
	ssize_t		count;

	buf = ft_setbuf(BUFFER_SIZE);
	count = read(fd, buf, BUFFER_SIZE);
	while (0 < count)
	{
		stash = ft_strjoin(stash, buf, count);
		result = ft_get_line(stash);
		if (result)
		{
			stash = ft_clean_stash(stash);
			free(buf);
			return (result);
		}
		count = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (!count && stash)
		return (result = ft_get_stash(&stash));
	return (NULL);
}
