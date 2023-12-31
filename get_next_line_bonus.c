/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:46:21 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/25 10:15:46 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_read(char *ptr, int fd)
{
	int		i;
	char	*str;

	i = 1;
	
	str = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!str)
		return (NULL);
	str[0] = 0;
	while (ft_check(str, '\n') == -1 && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			free(ptr);
			return (NULL);
		}
		str[i] = 0;
		ptr = ft_strjoin(ptr, str);
	}
	free(str);
	return (ptr);
}

char	*ft_cut(char *ptr)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
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

char	*ft_free(char *str, char *ptr)
{
	if (*str == 0)
	{
		free(str);
		free(ptr);
		return (NULL);
	}
	return (str);
}

char	*ft_line(char *ptr)
{
	int		i;
	char	*str;

	i = 0;
	if (!ptr)
		return (NULL);
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (i == 0 && !ptr[0])
		return (NULL);
	if (ptr[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
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
	static char	*ptr[1024];
	char		*str;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
		
	ptr[fd] = get_read(ptr[fd], fd);
	str = ft_line(ptr[fd]);
	ptr[fd] = ft_cut(ptr[fd]);
	return (str);
}

// int main()
// {
// 	int fd = open("vaa", O_RDONLY);
// 	char *str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 		printf("%s", str);

// }
