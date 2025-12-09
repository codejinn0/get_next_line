/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:37:59 by aantari           #+#    #+#             */
/*   Updated: 2025/12/09 16:36:42 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_strjoin(char *rest, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!rest && !buffer)
		return (NULL);
	if (!rest)
		return (ft_strdup(buffer));
	if (!buffer)
		return (ft_strdup(rest));
	str = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(rest) + 1));
	if (!str)
		return (NULL);
	while (rest[i])
	{
		str[i] = rest[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	return (str);
}
char	*ft_strchr(char *rest, int c)
{
	size_t	i;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i])
	{
		if (rest[i] == (char)c)
			return (rest + i);
		i++;
	}
	if ((char)c == '\0')
		return (rest + i);
	return (NULL);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

