/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/06 13:33:41 by inskim           ###   ########.fr       */
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
}