/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 10:59:21 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(t_deque *a, t_deque *b)
{
	t_model	*model;

	model = find_model(a -> size);
	fix_model(model);
	model = get_last_model(model);
	divide(a, b, model);
	while (model -> prev)
	{
		conquer(a, b, model);
		model = model -> prev;
	}
	if (b -> size)
		pop_chunk(b, a, b -> size);
	free_model(model);
}
