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

int int_max_length(void)
{
    int len;
    int max;
    
    max = INT_MAX;
    len = 1;
    while (max / 10)
    {
        max = max / 10;
        len++;
    }
    return (len);
}

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (*s++)
        i++;
    return (i);
}

int ft_atoix(char *s)
{
    long long num;
    int sign;
    
    num = 0;
    sign = 0;
    if (*s == '-' || *s == '+')
        if (*s++ == '-')
            sign = 1;
    if (ft_strlen(s) > int_max_length())
        print_error();
    while ('0' <= *s && *s <= '9')
        num = num * 10 + *s++ - '0';
    if (sign)
        num = -num;
    if (*s || !(INT_MIN <= num && num <= INT_MAX))
        print_error();
    return (num);
}

int get_arr_len(char **arr)
{
    int len;

    len = 0;
    if (!arr)
        exit (0);
    while (arr[len])
        len++;
    return (len);
}

int *ft_atoi_s(char **arr, int *size)
{
    int *args;
    int i;

    *size = get_arr_len(arr);
    args = (int *)malloc(sizeof(int) * *size);
    if (!args && !arr)
        print_error();
    i = 0;
    while (i < *size)
    {
        args[i] = ft_atoix(arr[i]);
        i++;
    }
    return (args);
}