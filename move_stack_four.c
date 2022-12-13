/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:49 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:00:19 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_four2(t_deque *a, t_deque *b, char *arr)
{
	if (!ft_strncmp(arr, "bcad", 4))
		execute(a, b, "pb rr pb rrr pb pb");
	else if (!ft_strncmp(arr, "bdac", 4))
		execute(a, b, "pb rr pb rrr sa pb pb");
	else if (!ft_strncmp(arr, "cbad", 4))
		execute(a, b, "sa pb rr pb rrr pb pb");
	else if (!ft_strncmp(arr, "cdab", 4))
		execute(a, b, "pb rr pb pb rrr pb");
	else if (!ft_strncmp(arr, "dbac", 4))
		execute(a, b, "sa pb rr pb pb rrr sb pb");
	else if (!ft_strncmp(arr, "dcab", 4))
		execute(a, b, "sa pb rr pb pb rrr pb");
}

void	move_stack_four3(t_deque *a, t_deque *b, char *arr)
{
	if (!ft_strncmp(arr, "bcda", 4))
		execute(a, b, "pb sa rr pb pb sb rrr sb pb");
	else if (!ft_strncmp(arr, "bdca", 4))
		execute(a, b, "pb rr pb pb sb rrr sb pb");
	else if (!ft_strncmp(arr, "cbda", 4))
		execute(a, b, "sa pb rr sa pb rrr pb pb");
	else if (!ft_strncmp(arr, "cdba", 4))
		execute(a, b, "pb rr sa pb pb rrr pb");
	else if (!ft_strncmp(arr, "dbca", 4))
		execute(a, b, "sa pb rr pb pb sb rrr sb pb");
	else if (!ft_strncmp(arr, "dcba", 4))
		execute(a, b, "sa pb rr sa pb pb rrr pb");
}

void	move_stack_four(t_deque *a, t_deque *b, int order)
{
	char	*arr;

	arr = set_temp_arr(a, order, 4);
	if (arr[0] == 'a')
	{
		execute(a, b, "pb");
		move_stack_three(a, b, order);
	}
	else if (!ft_strncmp(arr, "bacd", 4))
		execute(a, b, "pb pb sb pb pb");
	else if (!ft_strncmp(arr, "badc", 4))
		execute(a, b, "pb pb ss pb pb");
	else if (!ft_strncmp(arr, "cabd", 4))
		execute(a, b, "pb pb sb pb sb pb");
	else if (!ft_strncmp(arr, "cadb", 4))
		execute(a, b, "pb pb ss pb sb pb");
	else if (!ft_strncmp(arr, "dabc", 4))
		execute(a, b, "pb pb sb pb sb pb sb");
	else if (!ft_strncmp(arr, "dacb", 4))
		execute(a, b, "pb pb ss pb sb pb sb");
	else if (arr[2] == 'a')
		move_stack_four2(a, b, arr);
	else
		move_stack_four3(a, b, arr);
	free(arr);
}
