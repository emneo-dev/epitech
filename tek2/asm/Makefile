##
## EPITECH PROJECT, 2021
## asm
## File description:
## Makefile
##

include config.mk

#-------------------------------------------------------------------------------

all:	$(TARGET) ## Build the main binary

$(TARGET): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(TARGET)

%.o : %.S ## Compile the objects
	nasm -f elf64 -g $< -o $@

clean: ## Clean the project
	rm -f $(OBJ) $(COVERAGE) $(TEST_OBJ)

fclean: clean ## Force clean the project
	rm -f $(TARGET) $(TARGET_TEST)

re:	fclean ## Force clean then compile
	$(MAKE) all

tests_run: CFLAGS += --coverage ## Launch tests
tests_run: all $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TARGET_TEST) $(TEST_LFLAGS)
	./$(TARGET_TEST)
	LD_PRELOAD=./$(TARGET) ./$(TARGET_TEST)

re_tests: fclean ## Force clean then launch tests
	$(MAKE) tests_run

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean build all tests_run re_tests help valgrind