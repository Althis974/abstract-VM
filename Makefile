# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#   Makefile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: rlossy <rlossy@student.le-101.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#   Created: 2020/05/18 10:26:09 by rlossy             #+#    #+#              #
#   Updated: 2020/05/18 10:30:33 by rlossy            ###    ########lyon.fr   #
#                                                                              #
# **************************************************************************** #

NAME		=	avm
HEADER		=	./includes/
FILENAMES	=	main.cpp Lexer.cpp Exception.cpp Computer.cpp

SOURCES		=	$(addprefix srcs/, $(FILENAMES))
OBJECTS		=	$(addprefix build/, $(FILENAMES:.cpp=.o))

FLAGS		=	-Wall -Wextra -Werror -O2

LOADIR		=	./extra/Progress_Bar-for-Makefile
LOADF		=	$(LOADIR)/loading.sh

.PHONY: all clean fclean re


all: $(NAME)

clean:
	@echo "\033[31m"
	@bash $(LOADF) $(LOADIR) $@ r n $(NAME)
	@rm -rf build/
	@printf "\n\033[1m\033[34m\t\t\t\t⥷ $(NAME)⭃\tObject Files\t\033[0m\
	\033[1m⟿ \t\033[31mDeletion Success\033[0m ✅\n"

fclean: clean
	@echo "\033[31m"
	@bash $(LOADF) $(LOADIR) $@ r n $(NAME)
	@rm -f $(NAME)
	@printf "\n\033[1m\033[34m\t\t\t\t⥷ $(NAME)⭃\tCompiled Files\t\033[0m\
	\033[1m⟿ \t\033[31mDeletion Success\033[0m ✅\n"

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

build: 
	@echo "\033[35m"
	@mkdir build/

$(NAME): $(OBJECTS)
	@printf "\n\033[1m\033[34m\t\t\t\t⥷ $@⭃\tObject Files\033[0m \
		\033[1m⟿ \t\033[32mCreation Success\033[0m ✅\n"
	@echo "\033[42m\033[30m"
	@bash $(LOADF) $(LOADIR) $@ e n $(NAME)
	@echo "\033[0m"
	@clang++ $(FLAGS) -I $(HEADER) $(OBJECTS) -o $@
	@printf "\n\033[1m\033[34m\t\t\t\t⥷ $@⭃\tProject\t\t\033[0m \033[1m⟿  \
		\033[32mCreation Success\033[0m ✅\n"

build/%.o: srcs/%.cpp $(HEADER) | build
	@bash $(LOADF) $(LOADIR) $< o y
	@clang++ $(FLAGS) -I $(HEADER) -c $< -o $@
