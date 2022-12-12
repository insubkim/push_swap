/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:01:14 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_deque *deque)
{
	if (!deque || !(deque -> top))
		print_error();
	return (deque -> top -> val);
}

int	peek_bottom(t_deque *deque)
{
	if (!deque || !(deque -> bottom))
		print_error();
	return (deque -> bottom -> val);
}
