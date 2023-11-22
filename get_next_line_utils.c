/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:12:54 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/22 11:47:30 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s && (unsigned char)c == 0)
		return (ft_strlen(s) + (char *)s);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    char *ptr;
    int     i;

	if (!str)
	{
		ptr = malloc(sizeof(char));
		*ptr = 0;
		return (ptr);
	}
    ptr = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!ptr)
        return (0);
    
    i = 0;
    while (str[i])
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i] = 0;
    return (ptr);
}

char *ft_strjoin(char *s1, char *s2)
{
    int i;
    int j;
    char *ptr;

    if (!s1)
		s1 = ft_strdup("");
    i = 0;
    j = 0;
    ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!ptr)
        return (0);
    while (s1[i] && s1)
    {
        ptr[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        ptr[i] = s2[j];
        j++;
        i++;
    }
	free(s1);
    ptr[i] = 0;
    return (ptr);
}
