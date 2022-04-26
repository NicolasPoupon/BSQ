##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile BSQ with libmy
##

SRC	=	main_bsq.c	\
		bsq.c	\
		fill_map_bsq.c	\
		fill_map_bsq_int.c	\
		replace_square_by_x.c	\
		error_handling_bsq.c	\

SRC_TESTS	=	bsq.c   \
			fill_map_bsq.c	\
			fill_map_bsq_int.c	\
			replace_square_by_x.c	\
			error_handling_bsq.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

.PHONY : all clean fclean re tests_run

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(OBJ) -L lib/my/ -o $(NAME) -lmy

clean:
	rm -f *.o
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	make clean -C lib/my
	rm -f ./a.out

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

tests_run:
	make -C lib/my
	gcc $(SRC_TESTS) -L lib/my -lmy ./tests/test.c --coverage -lcriterion
	./a.out
