/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:11:42 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(int *args, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (args[i] > args[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*args;
	int		size;
	t_deque	*a;
	t_deque	*b;

	args = ft_atoi_s(parse_arg(--argc, ++argv), &size);
	check_dup(args, size);
	if (is_sort(args, size))
		return (0);
	a = make_deque("a", args, size);
	b = make_deque("b", (int *)0, 0);
	push_swap(a, b);
	free_deque(a);
	free_deque(b);
	free(args);
	return (0);
}
