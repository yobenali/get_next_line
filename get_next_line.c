/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:42:19 by yobenali          #+#    #+#             */
/*   Updated: 2021/12/04 03:11:26 by yobenali         ###   ########.fr       */
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
	if (!str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
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

	i = 0;
	if (!*saved)
		return (NULL);
	while (saved[0][size] && saved[0][size] != '\n')
		size++;
	new = (char *)ft_calloc((ft_strlen(*saved) - size + 1), sizeof(char));
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

char	*read_join(char *saved, char *buf, int len, int fd)
{
	while (len > 0 && !ft_strchr(saved, '\n'))
    {
        len = read(fd, buf, BUFFER_SIZE);
    	if (len < 0)
    	{
        	free(saved);
        	saved = NULL;
        	return (NULL);
    	}
    	buf[len] = '\0';
    	saved = ft_strjoin(&saved, buf);
    }
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*line;
	char 		buf[BUFFER_SIZE + 1];
	int 		len;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 1;
	if (!saved)
		saved = ft_strdup("");
	saved = read_join(saved, buf, len, fd);
	line = strline(saved);
	saved = to_save(&saved, 0);
	if (line && ft_strlen(line) == 0)
	{
		free(line);
		line = NULL;
		free(saved);
		saved = NULL;
	}
	return (line);
}

/*int	main(void)
{
	for (int i = 0; i < 16; i++)
		printf("%s", get_next_line(10));
	return (0);
}*/

