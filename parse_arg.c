/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:13:46 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_tmp_size(char ***tmp)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			size++;
			j++;
		}
		i++;
	}
	return (size);
}

char	*ft_strdupx(char *s)
{
	size_t	len;
	char	*cp;
	size_t	i;

	len = ft_strlen(s);
	cp = (char *)malloc(sizeof(char) * (len + 1));
	if (!cp)
		print_error();
	i = 0;
	while (i < len)
		cp[i++] = *s++;
	cp[i] = 0;
	return (cp);
}

char	**get_arr(char ***tmp, int size)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	arr = (char **)malloc(sizeof(char *) *(size + 1));
	if (!arr)
		print_error();
	arr[size] = 0;
	i = 0;
	k = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			arr[k++] = ft_strdupx(tmp[i][j]);
			j++;
		}
		i++;
	}
	return (arr);
}

char	**parse_arg(int argc, char **argv)
{
	int		i;
	char	***tmp;
	char	**arr;

	if (!argc)
		exit(0);
	tmp = (char ***)malloc(sizeof(char **) * (argc + 1));
	if (!tmp)
		print_error();
	tmp[argc] = 0;
	i = -1;
	while (++i < argc)
		tmp[i] = ft_split(argv[i], " ");
	arr = get_arr(tmp, get_tmp_size(tmp));
	free_arr(tmp);
	return (arr);
}
