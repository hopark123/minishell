# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 18:03:34 by hopark            #+#    #+#              #
#    Updated: 2021/05/20 20:58:52 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
NAME2 = echo
NAME3 = cd

CC = gcc
CFLAGS = -O2
#CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
#CFLAGS = -g3 -fsanitize=address
RM = rm
RMFLAGS = -f
SRC_DIR = src
INC_DIR = include
ENGINE_DIR = $(SRC_DIR)/engine
UTIL_DIR = $(SRC_DIR)/util
PASSING_DIR = $(SRC_DIR)/passing
UTIL_DIR = $(SRC_DIR)/util
OBJ_DIR = obj

INCLUDE = $(wildcard $(INC_DIR)/*.h)
ENGINE = $(wildcard $(ENGINE_DIR)/*.c)
PASSING = $(wildcard $(PASSING_DIR)/*.c)
UTIL = $(wildcard $(UTIL_DIR)/*.c)

vpath %.c \
	$(SRC_DIR) \
	$(UTIL_DIR) \
	$(PASSING_DIR)\
	$(ENGINE_DIR) \

SRC = \
	$(ENGINE) \
	$(UTIL) \
	$(PASSING)\
	main2.c

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : $(NAME)
	./minishell
$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
