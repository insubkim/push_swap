/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_deque.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 14:42:34 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop(t_deque *deque)
{
	t_list	*node;

	if (!deque || !(deque -> top))
		return (0);
	node = deque -> top;
	if (deque -> top -> next)
	{
		deque -> top = deque -> top -> next;
		deque -> top -> back = 0;
	}
	else
	{
		deque -> top = 0;
		deque -> bottom = 0;
	}
	node -> next = 0;
	node -> back = 0;
	(deque -> size)--;
	return (node);
}

t_list	*pop_bottom(t_deque *deque)
{
	t_list	*node;

	if (!deque || !(deque -> bottom))
		return (0);
	node = deque -> bottom;
	if (deque -> bottom -> back)
	{
		deque -> bottom = deque -> bottom -> back;
		deque -> bottom -> next = 0;
	}
	else
	{
		deque -> top = 0;
		deque -> bottom = 0;
	}
	node -> next = 0;
	node -> back = 0;
	(deque -> size)--;
	return (node);
}

void	push(t_deque *deque, t_list *node)
{
	if (!deque || !node)
		return ;
	node -> next = deque -> top;
	if (deque -> top)
		deque -> top -> back = node;
	node -> back = 0;
	deque -> top = node;
	if (deque -> bottom == 0)
		deque -> bottom = node;
	(deque -> size)++;
}

void	push_bottom(t_deque *deque, t_list *node)
{
	if (!deque || !node)
		return ;
	node -> next = 0;
	if (deque -> bottom)
		deque -> bottom -> next = node;
	node -> back = deque -> bottom;
	deque -> bottom = node;
	if (deque -> top == 0)
		deque -> top = node;
	(deque -> size)++;
}

t_deque	*make_deque(char *name, int *args, int size)
{
	t_deque	*deque;
	t_list	*node;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		print_error();
	deque -> name = name;
	deque -> size = 0;
	deque -> top = 0;
	deque -> bottom = 0;
	while (size-- > 0)
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (!node)
			print_error();
		node -> val = args[size];
		push(deque, node);
	}
	return (deque);
}
