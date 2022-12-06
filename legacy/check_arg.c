/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/01 17:59:13 by inskim           ###   ########.fr       */
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
    if (!*s || !(INT_MIN <= num && num <= INT_MAX))
        print_error();
    return (num);
}

int get_args_size(char ***arr)
{
    int size;

    size = 0;
    while (arr)
    {
        while (*arr)
        {
            size++;
            (*arr)++;
        }
        arr++;
    }
}

int *check_arg(int count, char **argv)
{
    int     *args;
    char    ***arr;
    int     size;
    int     i;

    arr = split_args(count, argv);
    args = (int *)malloc(sizeof(int) * (get_args_size(arr) + 1));
    if (!args)
        print_error();
    i = 0;
    while (arr)
    {
        while (*arr)
        {
            args[i++] = ft_atoix(**arr);
            (*arr)++;
        }
        arr++;
    }
    args[i] = args[i - 1];
    free_arr(arr);
    return (args);
}