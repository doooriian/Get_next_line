/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:43:56 by dley              #+#    #+#             */
/*   Updated: 2023/10/16 22:42:49 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stock(char *stash)
{
	char	*stock;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (NULL);
	stock = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	i++;
	j = 0;
	while (stash[i])
	{
		stock[j] = stash[i];
		i++;
		j++;
	}
	stash = stock;
	free(stock);
	return (stash);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		line[i] = stash[i];
		i++;
	}	
	stash = line;
	free(line);
	return (stash);
}

/* parcours le fichier et stock le resultat dans "stash", renvoie stash 
une fois qu'un "/n" est trouve ou qu'on est a la fin du fichier. */

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = (int)(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = ft_read(fd, stash);
	line = ft_line(stash);
	stash = ft_stock(stash);
	return (line);
}

// ssize_t	read(int fd, void *buffer, size_t nbyte);