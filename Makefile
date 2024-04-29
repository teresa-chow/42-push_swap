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


# ============================================================================ #
# NAMES & PATHS                                                                #
# ============================================================================ #

NAME		= push_swap

SRC		= #TODO

BUILD_DIR	= .build
OBJS	 	= $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.c=.o)))

LIBFT_DIR	= libft
LIBFT_ARC	= $(LIBFT_DIR)/libft.a


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

bonus: #TODO	## Compile push_swap with bonus features

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)
	@printf "$(GRN)>> Created .build/ directory for object files$(RES)\n\n"

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_ARC) $(BUILD_DIR) $(OBJS)	
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)
	@printf "$(GRN)>> Compiled Server$(RES)\n\n"

$(LIBFT_ARC):
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

.PHONY: all bonus clean fclean re help


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
