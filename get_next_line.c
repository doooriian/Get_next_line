/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:43:56 by dley              #+#    #+#             */
/*   Updated: 2023/11/15 16:12:34 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_and_free(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

char	*ft_stock(char *stash)
{
	char	*stock;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash[i])
	{	
		free (stash);
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	stock = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	i++;
	while (stash[i])
	{
		stock[j] = stash[i];
		i++;
		j++;
	}
	free (stash);
	return (stock);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] != '\0')
		line[j] = '\n';
	line[j++] = '\0';
	return (line);
}

/* parcours le fichier et stock le resultat dans "stash", renvoie stash 
une fois qu'un "/n" est trouve ou qu'on est a la fin du fichier. */

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	if (!stash)
		stash = malloc(sizeof(char) * 1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_join_and_free(stash, buffer);
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
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_stock(stash);
	return (line);
}

// ssize_t	read(int fd, void *buffer, size_t nbyte);