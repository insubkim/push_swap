/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/08 08:16:32 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pop_push(t_deque *from, t_deque *to)
{
    t_list  *node;

    node = pop(from);
    if (!node)
        print_error();
    push(to, node);
    write(1, "p", 1);
    write(1, from -> name, 1);
    write(1, "\n", 1);
}

void    swap(t_deque *a)
{
    t_list  *first;
    t_list  *second;

    first = pop(a);
    second = pop(a);
    if (!first || !second)
        print_error();
    push(a, first);
    push(a, second);
    write(1, "s", 1);
    write(1, a -> name, 1);
    write(1, "\n", 1);
}

void    rotate(t_deque *a)
{
    push_bottom(a, pop(a));
    write(1, "r", 1);
    write(1, a -> name, 1);
    write(1, "\n", 1);
}

void    r_rotate(t_deque *a)
{
    push(a, pop_bottom(a));
    write(1, "rr", 2);
    write(1, a -> name, 1);
    write(1, "\n", 1);
}

void    pa_center(t_deque *a, t_deque *b, int i)
{
    int j;

    j = 1;
    while (j++ < i)
        rotate(a);
    pop_push(a, b);
    while (--j > 1)
        r_rotate(a);
}