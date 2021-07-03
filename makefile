# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 14:12:16 by hjpark            #+#    #+#              #
#    Updated: 2021/07/03 18:11:37 by hjpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CLIBR =  -lncurses
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -g3 -fsanitize=address
RM = rm
RMFLAGS = -f
SRC_DIR = src
INC_DIR = include
ENGINE_DIR = $(SRC_DIR)/engine
UTIL_DIR = $(SRC_DIR)/util
PASSING_DIR = $(SRC_DIR)/passing
TERMI_DIR = $(SRC_DIR)/termi
BUILTIN_DIR = $(SRC_DIR)/builtin
OBJ_DIR = obj

INCLUDE = $(wildcard $(INC_DIR)/*.h)
BUILTIN = $(wildcard $(BUILTIN_DIR)/*.c)
ENGINE = $(wildcard $(ENGINE_DIR)/*.c)
PASSING = $(wildcard $(PASSING_DIR)/*.c)
TERMI = $(wildcard $(TERMI_DIR)/*.c)
UTIL = $(wildcard $(UTIL_DIR)/*.c)


vpath %.c \
	$(SRC_DIR) \
	$(BUILTIN_DIR) \
	$(ENGINE_DIR) \
	$(PASSING_DIR)\
	$(TERMI_DIR) \
	$(UTIL_DIR) \


SRC = \
	$(BUILTIN) \
	$(ENGINE) \
	$(PASSING)\
	$(TERMI) \
	$(UTIL) \
	main3.c \

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
	@$(CC) $(CFLAGS) -I $(CLIBR) -I $(INC_DIR)  -c $< -o $@
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR)  -o $(NAME) $(OBJ) $(CLIBR)

.PHONY: all clean fclean re test\
