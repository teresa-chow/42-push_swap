# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 16:14:04 by tchow-so          #+#    #+#              #
#    Updated: 2024/03/26 16:07:32 by tchow-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


# ============================================================================ #
# NAMES & PATHS                                                                #
# ============================================================================ #

LIBFT_PATH = ./libft
LIBFT_SRC	= $(addprefix $(LIBFT_PATH)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c)

FTPRINTF_PATH = ./ft_printf
FTPRINTF_SRC	= $(addprefix $(FTPRINTF_PATH)/, ft_printf.c ft_printchar.c \
	ft_printstr.c ft_printptr.c ft_printint.c)

GNL_PATH = ./get_next_line
GNL_SRC		= $(addprefix $(GNL_PATH)/, get_next_line.c get_next_line_utils.c)

BUILD_PATH = .build
OBJS		= $(LIBFT_OBJS) $(FTPRINTF_OBJS) $(GNL_OBJS)
LIBFT_OBJS	= $(addprefix $(BUILD_PATH)/, $(notdir $(LIBFT_SRC:.c=.o)))
FTPRINTF_OBJS	= $(addprefix $(BUILD_PATH)/, $(notdir $(FTPRINTF_SRC:.c=.o)))
GNL_OBJS	= $(addprefix $(BUILD_PATH)/, $(notdir $(GNL_SRC:.c=.o)))


# ============================================================================ #
# FLAGS & COMMANDS                                                             #
# ============================================================================ #

MAKE	= make -C
CFLAGS	= -Wall -Wextra -Werror

CC	= cc
RM	= rm -rf
AR	= ar rcs
MKDIR	= mkdir -p


# ============================================================================ #
# RULES                                                                        #
# ============================================================================ #

all: $(NAME)

$(NAME): $(BUILD_PATH) $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(BUILD_PATH):
	$(MKDIR) $(BUILD_PATH)

$(BUILD_PATH)/%.o: $(LIBFT_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(FTPRINTF_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(GNL_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	$(RM) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
