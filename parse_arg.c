/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/02 09:29:21 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **parse_arg(int argc, char **argv)
{
    int     size;
    int     i;
    char    ***tmp;
    char    **arr;

    if (!argc)
        exit(0);
    tmp = (char ***)malloc(sizeof(char **) * (argc + 1));
    if (!tmp)
        print_error();
    tmp[argc] = 0;
    i = -1;
    while (++i < tmp)
        tmp[i] = ft_split(argv[i], " ");
    size = get_tmp_size(tmp);
    arr = get_arr(tmp);
    free(tmp);
    return (arr);
}