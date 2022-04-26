##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile libmy.a
##

SRC	=	my_strcapitalize.c	\
	my_str_islower.c	\
	my_putstr.c	\
	my_sort_int_array.c	\
	my_compute_power_it.c	\
	my_strcpy.c	\
	my_compute_square_root.c	\
	my_strlen.c	\
	my_strlowcase.c	\
	my_showmem.c	\
	my_putchar.c	\
	my_strncpy.c	\
	my_str_isupper.c	\
	my_compute_factorial_it.c	\
	my_isneg.c	\
	my_str_isalpha.c	\
	my_swap.c	\
	my_str_isprintable.c	\
	my_strcat.c	\
	my_strncat.c	\
	my_strcmp.c	\
	my_find_prime_sup.c	\
	my_put_nbr.c	\
	my_compute_factorial_rec.c	\
	my_compute_power_rec.c	\
	my_str_isnum.c	\
	alphanumeric.c	\
	my_evil_str.c	\
	my_revstr.c	\
	cpy_nospace.c	\
	my_strncmp.c	\
	my_is_prime.c	\
	my_strupcase.c	\
	my_showstr.c	\
	my_getnbr.c	\
	find_str.c	\
	find_bigger_smallest_str.c	\
	it_is_smthg.c	\
	my_strdup.c	\
	fct_eval_expr.c	\
	infinadd.c	\
	infinsub.c	\
	decrypt_encrypt_str.c	\
	infinsub2.c	\
	delete_add_min.c	\
	infinmult.c	\
	infinmult2.c	\
	infindiv.c	\
	free_print_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a *.o
	cp $(NAME) ../
	rm -f *.o

clean:
	rm -f *.o
	rm -f *~

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
