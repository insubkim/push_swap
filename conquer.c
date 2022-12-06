/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/06 15:43:00 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    conquer(t_deque *a, t_deque *b, t_model *model)
{
    t_model *next;
    int     i;
    int     flag;

    next = model -> next;
    //pop [0] from -> to
    //cmp [0] [1] [2] and pop
    

    //until div_count
    i = 0;
    if (a -> size)
        flag = 0;
    else
        flag = 1;
    while (i < next -> div_count)
    {
        pop_chunk(a, b, flag, next -> )
        i++;
    }
}