/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:49 by inskim            #+#    #+#             */
/*   Updated: 2022/12/02 09:29:45 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*back;
}	t_list;

typedef struct s_deque
{
	struct s_list	*front;
    struct s_list	*rear;
}	t_deque;

void	print_error(void);
size_t	ft_strlen(const char *s);
int		*check_arg(int count, char **argv);
int		*check_stdin(void);
t_deque   *put_arg(int *args, int size);




#endif