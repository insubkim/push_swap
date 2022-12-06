/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:05:27 by inskim            #+#    #+#             */
/*   Updated: 2022/11/29 17:06:47 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = 0;
		s = s + 1;
		n--;
	}
}

static int	cnt_word(char const *s, char c)
{
	int	i;
	int	flag;

	if (!s)
		return (0);
	i = 0 ;
	flag = 1;
	s--;
	while (*++s)
	{
		if (*s == c)
			flag = 1;
		else if (flag == 1)
		{
			i++;
			flag = 0;
		}
	}
	return (i);
}

static int	alloc(char **arr, char const *s, int i, int j)
{
	int	len;
	int	k;

	len = j - i + 1;
	*arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!*arr)
		return (0);
	(*arr)[len] = 0;
	k = 0;
	while (i <= j)
		(*arr)[k++] = s[i++];
	return (1);
}

static	int	put(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	flag;

	j = -1;
	flag = 1;
	while (s[++j])
	{
		if (s[j] == c)
		{
			if (flag == 0)
				if (!alloc(arr++, s, i, j - 1))
					return (0);
			flag = 1;
		}
		else if (flag == 1)
		{
			i = j;
			flag = 0;
		}
	}
	if (flag == 0)
		print_error();
	return (1);
}

char	**ft_splitx(char const *s, char c)
{
	int		word;
	char	**arr;

	word = cnt_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!arr)
		print_error();
	arr[word] = 0;
	if (s && !put(arr, s, c))
	{
		while (*arr)
			free(*arr++);
		free(arr);
		print_error();
	}
	return (arr);
}

char	*ft_strjoinx_free(char *s1, char const *s2)
{
	int		len;
	char	*p;
	int		i;

	if (!s1 || !s2)
		print_error();
	len = ft_strlen((char const *)s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		print_error();
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	while (*s2)
		p[i++] = *s2++;
	p[i] = 0;
    free(s1);
    s1 = p;
	return (p);
}

int get_int_command(char *c)
{
    if (!c)
        print_error();
    if (c[0] == 'p'&& c[1] == 'a' && c[2] == 0)
            return (1);
    else if (c[0] == 'p'&& c[1] == 'b' && c[2] == 0)
            return (2);
    else if (c[0] == 's'&& c[1] == 'b' && c[2] == 0)
            return (3);
    else if (c[0] == 's'&& c[1] == 'b' && c[2] == 0)
            return (4);
    else if (c[0] == 's'&& c[1] == 's' && c[2] == 0)
            return (5);
    else if (c[0] == 'r'&& c[1] == 'a' && c[2] == 0)
            return (6);
    else if (c[0] == 'r'&& c[1] == 'b' && c[2] == 0)
            return (7);
    else if (c[0] == 'r'&& c[1] == 'r' && c[2] == 0)
            return (8);
    else if (c[0] == 'r'&& c[1] == 'r' && c[2] == 'a' && c[3] == 0)
            return (9);
    else if (c[0] == 'r'&& c[1] == 'r' && c[2] == 'b' && c[3] == 0)
            return (10);
   else if (c[0] == 'r'&& c[1] == 'r' && c[2] == 'r' && c[3] == 0)
            return (11);
   print_error();
   return (0);
}

void    free_char_arr(char **arr)
{
    char    **start;

    start = arr;
    while (*arr)
        free(*arr++);
    free(start);
}

int *atoi_commandx(char **char_commands)
{
    int len;
    int *commands;

    len = 0;
    while (char_commands[len])
        len++;
    commands = (int *)malloc(sizeof(int) * (len + 1));
    if (!commands)
        print_error();
    commands[len] = 0;
    while (--len >= 0)
        commands[len] = get_int_command(char_commands[len]);
    free_char_arr(char_commands);
    return (commands);
}

void	*ft_callocx(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
		print_error();
	if (nmemb > SIZE_MAX / size)
		print_error();
	p = (void *)malloc(nmemb * size);
	if (!p)
		print_error();
	ft_bzero(p, nmemb * size);
	return (p);
}

int *check_stdin(void)
{
    char    *stdin;
    char    **char_commands;
    char    buf[1024];

    ft_bzero((void *)buf, 1024);
    stdin = ft_callocx(1, 1);
    while (read(0, buf, 1023))
    {
        stdin = ft_strjoinx_free(stdin, buf);
        ft_bzero((void *)buf, 1024);
    }
    char_commands = ft_splitx(stdin, '\n');
    free(stdin);
    return (atoi_commandx(char_commands));
}

