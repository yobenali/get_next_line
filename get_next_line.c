/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:42:19 by yobenali          #+#    #+#             */
/*   Updated: 2021/11/29 03:12:59 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*get_next_line(int fd)
{
	static char *saved;
	char *line;
	char *buf;
	size_t len;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(saved, '\n') && !line)
	{
		len = read(fd, buf, BUFFER_SIZE);
		saved = ft_strlcpy(saved, buf, BUFFER_SIZE);
	}
}
