# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:46:29 by tchow-so          #+#    #+#              #
#    Updated: 2024/04/29 10:51:04 by tchow-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

# ============================================================================ #
# FILES                                                                        #
# ============================================================================ #

SRC		= $(addprefix $(SRC_DIR)/, main.c check_input.c check_input2.c \
	stack_init.c stack_utils.c sort_check.c sort_nano.c sort_any.c \
	mem_utils.c op_push.c op_reverse_rotate.c op_rotate.c op_swap.c)
OBJS	 	= $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.c=.o)))
LIBFT_ARC	= $(LIBFT_DIR)/libft.a


# ============================================================================ #
# PATHS                                                                        #
# ============================================================================ #

INC_DIR		= include
SRC_DIR 	= src
BUILD_DIR	= .build
LIBS_DIR	= libs

# Libraries
LIBFT_DIR	= $(LIBS_DIR)/libft


# ============================================================================ #
# COMPILER, FLAGS & COMMANDS                                                   #
# ============================================================================ #

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -g

MAKE	= make -C

RM	= rm -rf
AR	= ar rcs
MKDIR	= mkdir -p


# ============================================================================ #
# RULES                                                                        #
# ============================================================================ #

##@ COMPILATION RULES

all: $(NAME)	## Compile push_swap

$(NAME): $(LIBFT_ARC) $(BUILD_DIR) $(OBJS)
	@printf "$(GRN)>> Generated object files$(RES)\n\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)
	@printf "$(GRN)>> Compiled push_swap$(RES)\n\n"


$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)
	@printf "$(GRN)>> Created .build/ directory for object files$(RES)\n\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Library directories
$(LIBFT_DIR):
	git clone https://github.com/teresa-chow/42-libft-extended.git libs/libft
	@printf "$(GRN)>> Cloned Libft$(RES)\n\n"

# Library archives
$(LIBFT_ARC): $(LIBFT_DIR)
	$(MAKE) $(LIBFT_DIR)
	@printf "$(GRN)>> Created Libft archive$(RES)\n\n"


##@ CLEAN-UP RULES

clean:	## Remove object files
	$(RM) $(BUILD_DIR)
	$(MAKE) $(LIBFT_DIR) clean
	@printf "$(GRN)>> Removed object files$(RES)\n\n"

fclean: clean	## Remove executable files
	$(RM) $(NAME)
	@printf "$(GRN)>> Removed executable files$(RES)\n\n"
	$(MAKE) $(LIBFT_DIR) fclean
	@printf "$(GRN)>> Removed Libft archive$(RES)\n\n"

re: fclean all	## Purge and recompile


##@ STANDARD COMPLIANCE CHECK

norm:	## Execute norminette
	norminette $(INC_DIR)/push_swap.h
	norminette $(SRC_DIR)


##@ LEAK CHECK

valgrind:	## Run valgrind
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 3 2 1


##@ TOOL INSTALLATION

install: ## Install norminette and valgrind
	python3 -m pip install --upgrade pip setuptools
	python3 -m pip install norminette
	sudo apt install valgrind -y


##@ HELP

help:	## Display this help info
	@awk 'BEGIN { \
		FS = ":.*##"; \
		printf "\n$(WHI_B)USAGE$(RES)\n\t$(YEL)make$(RES)$(CYA)\t \
		<target>$(RES)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
		printf "\t$(CYA_B)%-15s$(RES) %s\n", $$1, $$2 } \
		/^##@/ { printf "\n$(WHI_B)%s$(RES)\n", \
		substr($$0, 5) } ' Makefile
	@printf "\n"

.PHONY: all clean fclean re help


# ============================================================================ #
# UTILS: SHELL FORMATTING                                                      #
# ============================================================================ #

# Reset to default
RES = \033[0m

# Regular text colors
RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYA = \033[0;36m
WHI = \033[0;37m

# Bold text colors
RED_B = \033[1;31m
GRN_B = \033[1;32m
YEL_B = \033[1;33m
BLU_B = \033[1;34m
MAG_B = \033[1;35m
CYA_B = \033[1;36m
WHI_B = \033[1;37m