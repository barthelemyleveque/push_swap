# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleveque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 10:15:06 by bleveque          #+#    #+#              #
#    Updated: 2019/03/26 17:35:26 by bleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, libft, clean, fclean, re 

NAME_1 = checker
NAME_2 = push_swap

INC_PATH = includes/
SRCS_PATH = srcs/
OBJS_PATH = objs/
LIB_PATH = libft/

SRC_NAME_1 = fonctions_pusw.c \
			 fonctions_rr.c \
			 init_checker.c \
			 init_struct.c \
			 init_tab.c \
			 quick_sort.c \
			 visualiser.c \
			 check_errors.c \
			 free_for_all.c \
			 start_split.c \
			 side.c \

SRC_NAME_2 = fonctions_pusw.c \
			 fonctions_rr.c \
			 init_struct.c \
			 init_tab.c \
			 quick_sort.c \
			 visualiser.c \
			 check_errors.c \
			 init_push_swap.c \
			 free_for_all.c \
			 start_split.c \
			 nuclear_reactor.c \
			 tri_tri.c \
			 functions_for_tri.c \
			 side.c \

INC_NAME = push_swap.h
LIB_NAME = libft.a
OBJ_NAME_1 = $(SRC_NAME_1:.c=.o)
OBJ_NAME_2 = $(SRC_NAME_2:.c=.o)
SRCS_1 = $(addprefix $(SRCS_PATH),$(SRC_NAME_1))
OBJS_1 = $(addprefix $(OBJS_PATH),$(OBJ_NAME_1))
SRCS_2 = $(addprefix $(SRCS_PATH),$(SRC_NAME_2))
OBJS_2 = $(addprefix $(OBJS_PATH),$(OBJ_NAME_2))
INC = $(addprefix $(INC_PATH),$(INC_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

RED = \x1b[31;01m
BLUE = \x1b[36;01m

CC = clang
CFLAGS = -Wall -Wextra -Werror

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC_PATH) -o $@ -c $<

all : lib $(NAME_1) $(NAME_2)

lib :
	@cd $(LIB_PATH) ; $(MAKE) -f Makefile

$(NAME_1) : $(OBJS_1) $(LIB)
	@$(CC) $(LIB) $^ -o $@
	@echo "$(RED)checker has compiled ✓✓$(END)"

$(NAME_2) : $(OBJS_2) $(LIB)
	@$(CC) $(LIB) $^ -o $@
	@echo "$(BLUE)push_swap has compiled ✓✓✓$(END)"

clean :
	@/bin/rm -f $(OBJS_1) $(OBJS_2)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@cd $(LIB_PATH) ; $(MAKE) fclean 


fclean : clean
	@/bin/rm -f $(NAME_1) $(NAME_2)
	@make fclean -C libft

re : fclean all
