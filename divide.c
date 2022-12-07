/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:49 by inskim            #+#    #+#             */
/*   Updated: 2022/12/07 22:24:24 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_stack_two(t_deque *a, t_deque *b, int order)
{
    int first;
    int second;
    
    first = peek(a);
    second = a -> top -> next -> val;
    if ((order == 1 && first < second) || (order == -1 && first > second))
        sa(a);
    pa(a, b);
    pa(a, b);
}

void    set_temp_arr(t_deque *a, int order, int *arr, int len)
{
    int     i;
    t_list  *node;

    i = 0;
    node = a -> top;
    if (order == -1)
    {
        while (i < len)
        {
            arr[i++] = node -> val;
            node = node -> next;
        }
    }
    else
    {
        while (0 <= --len)
        {
            arr[len] = node -> val;
            node = node -> next;    
        }   
    }
}

// void    move_stack_three(t_deque *a, t_deque *b, int order)
// {
//     int arr[3];
    
//     set_temp_arr(a, order, arr, 3);
//     if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
//     {
//         pa(a, b);
//         sa(a);
//     }
//     else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
//         sa(a); 
//     else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
//         ra(a); 
//     else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
//         ra(a); 
//     else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
//     {
//         sa(a);
//         rra(a);
//     }     
//     pa(a, b);
//     pa(a, b);
//     if (!(arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2]))
//         pa(a, b);
// }

void    move_stack_three(t_deque *a, t_deque *b, int order)
{
    int arr[3];

    set_temp_arr(a, order, arr, 3);
    if (arr[0] < arr[1] && arr[0] < arr[2])
    {
        pa(a, b);
        move_stack_two(a, b, order);
    }
    if (arr[0] > arr[1] && arr[1] < arr[2])
    {
        sa(a);
        move_stack_two(a, b, order);
    }    
    if (arr[0] > arr[2] && arr[1] > arr[2])
    {
        pa(a, b);
        sa(a);
        pa(a, b);
        sb(b);
        pa(a, b);
        if (arr[0] > arr[2])
            sb(b);
    }
}

void    move_stack_four(t_deque *a, t_deque *b, int order)
{
    int arr[4];
    
    set_temp_arr(a, order, arr, 4);
    if (arr[0] < arr[1] && arr[0] < arr[1] && arr[0] < arr[2] && arr[0] < arr[3])
        pa(a, b);
    else if (arr[0] < arr[1] && arr[1] < arr[2] && arr[1] < arr[3])
    {
        sa(a);
        pa(a, b);
    } 
    else if (arr[0] < arr[2] && arr[1] < arr[2] && arr[2] < arr[3])
        pa_center(a, b, 3); 
    else
        pa_center(a, b, 4);        
    move_stack_three(a, b, order); 
}

void    move_stack_five(t_deque *a, t_deque *b, int order)
{
    int arr[5];

    set_temp_arr(a, order, arr, 5);
    if (arr[0] < arr[1] && arr[0] < arr[2] && arr[0] < arr[3] && arr[0] < arr[4])
        pa(a, b);
    else if (arr[0] < arr[1] && arr[1] < arr[2] && arr[1] < arr[3] && arr[1] < arr[4])
    {
        sa(a);
        pa(a, b);
    } 
    else if (arr[0] < arr[2] && arr[1] < arr[2] && arr[2] < arr[3] && arr[2] < arr[4])
        pa_center(a, b, 3); 
    else if (arr[0] < arr[3] && arr[1] < arr[3] && arr[2] < arr[3] && arr[3] < arr[4])
        pa_center(a, b, 4); 
    else
        pa_center(a, b, 5);        
    move_stack_four(a, b, order); 
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
    else if (div_size == 5)
        move_stack_five(a, b, order);
    else
        print_error();
}

void    divide(t_deque *a, t_deque *b, t_model *model)
{
    int i;

    i = model -> div_count;
    while (--i >= 0)
        a_to_b(a, b, (model -> div_arr)[i], (model -> div_arr_order)[i]);
}
