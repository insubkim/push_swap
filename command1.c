/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 10:54:50 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_deque *a)
{
	push_bottom(a, pop(a));
	write(1, "r", 1);
	write(1, a -> name, 1);
	write(1, "\n", 1);
}

void	rotate_both(t_deque *a, t_deque *b)
{
	push_bottom(a, pop(a));
	push_bottom(b, pop(b));
	write(1, "rr\n", 3);
}

void	r_rotate(t_deque *a)
{
	push(a, pop_bottom(a));
	write(1, "rr", 2);
	write(1, a -> name, 1);
	write(1, "\n", 1);
}

void	r_rotate_both(t_deque *a, t_deque *b)
{
	push(a, pop_bottom(a));
	push(b, pop_bottom(b));
	write(1, "rrr\n", 4);
}
