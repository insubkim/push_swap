/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/07 23:15:10 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pop_chunk(t_deque *from, t_deque *to, int size)
{
    while (size-- > 0)
        push(to, pop(from));
}

void    match_model(t_deque *from, t_deque *to, t_model *match, int i)
{
    int val;
    int flag;

    if (match -> div_arr[i - 1])
    {
        flag = 0;
        val = peek_bottom(to);
    }
    if (match -> div_arr[i])
    {
        if (match -> div_arr_order[i] * -1 == 1)
        {
            if (val < peek(from))
            {
                flag = 1;
                val = peek(from);
            }
        }
        else
        {
            if (val > peek(from))
            {
                flag = 1;
                val = peek(from);
            }
        }
    }
    if (match -> div_arr[match -> div_count - i / 2])
    {
        if (match -> div_arr_order[i] * -1 == 1)
        {
            if (val < peek_bottom(from))
            {
                flag = 2;
                val = peek_bottom(from);
            }
        }
        else
        {
            if (val > peek(from))
            {
                flag = 2;
                val = peek_bottom(from);
            }
        }
    }
    if (flag == 0)
    {
        (match ->div_arr[i - 1])--;
        // ra 
    }
    else if (flag == 1)
    {
        (match ->div_arr[i])--;
        // pb
    }
    else if (flag == 2)
    {
        (match ->div_arr[match -> div_count - i / 2])--;
        // rrb pb
    }

}

void    conquer(t_deque *a, t_deque *b, t_model *model)
{
    t_model *match;
    int     i;
    int     j;
    int     flag;

    match = model -> prev;
    //pop [0] from -> to
    //cmp [0] [1] [2] and pop
    

    //until div_count
    i = 0;
    j = 0;
    if (a -> size)
        flag = 0;
    else
        flag = 1;
    while (j < match -> div_count)
    {
        if (flag)
        {
            pop_chunk(a, b, (match -> div_arr)[i++]);
            match_model(a, b, match, i++);
        }
        else
        {
            pop_chunk(b, a, (match -> div_arr)[i++]);
            match_model(b, a, match, i++);
        }
        j = j + 3;
    }
}