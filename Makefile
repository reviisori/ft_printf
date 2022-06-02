# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 21:54:04 by altikka           #+#    #+#              #
#    Updated: 2022/06/02 22:13:19 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCS = -I./libft -I./includes

SRC_DIR = src/
SRCS = $(SRC_DIR)ft_printf.c \
	   $(SRC_DIR)ft_vasprintf.c \
	   $(SRC_DIR)utilities.c \
	   $(SRC_DIR)press.c \
	   $(SRC_DIR)press_type.c \
	   $(SRC_DIR)inves_flags.c \
	   $(SRC_DIR)inves_width.c \
	   $(SRC_DIR)inves_preci.c \
	   $(SRC_DIR)inves_lenght.c \
	   $(SRC_DIR)tc_char.c \
	   $(SRC_DIR)tc_dbl.c \
	   $(SRC_DIR)round_dbl.c \
	   $(SRC_DIR)tc_len.c \
	   $(SRC_DIR)tc_num.c \
	   $(SRC_DIR)tc_ptr.c \
	   $(SRC_DIR)tc_str.c \
	   $(SRC_DIR)pad_nums_front.c \
	   $(SRC_DIR)pad_dbls_front.c \
	   $(SRC_DIR)pad_inf.c \
	   $(SRC_DIR)handlers.c

OBJ_DIR = obj/
OBJ_LIBFT = libft/*.o
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o) $(OBJ_LIBFT)

FLGS = -Wall -Wextra -Werror -O3

EOC = \033[0m
LGRAY = \033[38;5;244m
RED = \033[38;5;124m
PURP = \033[38;5;134m
GOLD = \033[38;5;136m

all: $(NAME)

$(NAME):
	@echo "$(EOC)"
	@echo "_________________________________________________________"
	@echo "_________________________________________________________"
	@echo "             .-..                       .  .-.           "
	@echo "             | _|_              o      _|_ |             "
	@echo "            -|- |      .,-. .--..  .--. | -|-            "
	@echo "             |  |      |   )|  /|  |  | |  |             "
	@echo "             |   -'____| -' '    --'   - -'|             "
	@echo "_____________'_________|___________________'_____________"
	@echo "                       '$(GOLD)   by altikka             "
	@echo "$(EOC)"
	@make -C ./libft
	@mkdir -p $(OBJ_DIR)
	@echo "$(LGRAY)[ft_printf] $(PURP)Making object files..."
	@gcc -c $(FLGS) $(INCS) $(SRCS)
	@mv *.o $(OBJ_DIR)
	@echo "$(LGRAY)[ft_printf] $(PURP)Creating library libftprintf.a"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(LGRAY)[ft_printf] $(PURP)Library created!"

clean:
	@make -C ./libft/ clean
	@echo "$(LGRAY)[ft_printf] $(RED)Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ./libft/ fclean
	@echo "$(LGRAY)[ft_printf] $(RED)Removing library..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
