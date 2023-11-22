/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:28 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/22 11:50:02 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int ft_check(char *str, char c)
{
    int i;

    i = 0;
	if (!str)
		return (-1);
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
	if (str[i] == 0 && i)
		return (i);
    return (-1);
}


char *get_read(char *ptr, int fd)
{
    char *str;
    ssize_t i;

    i = 1;
	if (BUFFER_SIZE)
    	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!str)
        return (NULL);
    while (ft_check(str, '\n') == -1)
    {
        i = read(fd, str, BUFFER_SIZE);
        if (i == -1)
        {
            free(str);
			free(ptr);
            return (NULL);
        }
        ptr = ft_strjoin(ptr, str);
		if (i == 0)
		{
			free(str);
			return (ptr);
		}
    }
	free(str);
	return (ptr);
}

char	*ft_substr(char *str, int start, int len)
{
	int i;
	char *ptr;

	ptr = malloc(sizeof(char) * (1 + len - start));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char *ft_cutstring(char *ptr, int i)
{
	int tmp;
	char *str;

	if (ptr[i + 1])
		i++;
	tmp = i;
	while (ptr[i])
		i++;
	str = malloc(sizeof(char) * (2 + i - tmp));
	if (!str)
		return (NULL);
	i = 0;
	while (ptr[tmp])
	{
		str[i] = ptr[tmp];
		i++;
		tmp++;
	}
	str[i] = 0;
	return (str);
}

char *get_next_line(int fd)
{
    static char	*ptr;
	char		*str;
	char		*tmp;
	int			i;

    if (fd == -1)
        return (NULL);
    ptr = get_read(ptr, fd);
	if (!ptr)
		return (NULL);
	if (*ptr == '\n')
	{
		i = ft_check(ptr + 1, '\n');
		str = ft_substr(ptr + 1, 0, i);
	}
	else
	{	
		i = ft_check(ptr, '\n');
		str = ft_substr(ptr, 0, i);
	}
	tmp = ft_cutstring(ptr, i);
	free(ptr);
	ptr = tmp;
	return (str);
}

// int main()
// {
//     int fd = open("test", O_RDONLY);
// 	if (fd < 0)
// 		return (0);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
	
// }