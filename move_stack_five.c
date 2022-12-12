/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:49 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:13:13 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_five2(t_deque *a, t_deque *b, char *arr)
{
	if (arr[0] == 'b')
		execute(a, b, "pb sa pb sb");
	else if (arr[1] == 'b')
		execute(a, b, "sa pb sa pb sb");
	else if (arr[3] == 'b')
		execute(a, b, "pb rr pb pb rrr pa");
	else if (arr[4] == 'b')
		execute(a, b, "pb rr pb sa pb rrr pa");
}

void	move_stack_five3(t_deque *a, t_deque *b, char *arr)
{
	if (arr[0] == 'b')
		execute(a, b, "pb rr sa pb rrr");
	else if (arr[1] == 'b')
		execute(a, b, "sa pb rr sa pb rrr");
	else if (arr[2] == 'b')
		execute(a, b, "pb rr sa pb pb rrr pa");
	else if (arr[4] == 'b')
		execute(a, b, "pb rr sa pb sa pb rrr pa");
}

void	move_stack_five4(t_deque *a, t_deque *b, char *arr)
{
	if (arr[0] == 'b')
		execute(a, b, "pb rr ra sa pb rrr rra");
	else if (arr[1] == 'b')
		execute(a, b, "sa pb rr ra sa pb rrr rra");
	else if (arr[2] == 'b')
		execute(a, b, "ra sa pb rr sa pb rrr rra");
	else if (arr[3] == 'b')
		execute(a, b, "ra pb rr sa pb pb rrr rra pa");
}

void	move_stack_five(t_deque *a, t_deque *b, int order)
{
	char	*arr;

	arr = set_temp_arr(a, order, 5);
	if (arr[0] == 'a')
	{
		execute(a, b, "pb");
		move_stack_four(a, b, order);
	}
	else if (arr[1] == 'a')
	{
		execute(a, b, "sa pb");
		move_stack_four(a, b, order);
	}
	else
	{
		if (arr[2] == 'a')
			move_stack_five2(a, b, arr);
		else if (arr[3] == 'a')
			move_stack_five3(a, b, arr);
		else if (arr[4] == 'a')
			move_stack_five4(a, b, arr);
		move_stack_three(a, b, order);
	}
}
