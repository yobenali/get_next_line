/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:42:19 by yobenali          #+#    #+#             */
/*   Updated: 2021/11/30 01:09:19 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*strline(char *str)
{
	char	*tab;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	tab = (char *)malloc((i + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (j <= i)
	{
		tab[j] = str[j];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*to_save(char *saved, int size)
{
	char 	*new;
	size_t	i;

	i = 0;
	if (!saved)
		return (NULL);
	while (saved[size] != '\n')
		size++;
	new = (char *)malloc((ft_strlen(saved) - size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	size++;
	while (saved[size + i])
	{
		new[i] = saved[size + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char *saved;
	char *line;
	char buf[BUFFER_SIZE + 1];
	size_t len;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 1;
	while (!ft_strchr(saved, '\n') && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		saved = ft_strjoin(saved, buf);
	}
	line = strline(saved);
	if (!line || !len)
		return (NULL);
	saved = to_save(saved, 0);
	return (line);
}

int	main(void)
{
	int	fd = open("Hated.txt", O_RDONLY);
	char *buf;
	if (fd == -1)
	{
		printf("Nothing turning on");
		exit(1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
