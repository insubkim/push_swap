/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/08 08:06:39 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    merge_sort(t_deque *a, t_deque *b)
{
    t_model    *model;
    
    model = find_model(a -> size);
    //divide
    model = get_last_node(model);
    divide(a, b, model);
    //conquer
    //apply stack b|a into model's next node
     //model -> prev;
     while (model -> prev)
     {
         conquer(a, b, model);
         model = model -> prev;
     }    
}