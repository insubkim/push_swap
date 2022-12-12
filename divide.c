/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:49 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:09:38 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_two(t_deque *a, t_deque *b, int order)
{
	int	first;
	int	second;

	first = peek(a);
	second = a -> top -> next -> val;
	if ((order == 1 && first < second) || (order == -1 && first > second))
		swap(a);
	pop_push(a, b);
	pop_push(a, b);
}

int	get_index_by_order(t_deque *a, int val, int order, int size)
{
	int		i;
	int		j;
	t_list	*node;

	i = 0;
	j = 0;
	node = a -> top;
	while (j++ < size)
	{
		if (val > node -> val)
			i++;
		node = node -> next;
	}
	if (order == 1)
		i = size - 1 - i;
	return (i);
}

char	*set_temp_arr(t_deque *a, char *arr, int order, int size)
{
	t_list	*node;
	int		i;

	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		print_error();
	arr[size] = 0;
	i = 0;
	node = a -> top;
	while (i < size)
	{
		arr[i++] = 'a' + get_index_by_order(a, node -> val, order, size);
		node = node -> next;
	}
	return (arr);
}

void	a_to_b(t_deque *a, t_deque *b, int div_size, int order)
{
	if (div_size == 1)
		pop_push(a, b);
	else if (div_size == 2)
		move_stack_two(a, b, order);
	else if (div_size == 3)
		move_stack_three(a, b, order);
	else if (div_size == 4)
		move_stack_four(a, b, order);
	else if (div_size == 5)
		move_stack_five(a, b, order);
	else
		print_error();
}

void	divide(t_deque *a, t_deque *b, t_model *model)
{
	int	i;

	i = model -> div_count;
	while (--i >= 0)
		a_to_b(a, b, (model -> div_arr)[i], (model -> div_arr_order)[i]);
}
