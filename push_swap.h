/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:21:09 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				val;
	struct s_list	*next;
	struct s_list	*back;
}	t_list;

typedef struct s_deque
{
	char			*name;
	int				size;
	struct s_list	*top;
	struct s_list	*bottom;
}	t_deque;

typedef struct s_model
{
	int				div_count;
	int				*div_arr;
	int				*div_arr_order;
	struct s_model	*next;
	struct s_model	*prev;
}	t_model;

void	print_error(void);
t_deque	*make_deque(char *name, int *args, int size);
void	push_swap(t_deque *a, t_deque *b);
void	merge_sort(t_deque *a, t_deque *b);
t_model	*find_model(int size);
t_list	*pop(t_deque *deque);
void	push(t_deque *deque, t_list *node);
int		peek(t_deque *deque);
int		peek_bottom(t_deque *deque);
void	check_dup(int *args, int size);
char	**parse_arg(int argc, char **argv);
int		*ft_atoi_s(char **arr, int *size);
int		ft_strlen(char *s);
void	free_arr(char ***arr);
char	**ft_split(char *s, char *c);
t_model	*get_last_model(t_model *model);
void	divide(t_deque *a, t_deque *b, t_model *model);
void	pop_push(t_deque *a, t_deque *b);
void	swap(t_deque *a);
void	rotate(t_deque *a);
void	r_rotate(t_deque *a);
int		peek_bottom(t_deque *deque);
void	push_bottom(t_deque *deque, t_list *node);
t_list	*pop_bottom(t_deque *deque);
void	conquer(t_deque *a, t_deque *b, t_model *model);
void	free_model(t_model *model);
void	free_deque(t_deque *deque);
void	sort_under_six(t_deque *a, t_deque *b);
void	execute(t_deque *a, t_deque *b, char *s);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	move_stack_three(t_deque *a, t_deque *b, int order);
void	move_stack_four(t_deque *a, t_deque *b, int order);
void	move_stack_five(t_deque *a, t_deque *b, int order);
char	*set_temp_arr(t_deque *a, char *arr, int order, int size);
void	r_rotate_both(t_deque *a, t_deque *b);
void	rotate_both(t_deque *a, t_deque *b);
void	swap_both(t_deque *a, t_deque *b);
void	pop_chunk(t_deque *from, t_deque *to, int size);
void	fix_model(t_model *model);

#endif
