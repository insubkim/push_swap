/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:15:26 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:11:16 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char ***arr)
{
	int	i;
	int	j;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			free(arr[i][j]);
			j++;
		}
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_model(t_model *model)
{
	t_model	*tmp;

	while (model)
	{
		free(model -> div_arr);
		free(model -> div_arr_order);
		tmp = model;
		model = model -> next;
		free(tmp);
	}
}

void	free_deque(t_deque *deque)
{
	while (deque -> top)
		free(pop(deque));
	free(deque);
}
