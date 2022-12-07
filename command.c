/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/07 22:03:33 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_deque *a, t_deque *b)
{
    t_list  *node;

    node = pop(a);
    if (!node)
        print_error();
    push(b, node);
    write(1, "pa\n", 3);
}

void    sa(t_deque *a)
{
    t_list  *first;
    t_list  *second;

    first = pop(a);
    second = pop(a);
    if (!first || !second)
        print_error();
    push(a, first);
    push(a, second);
    write(1, "sa\n", 3);
}

void    sb(t_deque *b)
{
    t_list  *first;
    t_list  *second;

    first = pop(b);
    second = pop(b);
    if (!first || !second)
        print_error();
    push(b, first);
    push(b, second);
    write(1, "sb\n", 3);
}

void    ra(t_deque *a)
{
    push_bottom(a, pop(a));
    write(1, "ra\n", 3);
}

void    rra(t_deque *a)
{
    push(a, pop_bottom(a));
    write(1, "rra\n", 4);
}

void    pa_center(t_deque *a, t_deque *b, int i)
{
    int j;

    j = 1;
    while (j++ < i)
        ra(a);
    pa(a, b);
    while (--j > 1)
        rra(a);
}