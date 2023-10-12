/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:43:56 by dley              #+#    #+#             */
/*   Updated: 2023/09/25 13:24:54 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_extract(char *stock)
{
	ssize_t	i;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	return (i);
}

/* parcours le fichier et stock le resultat dans "stock", renvoie 
stock une fois qu'un "/n" est trouve. */

char	*ft_line(int fd, char *stock, char *buffer)
{
	read(fd, buffer, BUFFER_SIZE);
	if (!ft_strchr(buffer, '\n'))
	{
		stock = ft_strjoin(stock, buffer);
		ft_line(fd, stock, buffer);
		return (stock);
	}
	else
		return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*stock;
	char			*buffer;
	ssize_t			i;

	buffer = malloc (sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stock = ft_line(fd, stock, buffer);
	i = ft_extract(stock);
	buffer = ft_substr(stock, 0, i);
	stock = ft_substr(stock, i + 1, strlen(stock));
	return (buffer);
}

// ssize_t	read(int fd, void *buffer, size_t nbyte);