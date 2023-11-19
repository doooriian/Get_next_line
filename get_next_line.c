/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:43:56 by dley              #+#    #+#             */
/*   Updated: 2023/11/19 17:22:12 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	- Lis le fichier, et stock ce qui est lu au fur a 
**	mesure dans "stock"
**	- Retourne "stock" */

char	*ft_read(int fd, char *stock, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stock)
			stock = ft_strdup("");
		tmp = stock;
		stock = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(stock, '\n'))
			break ;
	}
	return (stock);
}

/*	- Prends le contenu de line, met ce qu'il reste apres
	la ligne lue dans "stock" et le retourne
**	- Rajoute le caractere null a la fin de la ligne (dans
**	la variable line) */

char	*ft_extract(char *line)
{
	size_t	i;
	char	*stock;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	stock = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!stock)
		return (NULL);
	if (*stock == '\0')
	{
		free(stock);
		stock = NULL;
	}
	line[i + 1] = '\0';
	return (stock);
}

/*	- Fonction principale du code, c'est dedans qu'on appel les vus 
**	plus tot
**	- Elle retourne la ligne lu et stock le "reste" (si il y en a)
**	dans "stock" */

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read(fd, stock, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stock = ft_extract(line);
	return (line);
}
