/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:05:27 by inskim            #+#    #+#             */
/*   Updated: 2022/11/29 18:43:40 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
    if (ft_strlen(s) > int_max_length() || !*s)
        print_error();
    while ('0' <= *s && *s <= '9')
        num = num * 10 + *s++ - '0';
    if (sign)
        num = -num;
    if (*s || !(INT_MIN <= num && num <= INT_MAX))
        print_error();
    return (num);
}

int *check_arg(int count, char **argv)
{
    int *args;

    args = (int *)malloc(sizeof(int) * count);
    if (!args)
        print_error();
    while  (count > 0)
        args[--count] = ft_atoix(*argv++);
    return (args);
}
