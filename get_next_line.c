/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:51:10 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/23 11:58:06 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_check(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char *get_read(char *ptr, int fd)
{
	int i;
	char *str;
	
	i = 0;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	str[0] = 0;
	while (ft_check(str, '\n') == -1)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0 || i == 0)
		{
			free(ptr);
			free(str);
			return (NULL);
		}
		str[i] = 0;
		ptr = ft_strjoin(ptr, str);
		if (ft_strlen(str) > BUFFER_SIZE)
			break;
	}
	free (str);
	return (ptr);
}
char *ft_strlcpy(char *dst, char *src, int len)
{
	int i;

	i = 0;
	while (*src && i < len)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\n';
	dst[i + 1] = 0;
	return (dst);
}
char *ft_line(char *ptr, int f)
{
	int i;
	char *str;
	
	// printf("all ptr is :%s\n", ptr);
	i = ft_check(ptr + f, '\n');
	// printf("%d\n", i);
	str = malloc(sizeof(char) * (2 + i));
	if (!str)
	return (NULL);
	str
	
}

char	*get_next_line(int fd)
{
	static char *ptr;
	static int f;
	
	if (fd < 0)
		return (NULL);
	ptr = get_read(ptr, fd);
	return (ft_line(ptr , f));
}

int main()
{
	int fd = open("test" ,O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));÷
	//get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
}