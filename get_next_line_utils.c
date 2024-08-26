/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:06:30 by aerrahim          #+#    #+#             */
/*   Updated: 2023/04/09 21:06:32 by aerrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strchr(char *str, char c)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] && str[i] == c)
		return (i + 1);
	return (0);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t l;

	l = n;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	while ((int)n-- > 0)
		*(char *)(dst++) = *(const char *)(src++);
	return (dst - l);
}

char *ft_strdup(char *dup)
{
	char *str;
	size_t i;

	i = ft_strlen(dup);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, dup, i);
	str[i] = '\0';
	return (str);
}
