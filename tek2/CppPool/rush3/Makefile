##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## My makefile
##

# ========================= VAR ========================= #

NAME = MyGKrellm

MAIN_SRC = src/main.cpp

SRC = $(shell find src/ -name "*.cpp" ! -name "main.cpp")

TEST_NAME = unit_tests

TESTS_SRC = $(shell find tests/ -name "*.cpp")

CXXFLAGS = -W -Wall -Wextra

IFLAGS = $(addprefix -I, $(shell find include/ -type d))

LFLAGS = -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lpthread -lm

TESTS_FLAGS = -lcriterion --coverage

OTHER_FLAGS =

# ======================================================= #

## echo
ECHO = echo -e

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
WARN_COLOR = \x1b[33;01m

OK_STRING = $(OK_COLOR)[✔]$(NO_COLOR)
ERROR_STRING = $(ERROR_COLOR)[X]$(NO_COLOR)
WARN_STRING = $(WARN_COLOR)[!]$(NO_COLOR)

## shell
CXX = g++ -fdiagnostics-color=always
RM = rm -f

## obj
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
OBJ = $(SRC:.cpp=.o)
TESTS_OBJ = $(TESTS_SRC:.cpp=.o)

## flag
LFLAGS := $(LFLAGS) $(addprefix -L. , $(TMP_LFLAGS))

## tests
TEST_BUILD = *.gcno *.gcda

## build
BUILD_WARN_LOG = build_warn.log
BUILD_ERROR_LOG = build_error.log
LOGS = $(BUILD_WARN_LOG) $(BUILD_ERROR_LOG)

## rules
all: $(NAME)

%.o: %.cpp
	@$(RM)  $@
	@$(ECHO) "$(OK_STRING) $<"
	@$(CXX) $(CXXFLAGS) $(IFLAGS) $(OTHER_FLAGS) -c $< -o $@ 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(MAKE) -s check_error

check_error:
	@if [ -e $(BUILD_ERROR_LOG) ] && [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(ERROR_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(RM) $(BUILD_ERROR_LOG); \
	elif [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(WARN_STRING) "; \
		cat $(BUILD_WARN_LOG); \
	fi

$(NAME): $(MAIN_OBJ) $(OBJ)
	@$(CXX) $(CXXFLAGS) $(IFLAGS) $(OTHER_FLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LFLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)

clean:
	@$(RM) $(MAIN_OBJ) $(OBJ) $(TESTS_OBJ)
	@$(RM) $(LOGS)
	@$(RM) $(TEST_BUILD) vgcore.*
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

fclean:
	@$(MAKE) clean > /dev/null
	@$(RM) $(NAME) $(TEST_NAME)
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

re: fclean all

tests_run: $(OBJ) $(TESTS_OBJ)
	@$(RM) $(TEST_BUILD) $(TEST_NAME)
	@$(CXX) $(CXXFLAGS) $(IFLAGS) $(OTHER_FLAGS) -o $(TEST_NAME) $(OBJ) $(TESTS_OBJ) $(LFLAGS) $(TESTS_FLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)
	@./$(TEST_NAME)

coverage: $(TESTS_OBJ)
	@$(CXX) $(CXXFLAGS) $(IFLAGS) $(OTHER_FLAGS) -o $(TEST_NAME) $(SRC) $(TESTS_OBJ) $(LFLAGS) $(TESTS_FLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)
	@./$(TEST_NAME)
	gcovr --exclude tests/

debug: $(MAIN_OBJ) $(OBJ)
	@$(CXX) -g3 $(CXXFLAGS) $(IFLAGS) $(OTHER_FLAGS) -o $(NAME) $(MAIN_SRC) $(SRC) $(LFLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)

define print_build_status
	@if [ -e $(BUILD_ERROR_LOG) ] && [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(ERROR_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(ECHO) "$(ERROR_STRING) $(NAME) -> $1"; \
		$(RM) $(BUILD_ERROR_LOG); \
	elif [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(WARN_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(ECHO) "$(WARN_STRING) $(NAME) -> $1"; \
	else \
		$(ECHO) "$(OK_STRING) $(NAME) -> $1"; \
	fi
endef

.PHONY: $(NAME) all clean fclean re tests_run coverage debug