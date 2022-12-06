/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:49 by inskim            #+#    #+#             */
/*   Updated: 2022/12/06 11:26:11 by inskim           ###   ########.fr       */
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

void    move_stack_two(t_deque *a, t_deque *b, int order)
{
    int first;
    int second;
    
    first = peek(a);
    second = a -> top -> next -> val;
    if ((order == 1 && first > second) || (order == -1 && first < second))
        sa(a);
    pa(a, b);
    pa(a, b);
}

void    move_stack_three(t_deque *a, t_deque *b, int order)
{
    int first;
    int second;
    int third;
    
    first = peek(a);
    second = a -> top -> next -> val;
    third = a -> top -> next -> next -> val;
    if (order == 1)
    {
        if (first < second && first < third)
            //pa $(2!)
        if (first > second && first > third)
            //ra $(2!) rra pa
        if (first  > second && first < third && second < third)
            //sa pa pa pa
        if (first  > second && first < third && second > third)
            //rra pa pa pa
            
    }
    else
    {
        if (first > second && first > third)
            //pa $(2!)
        if (first < second && first < third)
            //ra $(2!) rra pa
        if (first  > second && first < third && second < third)
            //sa pa pa pa
        if (first  > second && first < third && second > third)
            //rra pa pa pa
    }
}

void    a_to_b(t_deque *a, t_deque *b, int div_size, int order)
{
    if (div_size == 1)
        pa(a, b);
    else if (div_size == 2)
        move_stack_two(a, b, order);
    else if (div_size == 3)
        move_stack_three(a, b, order);
    else if (div_size ==4)
        move_stack_four(a, b, order);
    else
        print_error();
}

void    divide(t_deque *a, t_deque *b, t_model *model)
{
    int i;

    i = model -> div_count;
    while (--i > 0)
        a_to_b(a, b, (model -> div_arr)[i], (model -> div_arr_order)[i]);
}
