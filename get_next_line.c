/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:43:56 by dley              #+#    #+#             */
/*   Updated: 2023/10/16 20:22:08 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_extract(char *stash)
{
	ssize_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return (i);
}

/* parcours le fichier et stock le resultat dans "stock", renvoie 
stock une fois qu'un "/n" est trouve. */

char	*ft_line(int fd, char *stash, char *buffer)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = (int)(fd, buffer, BUFFER_SIZE);
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buffer;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc (sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stash = ft_line(fd, stash, buffer);
	i = ft_extract(stash);
	line = ft_substr(stash, 0, i);
	stash = ft_substr(stash, i + 1, strlen(stash));
	return (buffer);
}

// ssize_t	read(int fd, void *buffer, size_t nbyte);