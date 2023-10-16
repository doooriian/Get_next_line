/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:44:20 by dley              #+#    #+#             */
/*   Updated: 2023/10/16 23:02:25 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Fonction qui calcul la longueur d'une chaine de caractere
et qui renvoie le resultat */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*  - Fonction utilisée pour rechercher la première occurrence d'un 
caractère donné dans une chaîne de caractères
	- Elle renvoie un pointeur vers la première occurrence du caractère 
recherché dans la chaîne, ou un pointeur nul (NULL) s'il ne le trouve pas.*/

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (unsigned char) c)
			return ((char *) str);
		str++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) str);
	return (NULL);
}

// Ajout uniquement pour l'utilisation de ft_strjoin

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/* Alloue et retourne une nouvelle chaîne, résultat de la 
concaténation de s1 et s2 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(len * sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcpy(join + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (join);
}
