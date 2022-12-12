/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:43:57 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_push(t_deque *from, t_deque *to)
{
	t_list	*node;

	node = pop(from);
	push(to, node);
	write(1, "p", 1);
	write(1, to -> name, 1);
	write(1, "\n", 1);
}

void	swap(t_deque *a)
{
	t_list	*first;
	t_list	*second;

	first = pop(a);
	second = pop(a);
	push(a, first);
	push(a, second);
	write(1, "s", 1);
	write(1, a -> name, 1);
	write(1, "\n", 1);
}

void	swap_both(t_deque *a, t_deque *b)
{
	t_list	*first;
	t_list	*second;

	first = pop(a);
	second = pop(a);
	push(a, first);
	push(a, second);
	first = pop(b);
	second = pop(b);
	push(b, first);
	push(b, second);
	write(1, "ss\n", 3);
}

void	pop_chunk(t_deque *from, t_deque *to, int size)
{
	while (size-- > 0)
		pop_push(from, to);
}
