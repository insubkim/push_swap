/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 14:43:11 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_deque_sorted(t_deque *a)
{
	t_list	*node;
	int		prev;

	node = a -> top;
	prev = INT_MIN;
	while (node)
	{
		if (prev > node -> val)
			return (0);
		prev = node -> val;
		node = node -> next;
	}
	return (1);
}

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	has_command(char *s)
{
	char	**arr;
	int		i;

	arr = ft_split("pa\n pb\n sa\n sb\n ss\n \
			ra\n rb\n rr\n rra\n rrb\n rrr\n", " ");
	i = 0;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], s))
		{
			free_tmp(arr);
			return ;
		}
		i++;
	}
	print_error();
}

void	check_a_b(t_deque *a, t_deque *b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		has_command(s);
		execute(a, b, s);
		free(s);
		s = get_next_line(0);
	}
	if (b -> size == 0 && is_deque_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		*args;
	int		size;
	t_deque	*a;
	t_deque	*b;

	args = ft_atoi_s(parse_arg(--argc, ++argv), &size);
	check_dup(args, size);
	a = make_deque("a", args, size);
	b = make_deque("b", (int *)0, 0);
	check_a_b(a, b);
	free_deque(a);
	free_deque(b);
	free(args);
	return (0);
}
