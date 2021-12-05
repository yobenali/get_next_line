/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:42:19 by yobenali          #+#    #+#             */
/*   Updated: 2021/12/04 17:44:07 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char    *free_garbeg(char **saved, char **line)
{
    if (line)
    {
        free(*line);
        *line = NULL;
    }
    free(*saved);
    *saved = NULL;
    return (NULL);
}

char	*strline(char *str)
{
	char	*tab;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!str)
		return (free_garbeg(&str, NULL));
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	tab = (char *)ft_calloc((i + 1), sizeof(char));
	if (!tab)
		return (NULL);
	while (j < i)
	{
		tab[j] = str[j];
		j++;
	}
	return (tab);
}

char	*to_save(char **saved, int size)
{
	char 	*new;
	int		i;
	int		saved_len;

	i = 0;
	saved_len = ft_strlen(*saved);
	if (!*saved)
		return (free_garbeg(saved, NULL));
	while (saved[0][size] && saved[0][size] != '\n')
		size++;
	new = (char *)ft_calloc((saved_len - size + 1), sizeof(char));
	if (!new)
		return (NULL);
	if (saved[0][size])
		size++;
	while (saved[0][size + i])
	{
		new[i] = saved[0][size + i];
		i++;
	}
	free(*saved);
	*saved = NULL;
	return (new);
}

char	*read_join(char **saved, char *buf, int len, int fd)
{
	while (len > 0 && !ft_strchr(*saved, '\n'))
    {
        len = read(fd, buf, BUFFER_SIZE);
        if (len < 0)
        	return (free_garbeg(saved, NULL));
		buf[len] = '\0';
        *saved = ft_strjoin(saved, buf);
    }
	return (*saved);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		*line;
	char 		buf[BUFFER_SIZE + 1];
	int 		len;
	
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	len = 1;
	if (!saved[fd])
		saved[fd] = ft_strdup("");
	saved[fd] = read_join(&saved[fd], buf, len, fd);
	if (!saved[fd])
		return (NULL);
	//system("leaks a.out");
	line = strline(saved[fd]);
	saved[fd] = to_save(&saved[fd], 0);
	if (line && ft_strlen(line) == 0)
		return(free_garbeg(&saved[fd], &line));
	return (line);
}

// int	main(void)
// {
// 	//int fd = open("Hated.txt", O_RDONLY);
// 	//for (int i = 0; i < 13; i++)
// 	printf("%s", get_next_line(10));
// }
