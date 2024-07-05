##
## EPITECH PROJECT, 2021
## B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
## File description:
## Makefile
##

SRC		:=	main.cpp		\

CXXFLAGS	:=	-W -Wall -Wextra

OBJ		:=	$(patsubst %.cpp,%.o,$(SRC))

TARGET	:=	my_convert_temp

all: $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all