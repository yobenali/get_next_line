/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:43:17 by yobenali          #+#    #+#             */
/*   Updated: 2021/12/04 13:32:32 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < len)
		ptr[i] = s1[i];
	return (ptr);
}

char	*ft_strjoin(char **s1, char *s2)
{
	int		i;
	char	*tab;
	int		s2_len;
	int 	s1_len;

	i = -1;
	if (!*s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	tab = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!tab)
		return (NULL);
	while (++i < s1_len)
		tab[i] = s1[0][i];
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	while (--s2_len >= 0)
		tab[i + s2_len] = s2[s2_len];
	return (tab);
}

void    *ft_calloc(int count, int size)
{
    int 	t_count;
	void    *ptr;
	int		i;

    t_count = count * size;
    ptr = malloc(t_count);
    if (!ptr)
        return (NULL);
	i = -1;
    while (++i < t_count)
		((char *)ptr)[i] = 0;
    return (ptr);
}
