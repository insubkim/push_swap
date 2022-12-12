/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:27:09 by inskim            #+#    #+#             */
/*   Updated: 2022/07/30 21:27:09 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*error_handle(t_list **lst, int fd, char *read_buf);
int		has_newline(t_list *lst, int fd);
int		ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, int len);
t_list	*get_node(t_list *lst, int fd);

#endif
