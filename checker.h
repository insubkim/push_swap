/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 13:45:27 by inskim           ###   ########.fr       */
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

void    free_arr(char ***arr);
int     ft_strcmp(char *s1, char *s2);
void	execute(t_deque *a, t_deque *b, char *s);
char	**ft_split(char *str, char *charset);
void	print_error(void);
void	check_dup(int *args, int size);
char	**parse_arg(int argc, char **argv);
int		*ft_atoi_s(char **arr, int *size);
void	free_deque(t_deque *deque);
void	rotate(t_deque *a);
void	rotate_both(t_deque *a, t_deque *b);
void	r_rotate(t_deque *a);
void	r_rotate_both(t_deque *a, t_deque *b);
void	pop_push(t_deque *from, t_deque *to);
void	swap(t_deque *a);
void	swap_both(t_deque *a, t_deque *b);

#endif