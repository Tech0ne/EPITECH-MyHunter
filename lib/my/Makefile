##
## EPITECH PROJECT, 2022
## makefile
## File description:
## make compile, clean, fclean, re...
##

SRC	=	*.c

HEADERS	=	*.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

$(NAME):	all

all:	compile

compile:
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(HEADERS) ../../includes/lib/
	cp $(NAME) ../

clean:
	rm -rf *~
	rm -rf \#*\#
	rm -rf $(OBJ)

fclean:	clean
	rm -rf ../../includes/lib/$(HEADERS)
	rm -rf ../$(NAME)
	rm -rf $(NAME)

re:	fclean	compile
