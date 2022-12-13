/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:49 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:13:30 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_three(t_deque *a, t_deque *b, int order)
{
	char	*arr;

	arr = set_temp_arr(a, order, 3);
	if (!ft_strncmp(arr, "abc", 3))
		execute(a, b, "pb pb pb");
	else if (!ft_strncmp(arr, "acb", 3))
		execute(a, b, "pb sa pb pb");
	else if (!ft_strncmp(arr, "bac", 3))
		execute(a, b, "sa pb pb pb");
	else if (!ft_strncmp(arr, "bca", 3))
		execute(a, b, "pb sa pb sb pb");
	else if (!ft_strncmp(arr, "cab", 3))
		execute(a, b, "sa pb sa pb pb");
	else if (!ft_strncmp(arr, "cba", 3))
		execute(a, b, "sa pb sa pb sb pb");
	free(arr);
}
