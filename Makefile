# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 18:23:09 by buozcan           #+#    #+#              #
#    Updated: 2024/09/16 01:22:51 by bgrhnzcn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++

FLAGS = -g -std=c++20 -Wall -Werror -Wextra #-pedantic

NAME = libmlxcpp.a

SRCEXT = cpp

SRCDIR = ./src

SRCS = $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")

OBJEXT = o

OBJDIR = ./obj

OBJS = $(patsubst $(SRCDIR)/%.$(SRCEXT), $(OBJDIR)/%.$(OBJEXT), $(SRCS))

INCEXT = hpp

INC = $(shell find . -type f -name "*.h*" -exec dirname {} \; | sort -u  | sed 's/^/-I/')

MLX_DIR = ./lib/mlx

MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME): $(MLX) $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(MLX_DIR):
	@echo "Downloading MiniLib x For Linux..."
	@curl -s https://cdn.intra.42.fr/document/document/18343/minilibx-linux.tgz -o $(MLX_DIR).tgz
	@mkdir $(MLX_DIR)
	@tar xvfz $(MLX_DIR).tgz --strip 1 -C $(MLX_DIR) > /dev/null 2> /dev/null
	@rm $(MLX_DIR).tgz

$(MLX): | $(MLX_DIR)
	@echo "Compiling mlx"
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(MLX)
	@rm -f $(NAME)

re: fclean all

print:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(INC)

test: $(NAME)
	@rm -f test
	$(CC) $(FLAGS) main.$(SRCEXT) -o test $(INC) -L./ -lmlxcpp -L$(MLX_DIR) $(MLX) -lXext -lX11
	@./test

.PHONY: all clean re fclean test