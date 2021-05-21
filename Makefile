# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroland <rroland@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 20:41:01 by rroland           #+#    #+#              #
#    Updated: 2021/05/19 13:59:06 by rroland          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

FLAGS = -f macho64

SOURCE = ft_strlen.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s ft_strcmp.s

OBJECTS = $(SOURCE:.s=.o)

all: $(NAME)
%.o: %.s
	@nasm $(FLAGS) $< -o $@
$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
clean:
	@rm -f $(OBJECTS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus