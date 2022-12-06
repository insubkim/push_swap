/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/06 15:30:42 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *pop(t_deque *deque)
{
    t_list *node;

    if (!deque || !(deque -> top))
        print_error();
    node = deque -> top;
    if (deque -> top -> next)
        deque -> top =  deque -> top -> next;
    (deque -> size)--;
    return (node);
}

void    push(t_deque *deque, t_list *node)
{
    if (!deque || !node)
        print_error();
    node -> next = deque -> top;
    if (deque -> top)
        deque -> top -> back = node;
    deque -> top = node;
    if (deque -> bottom == 0)
        deque -> bottom = node;
    (deque -> size)++;
}

int peek(t_deque *deque)
{
    if (!deque || !(deque -> top))
        print_error();
    return (deque -> top -> val);
}

int peek_bottom(t_deque *deque)
{
    if (!deque || !(deque -> bottom))
        print_error();
    return (deque -> bottom -> val);
}

t_deque *make_deque_b(void)
{
    t_deque *b;

    b = (t_deque *)malloc(sizeof(t_deque));
    if (!b)
        print_error();
    b -> size = 0;
    b -> top = 0;
    b -> bottom = 0;
    return (b);
}

void    add_front_deque(t_deque *a, int val)
{
    t_list  *node;
    
    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        print_error();
    node -> val = val;
    node -> back = 0;
    node -> next = a -> top;
    a -> top = node;
    if (a -> bottom == 0)
        a -> bottom = node;
    (a -> size)++;
}

t_deque *make_deque_a(int   *args, int size)
{
    t_deque *a;

    a = (t_deque *)malloc(sizeof(t_deque));
    if (!a)
        print_error();
    a -> size = 0;
    a -> top = 0;
    a -> bottom = 0;
    while (size-- > 0)
        add_front_deque(a, args[size]);
    return (a);
}