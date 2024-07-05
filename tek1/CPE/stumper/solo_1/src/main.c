/*
** EPITECH PROJECT, 2020
** CPE_solostumper_1_2019
** File description:
** main
*/

/*
* The only external include we need is
* for the write calls on line 26
*/
#include <unistd.h>
#include "hidenp.h"

/*
* Entry point for the hidenp
* project.
* It's handling the non conforming
* arguments and then calls the main function
* And I hope you won't be runnig
* seeing my very tiny code...
*/
int main(int argc, char **argv)
{
    if (argc != 3) {
        write(1, "Usage: ./hidenp needle haystack\n", 32);
        return (84);
    }
    return (find_needle(argv[1], argv[2]));
}
