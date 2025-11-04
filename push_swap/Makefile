# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 04:46:41 by juan-her          #+#    #+#              #
#    Updated: 2025/11/03 01:01:53 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
NAME = push_swap
SRCLIBFT = ./libft
LIBFT = $(SRCLIBFT)/libft.a
SRCPRINTF = ./ft_printf
FT_PRINTF = $(SRCPRINTF)/libftprintf.a
SRC = main.c parsing.c
OBJ_URL = ./obj
OBJ = $(SRC:%.c=$(OBJ_URL)/%.o)
INCLUDE = -I$(SRCLIBFT) -I$(SRCPRINTF) parsing.h
RM = rm -rf

all: $(LIBFT) $(FT_PRINTF) $(NAME)
	@echo "Push_swap ready."

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(SRCLIBFT) -lft -L$(SRCPRINTF) -lftprintf -o $(NAME)
	@echo "Finish $(NAME)"

$(LIBFT):
	@$(MAKE) -C $(SRCLIBFT)

$(FT_PRINTF):
	@$(MAKE) -C $(SRCPRINTF)

$(OBJ_URL):
	@mkdir -p $(OBJ_URL)

$(OBJ_URL)/%.o:%.c | $(OBJ_URL)
	@$(CC) $(CFLAGS) -L$(SRCLIBFT) -lft -L$(SRCPRINTF) -lftprintf -c $< -o $@

clean:
	@$(MAKE) -C $(SRCLIBFT) clean
	@$(MAKE) -C $(SRCPRINTF) clean
	@$(RM) $(OBJ_URL)
	@echo "Objects deleted."

fclean: clean
	@$(MAKE) -C $(SRCLIBFT) fclean
	@$(MAKE) -C $(SRCPRINTF) fclean
	@$(RM) $(NAME)
	@echo "Program deleted."

re: fclean all
	@echo "Re Program."

.PHONY: all clean fclean re
