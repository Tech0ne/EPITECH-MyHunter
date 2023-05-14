##
## EPITECH PROJECT, 2022
## makefile
## File description:
## make compile, clean, fclean, re...
##

SRC	=	src/*.c

NAME	=	my_hunter

DEBUG_NAME	=	$(NAME)-debug

LIB	=	./lib/my/

HEADERS	=	./includes/

FLAGS	=	-L$(LIB) -lmy -I$(HEADERS) -lcsfml-graphics -lcsfml-window	\
			-lcsfml-audio -lcsfml-system

DEBUG_FLAGS	=	-Wall -Wextra -g3

$(NAME):	all

all:	compile

compile:
	make -C $(LIB)
	gcc $(SRC) -o $(NAME) $(FLAGS)

debug:
	make -C $(LIB)
	gcc $(SRC) -o $(DEBUG_NAME) $(FLAGS) $(DEBUG_FLAGS)

clean:
	make -C $(LIB) clean
	rm -rf \#*\#
	rm -rf *~
	rm -rf *.swp
	rm -rf *.o
	rm -rf coding-style-reports.log
	rm -rf vgcore*

fclean:	clean
	make -C $(LIB) fclean
	rm -rf $(NAME)
	rm -rf $(DEBUG_NAME)

cs:	fclean
	abricot .
	@echo "--- report made ---"

re:	fclean	compile

re-debug:	fclean debug

push:	fclean
	@git add .
	@echo -n "> "
	@read message; git commit -m "$$message"
	@git push
