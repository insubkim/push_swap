# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 08:02:44 by inskim            #+#    #+#              #
#    Updated: 2022/12/12 13:55:44 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = CC
CFLAGS = -Wall -Werror -Wextra -g

SRC = check_dup.c command1.c command2.c conquer.c deque.c divide.c error_handle.c execute.c fix_model.c free.c ft_atoi_s.c ft_split.c main.c merge_sort.c model.c move_stack_five.c move_stack_four.c move_stack_three.c parse_arg.c peek_deque.c push_swap.c sort_under_six.c
HEADER = push_swap.h
OBJ = $(SRC:.c=.o)
BONUS_SRC = checker.c checker_util.c check_dup.c execute.c free.c ft_atoi_s.c ft_split.c parse_arg.c deque.c command1.c command2.c error_handle.c get_next_line.c get_next_line_utils.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) 
	$(CC) $(CFLAGS) -o $@ $(OBJ)

bonus: $(BONUS_OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o checker $(BONUS_OBJ)

clean:
	rm -f $(NAME) checker

fclean:	clean
	rm -f $(OBJ) $(BONUS_OBJ)

re: fclean
	all

.phony: all clean fclean re bonus