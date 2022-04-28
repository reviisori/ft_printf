# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 13:24:47 by altikka           #+#    #+#              #
#    Updated: 2022/04/28 16:59:49 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCS = -I libft/ -I includes/

SRC_DIR = src/
SRCS = src/ft_printf.c \
	   src/print_shop.c

OBJ_DIR = obj/
OBJ_LIBFT = libft/*.o
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

FLGS = -Wall -Wextra -Werror

NCOLOR = \033[0m
LGRAY = \033[1;30m
RED = \033[0;31m
LGREEN = \033[1;32m
GREEN = \033[0;32m
YELLOW= \033[0;33m
PURP = \033[0;35m
W = \033[1;37m

all: $(NAME)

$(NAME):
	@echo "$(NCOLOR)"
	@echo "__________________________________________________________________"
	@echo "__________________________________________________________________"
	@echo "                .-..                       .  .-.                 "
	@echo "                | _|_              o      _|_ |                   "
	@echo "               -|- |      .,-. .--..  .--. | -|-                  "
	@echo "                |  |      |   )|  /|  |  | |  |                   "
	@echo "                |   -'____| -' '    --'   - -'|                   "
	@echo "________________'_________|___________________'___________________"
	@echo "                          '$(W)    by altikka                     "
	@echo "$(NCOLOR)"
	@make -C libft/
	@mkdir $(OBJ_DIR)
	@echo "$(LGRAY)[ft_printf] $(PURP)Making object files..."
	@gcc -c $(FLGS) $(INCS) $(SRCS)
	@mv *.o $(OBJ_DIR)
	@echo "$(LGRAY)[ft_printf] $(PURP)Creating library libftprintf.a"
	@ar rcs $(NAME) $(OBJS) $(OBJ_LIBFT)
	@echo "$(LGRAY)[ft_printf] $(PURP)Library created!"

clean:
	@make -C libft/ clean
	@echo "$(LGRAY)[ft_printf] $(RED)Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft/ fclean
	@echo "$(LGRAY)[ft_printf] $(RED)Removing library..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
