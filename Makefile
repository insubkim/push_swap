# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 08:02:44 by inskim            #+#    #+#              #
#    Updated: 2022/12/12 16:43:55 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

SRC = check_dup.c command1.c command2.c conquer.c deque.c divide.c error_handle.c execute.c fix_model.c free.c ft_atoi_s.c ft_split.c main.c merge_sort.c model.c move_stack_five.c move_stack_four.c move_stack_three.c parse_arg.c peek_deque.c swap.c sort_under_six.c
HEADER = push_swap.h
OBJ = $(SRC:.c=.o)
BONUS_SRC = checker.c checker_util.c check_dup.c execute.c free.c ft_atoi_s.c ft_split.c parse_arg.c checker_deque.c command1.c command2.c error_handle.c get_next_line.c get_next_line_utils.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): make_mandatory

bonus: make_bonus

make_mandatory: $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	touch $@

make_bonus: $(BONUS_OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o checker $(BONUS_OBJ)
	touch $@

clean:
	rm -f make_mandatory
	rm -f make_bonus
	rm -f $(OBJ) $(BONUS_OBJ)

fclean:	clean
	rm -f $(NAME) checker

re: fclean
	make all

.phony: all clean fclean re bonus