/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:43:17 by yobenali          #+#    #+#             */
/*   Updated: 2021/11/29 02:16:14 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize > 0)
	{
		while (++i < dstsize - 1 && src[i])
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	tab = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	if (!tab)
		return (NULL);
	while (i++ < ft_strlen(s1))
		tab[i] = s1[i];
	while (j < ft_strlen(s2))
		tab[i + j] = s2[j];
	free((void *)s1);
	return (tab);
}
