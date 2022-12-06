/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/06 15:15:30 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h> 
# include <limits.h> 


typedef struct s_list
{
	int             val;
	struct s_list	*next;
	struct s_list	*back;
}	t_list;

typedef struct  s_deque
{
    int size;
    struct  s_list  *top;
    struct  s_list  *bottom;
}   t_deque;

typedef struct  s_model
{
    int div_count;
    int *div_arr;
    int *div_arr_order;
    struct  s_model *next;
    struct  s_model *prev;
}   t_model;

void print_error(void);
t_deque *make_deque_a(int   *args, int size);
t_deque *make_deque_b(void);
void    push_swap(t_deque *a, t_deque *b);
void    merge_sort(t_deque *a, t_deque *b);
t_model *find_model(int size);
t_list *pop(t_deque *deque);
void    push(t_deque *deque, t_list *node);
int peek(t_deque *deque);
int peek_bottom(t_deque *deque);
void    check_dup(int *args, int size);
char **parse_arg(int argc, char **argv);
int *ft_atoi_s(char **arr, int *size);
int ft_strlen(char *s);
void    free_arr(char ***arr);
char	**ft_split(char *s, char *c);

//-----------------지우셈..
#include <stdio.h>



//-----------------
#endif