/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:51:10 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/24 11:51:14 by hibouzid         ###   ########.fr       */
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
	
	i = 1;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	str[0] = 0;
	while (ft_check(str, '\n') == -1 && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0 )
		{
			free(str);
			free(ptr);
			return (NULL);
		}
		str[i] = 0;
		ptr = ft_strjoin(ptr, str);
	}
	free (str);
	return (ptr);
}

char *ft_cut(char *ptr)
{
	int i;
	char *str;

	i = 0;
	if (!ptr)
		return (NULL);
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	if (!ptr[i])
	{
		free(ptr);
		return (NULL);
	}
	str = ft_strdup(ptr + i);
	free(ptr);
	return (str);
}

char *ft_free(char *str, char *ptr)
{
	if (*str == 0)
	{
		free(str);
		free(ptr);
		return (NULL);
	}
	return (str);
}
char *ft_line(char *ptr)
{
	int i;
	char *str;

	i = 0;
	if (!ptr)
		return (NULL);
	while (ptr[i] && ptr[i] != '\n')
	i++;
	if (i == 0 && !ptr[0])
		return (NULL);
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
	{
		str[i] = ptr[i];
		i++;
	}
	if (ptr[i] != 0)
		str[i++] = '\n';
	str[i] = 0;
	return (ft_free(str, ptr));
}

char	*get_next_line(int fd)
{
	static char *ptr;
	char *str;

	str = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = get_read(ptr, fd);
	str = ft_line(ptr);
	ptr = ft_cut(ptr);
	return (str);
}

// int main()
// {
// 	int fd = open("test" ,O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));÷
// 	//get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// }
int main(int ac, char **av){
	int fd = open(av[1] ,O_RDONLY);
	char *line = get_next_line(fd);
	while(line){
		printf("%s",line);
		line = get_next_line(fd);
	}
	return 0;
}