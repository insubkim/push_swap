/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:34:25 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest(int arr[][2])
{
	int	big;

	if (arr[0][1])
		big = arr[0][0];
	else if (arr[1][1])
		big = arr[1][0];
	else if (arr[2][1])
		big = arr[2][0];
	if (arr[0][1] && big < arr[0][0])
		big = arr[0][0];
	if (arr[1][1] && big < arr[1][0])
		big = arr[1][0];
	if (arr[2][1] && big < arr[2][0])
		big = arr[2][0];
	if (arr[0][1] && big == arr[0][0])
		return (1);
	if (arr[1][1] && big == arr[1][0])
		return (2);
	return (3);
}

int	get_smallest(int arr[][2])
{
	int	small;

	if (arr[0][1])
		small = arr[0][0];
	else if (arr[1][1])
		small = arr[1][0];
	else if (arr[2][1])
		small = arr[2][0];
	if (arr[0][1] && small > arr[0][0])
		small = arr[0][0];
	if (arr[1][1] && small > arr[1][0])
		small = arr[1][0];
	if (arr[2][1] && small > arr[2][0])
		small = arr[2][0];
	if (arr[0][0] && small == arr[0][0])
		return (1);
	if (arr[1][1] && small == arr[1][0])
		return (2);
	return (3);
}

int	get_next(t_deque *from, t_deque *to, t_model *model, int i)
{
	int	arr[3][2];

	arr[0][1] = 1;
	arr[1][1] = 1;
	arr[2][1] = 1;
	if (model -> div_arr [i])
		arr[0][0] = peek_bottom(to);
	else
		arr[0][1] = 0;
	if (model -> div_arr [model -> div_count / 3 + i])
		arr[1][0] = peek(from);
	else
		arr[1][1] = 0;
	if (model -> div_arr [model -> div_count - 1 - i])
		arr[2][0] = peek_bottom(from);
	else
		arr[2][1] = 0;
	if (model -> div_arr_order[i] * -1 == 1)
		return (get_biggest(arr));
	else
		return (get_smallest(arr));
}

void	match_model(t_deque *from, t_deque *to, t_model *model, int i)
{
	int	next;

	while (model -> div_arr[i] || model -> div_arr[model -> div_count / 3 + i] \
			|| model -> div_arr[model -> div_count - 1 - i])
	{
		next = get_next(from, to, model, i);
		if (next == 1)
		{
			(model ->div_arr[i])--;
			r_rotate(to);
		}
		else if (next == 2)
		{
			(model ->div_arr[model -> div_count / 3 + i])--;
			pop_push(from, to);
		}
		else
		{
			(model ->div_arr[model -> div_count - 1 - i])--;
			r_rotate(from);
			pop_push(from, to);
		}
	}
}

void	conquer(t_deque *a, t_deque *b, t_model *model)
{
	int			i;
	t_deque		*tmp;

	if (!(a -> size))
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	i = 0;
	while (i < (model -> div_count) / 3)
		pop_chunk(a, b, model -> div_arr[i++]);
	i = 0;
	while (i < (model -> div_count) / 3)
		match_model(a, b, model, i++);
}
