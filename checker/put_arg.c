/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/11/29 18:46:23 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    add_front(t_deque *deque, int value)
{
    t_list  *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        print_error();
    node -> content = (void *)value;
    if (deque -> front == 0)
    {
        deque -> rear = node;
        node -> next = 0;
    }
    else
    {
        deque -> front -> back = node;
        node -> next = deque -> front;
    }
    node -> back = 0;
    deque -> front = node;
}

t_deque   *put_arg(int *args, int size)
{
    t_deque   *deque;
    
    deque = (t_deque *)malloc(sizeof(t_deque));
    if (!deque)
        print_error();
    deque -> front = 0;
    deque -> rear = 0;
    while (size-- > 0)
        add_front(deque, args[size]);    
    return (deque);
}