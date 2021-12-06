/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:34:39 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:45:34 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str2;
	size_t	i;
	size_t	j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str2 = malloc(len + 1);
	if (!str2)
		return (NULL);
	while (s1[i])
	{
		str2[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str2[i + j] = s2[j];
		j++;
	}
	str2[len] = '\0';
	return (str2);
}

char	*ft_strdup(const char *source)
{
	char	*str;
	int		len;

	len = ft_strlen((char *)source);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = source[len];
	return (str);
}

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c && c[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)src);
	if (dst_size == 0)
		return (len);
	while (src[i] != '\0' && i < (dst_size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_size;

	str_size = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (s[start + str_size])
		str_size++;
	if (len < str_size)
		str_size = len;
	str = malloc((str_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, str_size + 1);
	return (str);
}
