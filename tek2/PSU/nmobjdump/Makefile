##
## EPITECH PROJECT, 2021
## nmobjdump
## File description:
## Makefile
##

## NM

NM_SRC				:=	src/project_nm/nm.c									\

NM_OBJ 				:=	$(NM_SRC:.c=.o)

NM_SRC				:=	src/project_nm/nm.c									\
						src/project_nm/check_arch.c							\
						src/project_nm/load_file_in_memory.c				\
						src/project_nm/print_symbols_64.c					\
						src/project_nm/print_symbol_64.c					\
						src/project_nm/print_symbols_32.c					\
						src/project_nm/print_symbol_32.c					\

NM_OBJ 				:=	$(NM_SRC:.c=.o)

NM_MAIN_SRC			:=	src/project_nm/main.c								\

NM_MAIN_OBJ			:=	$(NM_MAIN_SRC:.c=.o)

NM_CPPFLAGS			:=	-I./include/project_nm/

NM_TEST_SRC			:=	tests/project_nm/tests_nm.c							\

NM_TEST_OBJ			:=	$(NM_TEST_SRC:.c=.o)

NM_COVERAGE			:=	$(NM_SRC:.c=.gcda)									\
						$(NM_SRC:.c=.gcno)									\
						$(NM_TEST_SRC:.c=.gcno)								\
						$(NM_TEST_SRC:.c=.gcda)								\

NM_TARGET			:=	my_nm

NM_TARGET_TEST		:=	nm_unit_tests

## OBJDUMP

OBJDUMP_SRC			:=	src/project_objdump/objdump.c						\
						src/project_objdump/check_arch.c					\
						src/project_objdump/load_file_in_memory.c			\
						src/project_objdump/print_sections_64.c				\
						src/project_objdump/print_start_64.c				\
						src/project_objdump/get_size_max_addr.c				\
						src/project_objdump/print_sections_32.c				\
						src/project_objdump/print_start_32.c				\

OBJDUMP_OBJ 		:=	$(OBJDUMP_SRC:.c=.o)

OBJDUMP_MAIN_SRC	:=	src/project_objdump/main.c							\

OBJDUMP_MAIN_OBJ	:=	$(OBJDUMP_MAIN_SRC:.c=.o)

OBJDUMP_CPPFLAGS	:=	-I./include/project_objdump/

OBJDUMP_TEST_SRC	:=	tests/project_objdump/tests_objdump.c				\

OBJDUMP_TEST_OBJ	:=	$(OBJDUMP_TEST_SRC:.c=.o)

OBJDUMP_COVERAGE	:=	$(OBJDUMP_SRC:.c=.gcda)								\
						$(OBJDUMP_SRC:.c=.gcno)								\
						$(OBJDUMP_TEST_SRC:.c=.gcno)						\
						$(OBJDUMP_TEST_SRC:.c=.gcda)						\

OBJDUMP_TARGET		:=	my_objdump

OBJDUMP_TARGET_TEST	:=	objdump_unit_tests

## General

CPPFLAGS			:=

CFLAGS				:=	-Wall -Wextra -pedantic -fno-builtin

TEST_LFLAGS			:=	-lcriterion

LFLAGS				:=

#-------------------------------------------------------------------------------

all: nm objdump ## Build the main binaries

nm: $(NM_TARGET)

objdump: $(OBJDUMP_TARGET)

$(NM_TARGET): CPPFLAGS += $(NM_CPPFLAGS)
$(NM_TARGET): $(NM_OBJ) $(NM_MAIN_OBJ)
	$(CC) $(LFLAGS) $(NM_OBJ) $(NM_MAIN_OBJ) -o $(NM_TARGET)

$(OBJDUMP_TARGET): CPPFLAGS += $(OBJDUMP_CPPFLAGS)
$(OBJDUMP_TARGET): $(OBJDUMP_OBJ) $(OBJDUMP_MAIN_OBJ)
	$(CC) $(LFLAGS) $(OBJDUMP_OBJ) $(OBJDUMP_MAIN_OBJ) -o $(OBJDUMP_TARGET)

clean: ## Clean the project
	rm -f $(NM_OBJ) $(NM_COVERAGE) $(NM_TEST_OBJ) $(NM_MAIN_OBJ) $(OBJDUMP_OBJ) $(OBJDUMP_COVERAGE) $(OBJDUMP_TEST_OBJ) $(OBJDUMP_MAIN_OBJ)

fclean: clean ## Force clean the project
	rm -f $(NM_TARGET) $(NM_TARGET_TEST) $(OBJDUMP_TARGET) $(OBJDUMP_TARGET_TEST)

re:	fclean ## Force clean then compile
	$(MAKE) all

tests_run: nm_tests_run objdump_tests_run ## Launch tests

nm_tests_run: CFLAGS += --coverage ## Launch nm tests
nm_tests_run: CPPFLAGS += $(NM_CPPFLAGS)
nm_tests_run: $(NM_OBJ) $(NM_TEST_OBJ)
	$(CC) $(CFLAGS) $(NM_OBJ) $(NM_TEST_OBJ) -o $(NM_TARGET_TEST) $(TEST_LFLAGS)
	./$(NM_TARGET_TEST)

objdump_tests_run: CFLAGS += --coverage ## Launch objdump tests
objdump_tests_run: CPPFLAGS += $(OBJDUMP_CPPFLAGS)
objdump_tests_run: $(OBJDUMP_OBJ) $(OBJDUMP_TEST_OBJ)
	$(CC) $(CFLAGS) $(OBJDUMP_OBJ) $(OBJDUMP_TEST_OBJ) -o $(OBJDUMP_TARGET_TEST) $(TEST_LFLAGS)
	./$(OBJDUMP_TARGET_TEST)

re_tests: fclean ## Force clean then launch tests
	$(MAKE) tests_run

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean build all tests_run re_tests help