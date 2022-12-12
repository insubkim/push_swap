/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:45:22 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_div_arr(t_model *node, t_model *new_node)
{
	int	i;
	int	j;

	new_node -> div_arr = (int *)malloc(sizeof(int) * new_node -> div_count);
	new_node -> div_arr_order = \
	(int *)malloc(sizeof(int) * new_node -> div_count);
	if (new_node -> div_arr == 0 || new_node -> div_arr_order == 0)
		print_error();
	i = 0;
	j = node -> div_count - 1;
	while (i < node -> div_count)
	{
		(new_node -> div_arr)[i] = (node -> div_arr)[j - i] / 3;
		(new_node -> div_arr_order)[i] = (node -> div_arr_order)[j - i] * -1;
		(new_node -> div_arr)[i + j + 1] = (node -> div_arr)[j - i] / 3 + \
		(node -> div_arr)[j - i] % 3;
		(new_node -> div_arr_order)[i + j + 1] = \
		(node -> div_arr_order)[j - i] * -1;
		(new_node -> div_arr)[new_node -> div_count - 1 - i] = \
		(node -> div_arr)[j - i] / 3;
		(new_node -> div_arr_order)[new_node -> div_count - 1 - i] = \
		(node -> div_arr_order)[j - i];
		i++;
	}
}

void	find_next_model(t_model *node, int size)
{
	t_model	*new_node;

	new_node = (t_model *)malloc(sizeof(t_model));
	if (!new_node)
		print_error();
	node -> next = new_node;
	new_node -> prev = node;
	new_node -> next = 0;
	new_node -> div_count = node -> div_count * 3;
	set_div_arr(node, new_node);
}

t_model	*get_last_model(t_model *model)
{
	while (model -> next)
		model = model -> next;
	return (model);
}

t_model	*find_model(int size)
{
	t_model	*model;

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
		find_next_model(get_last_model(model), size);
		size = size / 3 + size % 3;
	}
	return (model);
}
