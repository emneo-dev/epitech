SRC			=	src/memcpy.S			\
				src/memmove.S			\
				src/memset.S			\
				src/rindex.S			\
				src/strcasecmp.S		\
				src/strchr.S			\
				src/strcmp.S			\
				src/strcspn.S			\
				src/strlen.S			\
				src/strncmp.S			\
				src/strpbrk.S			\
				src/strstr.S			\

OBJ 		=	$(SRC:.S=.o)

LDFLAGS		=	-shared

CFLAGS		=	-I./include/ -W -Wall -Wextra

TEST_SRC	=	tests/tests_test.c		\

TEST_OBJ	=	$(TEST_SRC:.c=.o)

TEST_LFLAGS	=	-lcriterion

COVERAGE	=	$(SRC:.S=.gcda)			\
				$(SRC:.S=.gcno)			\
				$(TEST_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\

TARGET	=	libasm.so

TARGET_TEST	=	unit_tests