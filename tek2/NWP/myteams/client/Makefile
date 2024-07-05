
##
## EPITECH PROJECT, 2021
## my_teams
## File description:
## Makefile
##

SRC					:=	src/client.c										\

OBJ 				:=	$(SRC:.c=.o)

CPPFLAGS			:=	-I./include/

TARGET				:=	myteams_cli

CFLAGS				:=	 -W -Wall -Wextra -Wpedantic \
    					-Wshadow -Wundef -Wuninitialized -Wmaybe-uninitialized -Wnonnull -Wnull-dereference \
    					-Wdouble-promotion -Wconversion -Wsign-conversion \
    					-Wshift-overflow=2 -Wformat=2 -Wformat-truncation -Wrestrict \
    					-Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wjump-misses-init \
    					-Wcast-align -Wcast-qual -Wreturn-type -Wsequence-point \
    					-Wstrict-aliasing=2 -Wframe-larger-than=32768 \
    					-Wsync-nand -Wtrampolines -Wenum-compare -Wsign-compare -Wfloat-equal -Wimplicit-int \
    					-Wparentheses -Wmissing-parameter-type -Wmissing-braces -Wpointer-sign \
    					-Wsuggest-final-types -Wsuggest-final-methods \
    					-Wempty-body -Wmain -Winit-self \
    					-Waggressive-loop-optimizations \
    					-Wwrite-strings -Waddress -Warray-bounds -Wchar-subscripts \
    					-Wvolatile-register-var -Wignored-qualifiers \
    					-Wodr -Wformat-signedness \
    					-fno-common -fno-builtin -O2 --param ssp-buffer-size=4

LDFLAGS				:=

#-------------------------------------------------------------------------------

all: $(TARGET)	## Builds the main binaries

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(TARGET)

clean:	## Cleans the project
	rm -f $(OBJ)

fclean: clean	## Force cleans the project
	rm -f $(TARGET)

re:	fclean	## Force cleans then compile
	$(MAKE) all

help:	## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean all help