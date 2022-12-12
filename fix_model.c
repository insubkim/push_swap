/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_model.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:10:38 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_model(t_model *model)
{
	int	size;
	int	i;

	size = 1;
	while (model -> next)
	{
		model = model -> next;
		size++;
	}
	if (size >= 3 && size % 2 == 1)
	{
		while (model)
		{
			i = 0;
			while (i < model -> div_count)
				model -> div_arr_order[i++] *= -1;
			model = model -> prev;
		}
	}
}
