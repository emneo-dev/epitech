##
## EPITECH PROJECT, 2019
## Sample C Project
## File description:
## Makefile for Sample C Project
##

SHELL	=	bash

#-------------------------------------------------------------------------------

all: build_lib build ## Build the main binary with libs

build_lib: ## Compile the libs
	@$(MAKE) -C ./solver/ build_lib
	@$(MAKE) -C ./generator/ build_lib

build: $(OBJ) $(MAIN_OBJ) ## Build the main binary
	@$(MAKE) -C ./solver/ build
	@$(MAKE) -C ./generator/ build

clean_lib: ## Clean the libs
	@$(MAKE) -C ./solver/ clean_lib
	@$(MAKE) -C ./generator/ clean_lib

fclean_lib: ## Force clean the libs
	@$(MAKE) -C ./solver/ fclean_lib
	@$(MAKE) -C ./generator/ fclean_lib

clean: clean_lib ## Clean the project
	@$(MAKE) -C ./solver/ clean
	@$(MAKE) -C ./generator/ clean

fclean: fclean_lib clean ## Force clean the project
	@$(MAKE) -C ./solver/ fclean
	@$(MAKE) -C ./generator/ fclean

re:	fclean all ## Force clean then compile

tests_run: CFLAGS += --coverage ## Launch tests
tests_run: build_lib $(OBJ) $(TEST_OBJ)
	@$(MAKE) -C ./solver/ tests_run
	@$(MAKE) -C ./generator/ tests_run

re_tests: fclean tests_run ## Force clean then launch tests

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all tests_run re_tests help
