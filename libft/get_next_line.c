/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:30:06 by amusakha          #+#    #+#             */
/*   Updated: 2023/10/08 15:27:08 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_read(int fd, long len, char *str)
{
	char	buf[BUFFER_SIZE + 1];


	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		if (len == -1)
			return (0);
		if (!str)
			str = ft_strdup_gnl(buf);
		else
			str = ft_strjoin_gnl(str, buf);
		if (ft_strchr_gnl(str, '\n') || len == 0)
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*all;
	char		*line;
	char		*left;
	long		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	len = 1;
	if (len == 0)
		return (0);
	all = ft_read(fd, len, all);
	if (!all)
		return (0);
	len = ft_strlen_gnl(all) - ft_strlen_gnl(ft_strchr_gnl(all, '\n')) + 1;
	line = ft_substr_gnl(all, 0, len);
	left = all;
	all = ft_substr_gnl(all, len, ft_strlen_gnl(all));
	free(left);
	return (line);
}
