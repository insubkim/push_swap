/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/05 14:49:54 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_div_arr(t_model *node, t_model *new_node)
{
    int i;
    int j;
    int k;
    
    new_node -> div_arr = (int *)malloc(sizeof(int) * new_node -> div_count);
    new_node -> div_arr_order = (int *)malloc(sizeof(int) * new_node -> div_count);
    if (new_node -> div_arr == 0 || new_node -> div_arr_order == 0)
        print_error();
    i = node -> div_count;
    j = 0;
    k = new_node -> div_count;
    while (--i >= 0)
    {
        (new_node -> div_arr)[j] = (node -> div_arr)[i] / 3;
        (new_node -> div_arr_order)[j++] = (node -> div_arr_order)[i] * -1;
        (new_node -> div_arr)[j] = (node -> div_arr)[i] / 3 + (node -> div_arr)[i] % 3;
        (new_node -> div_arr_order)[j++] = (node -> div_arr_order)[i] * -1;
        (new_node -> div_arr)[--k] = (node -> div_arr)[i] / 3;
        (new_node -> div_arr_order)[k] = (node -> div_arr_order)[i];
    }
}

void find_next_model(t_model *node, int size)
{
    t_model *new_node;

    new_node = (t_model *)malloc(sizeof(t_model));
    if (!new_node)
        print_error();
    node -> next = new_node;
    new_node -> prev = node;
    new_node -> next = 0;
    new_node -> div_count = node -> div_count * 3;
    set_div_arr(node, new_node);
}

t_model *get_last_node(t_model *model)
{
    while (model -> next)
        model = model -> next;
    return (model);
}

t_model *find_model(int size)
{
    t_model *model;

    model = (t_model *)malloc(sizeof(t_model));
    if (!model)
        print_error();
    model -> div_arr = (int *)malloc(sizeof(int));
    if (model -> div_arr == 0)
        print_error();
    model -> div_arr_order = (int *)malloc(sizeof(int));
    if (model -> div_arr_order == 0)
        print_error();
    *(model -> div_arr) = size; 
    model -> div_count = 1;
    *(model -> div_arr_order) = 1;
    model -> next = 0;
    model -> prev = 0;
    while (size > 5)
    {
        find_next_model(get_last_node(model), size);
        size = size / 3 + size % 3;
    }
    return (model);
}