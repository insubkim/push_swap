/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:44 by inskim            #+#    #+#             */
/*   Updated: 2022/12/12 11:52:52 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*s1 == *s2 && i++ < n)
	{
		if (*s1++ == 0 || i == n)
			return (0);
		s2++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*inc_s(char *s)
{
	while (*s && *s != ' ')
		s++;
	if (*s == ' ')
		s++;
	return (s);
}

void	execute2(t_deque *a, t_deque *b, char *s)
{
	if (!ft_strncmp(s, "ra", 2))
		rotate(a);
	else if (!ft_strncmp(s, "rb", 2))
		rotate(b);
	else if (!ft_strncmp(s, "rra", 3))
		r_rotate(a);
	else if (!ft_strncmp(s, "rrb", 3))
		r_rotate(b);
	else if (!ft_strncmp(s, "rrr", 3))
		r_rotate_both(a, b);
	else if (!ft_strncmp(s, "rr", 2))
		rotate_both(a, b);
}

void	execute(t_deque *a, t_deque *b, char *s)
{
	while (*s)
	{
		if (!ft_strncmp(s, "sa", 2))
			swap(a);
		else if (!ft_strncmp(s, "sb", 2))
			swap(b);
		else if (!ft_strncmp(s, "ss", 2))
			swap_both(a, b);
		else if (!ft_strncmp(s, "pa", 2))
			pop_push(b, a);
		else if (!ft_strncmp(s, "pb", 2))
			pop_push(a, b);
		else
			execute2(a, b, s);
		s = inc_s(s);
	}
}
