/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:15:26 by inskim            #+#    #+#             */
/*   Updated: 2022/12/06 15:08:48 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_arr(char ***arr)
{
    int i;
    int j;

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