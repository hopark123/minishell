# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 14:12:16 by hjpark            #+#    #+#              #
#    Updated: 2021/06/30 21:38:16 by hjpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -O2 -lncurses
#CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -g3 -fsanitize=address
RM = rm
RMFLAGS = -f
SRC_DIR = src
INC_DIR = include
ENGINE_DIR = $(SRC_DIR)/engine
UTIL_DIR = $(SRC_DIR)/util
PASSING_DIR = $(SRC_DIR)/passing
TERM_DIR = $(SRC_DIR)/term
OBJ_DIR = obj

INCLUDE = $(wildcard $(INC_DIR)/*.h)
ENGINE = $(wildcard $(ENGINE_DIR)/*.c)
PASSING = $(wildcard $(PASSING_DIR)/*.c)
UTIL = $(wildcard $(UTIL_DIR)/*.c)
TERM = $(wildcard $(TERM_DIR)/*.c)


vpath %.c \
	$(SRC_DIR) \
	$(ENGINE_DIR) \
	$(PASSING_DIR)\
	$(UTIL_DIR) \
	$(TERM_DIR) \


SRC = \
	$(ENGINE) \
	$(PASSING)\
	$(UTIL) \
	$(TERM) \
	main3.c

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
