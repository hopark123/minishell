# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 14:12:16 by hjpark            #+#    #+#              #
#    Updated: 2021/07/05 14:08:43 by hjpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -o2
CLIBR =  -lncurses
# CFLAGS = -Wall -Wextra -Werror
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

INCLUDE = $(addprefix $(INC_DIR)/, \
	builtin.h \
	engine.h  \
	head.h  \
	passing.h  \
	termi.h \
	type.h  \
	util.h \
)
BUILTIN = $(addprefix $(BUILTIN_DIR)/, \
	ft_builtin.c \
	ft_cd.c \
	ft_echo.c \
	ft_env_list.c \
	ft_env.c \
	ft_export.c \
	ft_getenv.c \
	ft_pwd.c \
	ft_unset.c \
)

ENGINE = $(addprefix $(ENGINE_DIR)/, \
	ft_error.c \
	ft_execute.c \
	ft_execve.c \
	ft_exit.c \
	ft_guard.c \
	ft_parent.c \
	ft_pipe.c \
	ft_redirect.c \
	ft_shell.c \
	ft_signal.c \
	ft_subshell.c \
)
PASSING = $(addprefix $(PASSING_DIR)/, \
	ft_del_blank.c \
	ft_del_quotes.c \
	ft_envswap.c \
	ft_get_line.c \
	ft_parse.c \
	ft_split_built.c \
	ft_syntax.c \
	ft_token_split.c \
)
TERMI = $(addprefix $(TERMI_DIR)/, \
	ft_cursor.c \
	ft_history.c \
	ft_init_term.c \
)
UTIL = $(addprefix $(UTIL_DIR)/, \
	ft_add_char.c \
	ft_atoi.c \
	ft_built.c \
	ft_draw.c \
	ft_free.c \
	ft_isalpha.c \
	ft_itoa.c \
	ft_list.c \
	ft_list2.c \
	ft_list3.c \
	ft_listjoin.c \
	ft_malloc.c \
	ft_memory.c \
	ft_memory2.c \
	ft_memory3.c \
	ft_num.c \
	ft_split.c \
	ft_write.c \
	get_next_line.c \
)

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
	main.c \

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
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(CLIBR) -I $(INC_DIR)  -c $< -o $@

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR)  -o $(NAME) $(OBJ) $(CLIBR)

.PHONY: all clean fclean re test\
