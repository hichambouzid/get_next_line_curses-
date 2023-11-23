/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:51:10 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/23 21:24:28 by hibouzid         ###   ########.fr       */
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
			free(str);
			if (!ptr)
				return (ptr);
			return (ptr);
		}
		str[i] = 0;
		ptr = ft_strjoin(ptr, str);
		if (ft_strlen(str) < BUFFER_SIZE || !ptr)
			break;
	}
	free (str);
	return (ptr);
}

char *ft_line(char *ptr, int *f)
{
	int i;
	char *str;
	int j;
	
	j = 0;
	i = *f;
	while (ptr[i] != '\0')
	{
		i++;
		if (ptr[i] == '\n')
		break;
	}
	if (i == *f)
	{
		free(ptr);
		return (NULL);
	}
	str = malloc(sizeof(char) * (2 + i - *f));
	while (*f <= i)
	{
		str[j] = ptr[*f];
		j++;
		*f += 1;
	}
	str[j] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static char *ptr;
	static int f;
	char *str;

	str = NULL;
	if (fd == -1)
		return (NULL);
	ptr = get_read(ptr, fd);
	if (ptr)
		str = ft_line(ptr, &f);
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
// int main(int ac, char **av){
// 	int fd = open(av[1] ,O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while(line){
// 		printf("%s",line);
// 		line = get_next_line(fd);
// 	}
// 	return 0;
// }