/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrahim <aerrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:06:13 by aerrahim          #+#    #+#             */
/*   Updated: 2023/04/10 00:45:01 by aerrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 24
#endif
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strchr(char *str, char c);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *dup);
void *ft_memcpy(void *dst, const void *src, size_t n);
size_t ft_strlen(char *str);
char *get_next_line(int fd);

#endif
