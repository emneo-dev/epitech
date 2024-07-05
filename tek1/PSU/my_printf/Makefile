##
## EPITECH PROJECT, 2019
## libmy
## File description:
## The Makefile for libmy
##

CC		=	gcc

SRC 	=	src/concat_params.c	\
		src/my_compute_power_rec.c	\
		src/my_compute_square_root.c	\
		src/my_find_prime_sup.c	\
		src/my_getnbr.c	\
		src/my_is_prime.c	\
		src/my_isneg.c	\
		src/my_put_nbr.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_revstr.c	\
		src/my_show_word_array.c	\
		src/my_showmem.c	\
		src/my_showstr.c	\
		src/my_sort_int_array.c	\
		src/my_str_isalpha.c	\
		src/my_str_islower.c	\
		src/my_str_isnum.c	\
		src/my_str_isprintable.c	\
		src/my_str_isupper.c	\
		src/my_str_to_word_array.c	\
		src/my_strcapitalize.c	\
		src/my_strcat.c	\
		src/my_strcmp.c	\
		src/my_strcpy.c	\
		src/my_strdup.c	\
		src/my_strlen.c	\
		src/my_strlowcase.c \
		src/my_strncat.c	\
		src/my_strncmp.c	\
		src/my_strncpy.c	\
		src/my_strstr.c	\
		src/my_strupcase.c	\
		src/my_swap.c	\
		src/sum_stdarg.c	\
		src/disp_stdarg.c	\
		src/my_printf.c	\
		src/my_printf_su.c	\
		src/my_printf_i.c	\
		src/my_printf_perc.c	\
		src/my_printf_s.c	\
		src/my_printf_p.c	\
		src/my_printf_c.c	\
		src/my_printf_o.c	\
		src/my_printf_b.c	\
		src/my_printf_u.c	\
		src/my_printf_xu.c 	\
		src/my_printf_xl.c 	\
		src/my_printf_m.c 	\

TEST_SRC	=	tests/test_my_printf.c	\

OBJ 	=	$(SRC:.c=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -pedantic -fno-builtin -Werror

TEST_CFLAGS	=	-lcriterion

LIB_FLAGS	=	-L. -lmy

TARGET	=	libmy.a

TARGET_TEST	=	unit_tests

all:	$(TARGET)

$(TARGET): $(OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@ar rc libmy.a $(OBJ)
	@printf "[\e[1;33mLinked\e[0m] % 33s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 31s\n" $< | tr ' ' '.'

clean:
	@rm -f $(OBJ) $(TEST_OBJ)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

tests_run: all
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) -o $(TARGET_TEST) $(TEST_SRC) $(LIB_FLAGS)
	@printf "[\e[1;34mCompiled\e[0m] % 31s\n" $(TEST_SRC) | tr ' ' '.'
	@printf "\e[1;32mFinished compiling tests...\e[0m\n"
	@printf "\e[1;32mLaunching tests...\e[0m\n"
	@./unit_tests

fclean: clean
	@rm -f $(TARGET) $(TARGET_TEST)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(TARGET_TEST) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all

re_tests: re tests_run
