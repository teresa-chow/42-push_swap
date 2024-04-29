/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:12:24 by tchow-so          #+#    #+#             */
/*   Updated: 2024/01/02 08:07:21 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* calculate length of string */
int	ft_strlen_gnl(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/* find char in string */
char	*ft_strchr_gnl(const char *str, int c)
{
	while ((*str) && ((unsigned char)*str != (unsigned char)c))
		str++;
	if ((unsigned char)*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

/* join two strings */
char	*ft_strjoin_gnl(char *str, char *next_buffer)
{
	char	*new_str;
	char	*ptr_str;
	int		len;
	int		i;

	ptr_str = str;
	len = ft_strlen_gnl(str) + ft_strlen_gnl(next_buffer);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*str)
		new_str[i++] = *str++;
	while (*next_buffer)
		new_str[i++] = *next_buffer++;
	new_str[i] = '\0';
	if (ptr_str)
		free(ptr_str);
	return (new_str);
}
