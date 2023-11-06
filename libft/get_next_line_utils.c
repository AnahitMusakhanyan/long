/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:44:12 by amusakha          #+#    #+#             */
/*   Updated: 2023/10/08 17:17:54 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strdup_gnl(char *s1)
{
	char		*s2;
	int			i;

	if (!s1)
		return (0);
	i = -1;
	s2 = malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!s2)
		return (0);
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == 0 && s[i] == 0)
		return ((char *)(s + i));
	return (0);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	s = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!s)
		return (0);
	while (s1[++i])
	{
		s[j] = s1[i];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		s[j] = s2[i];
		i++;
		j++;
	}
	s[j] = '\0';
	if (s1)
		free(s1);
	return (s);
}

char	*ft_substr_gnl(char *str, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!str || !*str)
		return (0);
	i = ft_strlen_gnl(str);
	j = 0;
	if (start < i)
		j = i - start;
	if (j > len)
		j = len;
	sub = (char *)malloc(sizeof(char) * (j + 1));
	if (!sub)
		return (0);
	i = 0;
	while (i < j && str[start])
	{	
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
