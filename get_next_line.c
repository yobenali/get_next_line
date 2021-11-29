/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:42:19 by yobenali          #+#    #+#             */
/*   Updated: 2021/11/29 08:25:48 by yobenali         ###   ########.fr       */
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

char	*nextstr(char *saved, char *line)
{
	char 	*new;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(line);
	while (saved[i])
	{
		new[j] = saved[i];
		j++;	
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char *saved;
	char *line;
	char *buf;
	char *tmp;
	size_t len;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 1;
	while (!ft_strchr(saved, '\n') && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		saved = ft_strjoin(saved, buf);
	}
	line = strline(saved);
	if (!line)
		return (NULL);
	saved = nextstr(saved, line);
	tmp = line;
	free(line);
	return (tmp);
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
	read(fd, buf, 20);
	printf("buf: %s", buf);
	return (0);
}
