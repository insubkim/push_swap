/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/05 16:40:12 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    merge_model(t_deque *to, t_deque *from, t_model *model)
{
    t_model *pre_model;
    int     i;

    pre_model = model -> next;
    i = 0;
    while (i < pre_model ->div_count)
    {
        pop_from_to(to, from, (pre_model -> div_arr)[i]);
        
    }
}

void    apply_model(t_deque *to, t_deque *from, t_model *model)
{
    if (model -> next = 0)
        apply_first_model(to, from, model);
    else
        merge_model(to, from, model);
}


void    match_model(t_deque *a, t_deque *b, t_model *model)
{
    while (model -> div_count != 1)
    {
        if (a -> size)
            apply_model(b ,a ,model);
        else
            apply_model(a ,b ,model);
        model = model -> prev;
    }
}