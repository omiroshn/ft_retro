# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/07 15:58:43 by omiroshn          #+#    #+#              #
#    Updated: 2018/04/08 17:22:40 by kshyshki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro
FILES = main Ship AObject Bulet EnemyShip GameEntity
HDRS =  includes/Ship.hpp includes/AObject.hpp includes/Bulet.hpp \
		includes/EnemyShip.hpp includes/GameEntity.hpp
HEADERS = -I./includes
SRC = $(addprefix src/, $(addsuffix .cpp, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
FLAGS = -Wall -Werror -Wextra -O3 -std=c++98 

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(OBJ) -o $(NAME) -lncurses -flto=thin
obj/%.o: src/%.cpp $(HDRS)
	clang++ -o $@ $(FLAGS) $(HEADERS) -c $<
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
