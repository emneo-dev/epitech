##
## EPITECH PROJECT, 2021
## Santa
## File description:
## Makefile
##

SRC			:=	src/Wrap.cpp					\
				src/Toy.cpp						\
				src/Teddy.cpp					\
				src/PapaXmasConveyorBelt.cpp	\
				src/PapaXmasTable.cpp			\
				src/Object.cpp					\
				src/main.cpp					\
				src/LittlePoney.cpp				\
				src/GiftPaper.cpp				\
				src/Elf.cpp						\
				src/Box.cpp						\
				src/TableRand.cpp				\
				src/ConveyorBeltRand.cpp		\
				src/MyUnitTests.cpp				\

SRCSANTA	:=	santa_src/Santa.cpp				\

CXXFLAGS	:=	-std=c++14 -W -Wall -Wextra -I./include -g3

CXX			:=	g++

OBJ			:=	$(patsubst %.cpp,%.o,$(SRC))

OBJSANTA 	:=  $(patsubst %.cpp,%.o,$(SRCSANTA))

TARGET		:=	factory

TARGETSANTA := 	santa
all: $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(OBJSANTA)

fclean: clean
	rm -f $(TARGET)
	rm -f $(TARGETSANTA)

re: fclean
	$(MAKE) all

santa: $(OBJSANTA)
	$(CXX) -o $(TARGETSANTA) $(OBJSANTA)