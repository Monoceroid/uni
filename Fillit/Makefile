# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 18:05:34 by gfranco           #+#    #+#              #
#    Updated: 2018/08/14 12:11:30 by wtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH)

SRC_PATH = ./src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRC = arrange.c               \
	  fillit.c        		  \
	  increment.c             \
	  output.c           	  \
	  store_check.c           \
	  upsize.c        		  \
	  validate.c   	          \
	  zero.c	              \
	 
OBJ_PATH = ./obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_PATH = ./includes/
INCS = $(addprefix $(INC_PATH), $(INC))
INC = fillit.h

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@clear
	@echo "            \033[1;34m                boing         boing         boing"
	@echo "             \033[1;32m e-e\033[1;31m           . - .         . - .         . - ."
	@echo "             \033[1;32m(\_/)\ \033[1;31m      '       '.   ,'       '.   ,'       '."
	@echo "              \033[1;32m'-'\ '--.___,\033[1;31m         . .           . .           ."
	@echo "               \033[1;32m'\( ,_.-'\033[1;31m             v             v            ."
	@echo "                   \033[1;32m\ \ \033[1;31m              .             .            . "
	@echo "                   \033[1;32m^'^'\033[1;31m"
#	@./fillit text

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
