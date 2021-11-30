/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:43:17 by yobenali          #+#    #+#             */
/*   Updated: 2021/11/30 01:13:34 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

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
	if (*s == (char) c)
		return ((char *) s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		return (ft_strdup(s2));
	/*	s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';*/
	}
	tab = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		tab[i] = s1[i];
		i++;
	}	
	while (j < ft_strlen(s2))
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}
