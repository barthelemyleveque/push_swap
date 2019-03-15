# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleveque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 10:15:06 by bleveque          #+#    #+#              #
#    Updated: 2019/03/11 13:44:04 by bleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re 

NAME = checker

SRC_NAME = checkfile.c solver.c main.c \

SRCS_PATH = srcs/
OBJS_PATH = objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRCS = $(addprefix $(SRCS_PATH),$(SRC_NAME))
OBJS = $(addprefix $(OBJS_PATH),$(OBJ_NAME))

CC = clang
CFLAGS = -Wall -Wextra -Werror
I_FLAG = -Iincludes
LIB_PATH = -Llibft
LIB_NAME = -lft

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(I_FLAG) -o $@ -c $<

all : $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(LIB_PATH) $(LIB_NAME) $^ -o $@

clean :
	@/bin/rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@make clean -C libft

fclean : clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re : fclean all
