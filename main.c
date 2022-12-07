/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/07 22:37:41 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int *args;
    int size;
    t_deque *a;
    t_deque *b;

    // args = ft_atoi_s(parse_arg(--argc, ++argv), &size);
    // check_dup(args, size);

    // int i  = 0;
    // while (size > i)
    //     printf("%d\n", args[i++]);
    size = 500;
    args = malloc(sizeof(int) * size);
    int i = 0;
    while (i < size)
    {
        args[i] = size -i;
        i++;
    }
    
    
    a = make_deque_a(args, size);
    b = make_deque_b();
    
    // while (a->top)
    // {
    //     printf("%d\n", a->top->val);
    //     a->top = a->top->next;
    // }
    // while (b->top)
    // {
    //     printf("%d\n", b->top->val);
    //     b->top = b->top->next;
    // }
    push_swap(a,b);
     while (b->top)
     {
         printf("%d\n", b->top->val);
         b->top = b->top->next;
     }
    return (0);
}