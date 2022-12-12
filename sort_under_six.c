/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:46:22 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_deque *a, t_deque *b)
{
	if (a -> top -> val > a -> top -> next -> val)
		swap(a);
}

void	sort_three(t_deque *a, t_deque *b)
{
	int	arr[3];

	arr[0] = a -> top -> val;
	arr[1] = a -> top -> next -> val;
	arr[2] = a -> top -> next -> next -> val;
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] > arr[2])
		execute(a, b, "rra sa");
	else if (arr[0] > arr[1] && arr[0] < arr[2] && arr[1] < arr[2])
		execute(a, b, "sa");
	else if (arr[0] < arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
		execute(a, b, "rra");
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		execute(a, b, "ra");
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
		execute(a, b, "sa rra");
}

void	sort_four(t_deque *a, t_deque *b)
{
	int	arr[4];

	arr[0] = a -> top -> val;
	arr[1] = a -> top -> next -> val;
	arr[2] = a -> top -> next -> next -> val;
	arr[3] = a -> top -> next -> next -> next -> val;
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[0] < arr[3])
		execute(a, b, "pb");
	else if (arr[1] < arr[0] && arr[1] < arr[2] && arr[1] < arr[3])
		execute(a, b, "sa pb");
	else if (arr[2] < arr[0] && arr[2] < arr[1] && arr[2] < arr[3])
		execute(a, b, "rra rra pb");
	else if (arr[3] < arr[0] && arr[3] < arr[1] && arr[3] < arr[2])
		execute(a, b, "rra pb");
	sort_three(a, b);
	execute(a, b, "pa");
}

void	sort_five(t_deque *a, t_deque *b)
{
	int	arr[5];

	arr[0] = a -> top -> val;
	arr[1] = a -> top -> next -> val;
	arr[2] = a -> top -> next -> next -> val;
	arr[3] = a -> top -> next -> next -> next -> val;
	arr[4] = a -> top -> next -> next -> next -> next -> val;
	if (arr[0] < arr[1] && arr[0] < arr[2] && \
	arr[0] < arr[3] && arr[0] < arr[4])
		execute(a, b, "pb");
	else if (arr[1] < arr[0] && arr[1] < arr[2] && \
	arr[1] < arr[3] && arr[1] < arr[4])
		execute(a, b, "sa pb");
	else if (arr[2] < arr[0] && arr[2] < arr[1] && \
	arr[2] < arr[3] && arr[2] < arr[4])
		execute(a, b, "ra ra pb");
	else if (arr[3] < arr[0] && arr[3] < arr[1] && \
	arr[3] < arr[2] && arr[3] < arr[4])
		execute(a, b, "rra rra pb");
	else if (arr[4] < arr[0] && arr[4] < arr[1] && \
	arr[4] < arr[2] && arr[4] < arr[3])
		execute(a, b, "rra pb");
	sort_four(a, b);
	execute(a, b, "pa");
}

void	sort_under_six(t_deque *a, t_deque *b)
{
	if (a -> size == 2)
		sort_two(a, b);
	else if (a -> size == 3)
		sort_three(a, b);
	else if (a -> size == 4)
		sort_four(a, b);
	else if (a -> size == 5)
		sort_five(a, b);
}
