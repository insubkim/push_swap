/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/11/29 18:48:29 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


#include <stdio.h>
int main(int argc, char **argv)
{
    int         *commands;
    t_deque   *deque;
    int         *args;

    args = check_arg(--argc, ++argv);

    printf("-----arg-----\n");
    for(int i = 0; i < argc; i++)
        printf("%d\n", args[i]);
    printf("\n\n\n");

    commands = check_stdin();

    printf("-----commands----\n");
    while (*commands)
    {
        printf("%d\n", *commands++);
    }
    printf("\n\n\n");
   
    
    deque = put_arg(args, argc);
    t_list *a = deque -> front;
   
    while (a)
    {
        printf("%d\n",(int)( a->content));
        a = a-> next;
    }
    system("leaks a.out > test");

    /*
    excute(deque, commands);
    check_deque(deque);
    print_deque(deque);
    */
    return (0);
}