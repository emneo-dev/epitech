/*
** EPITECH PROJECT, 2019
** CPool_finalstumper_2019
** File description:
** Get the exercice from the rush1 using the given buffer in parameter
*/

#include <rush3.h>
#include <my.h>

static int get_ex_3_to_5(char *buff);

int get_ex(char *buff)
{
    if (buff[0] == 'o')
        if (is_first(buff))
            return (1);
    if (buff[0] == '/' || buff[0] == '*') {
        if (is_second(buff))
            return (2);
        if (is_just_star(buff))
            return (2);
    }
    return (get_ex_3_to_5(buff));
}

static int get_ex_3_to_5(char *buff)
{
    if (((get_length(buff))[0] == 1 || (get_length(buff))[1] == 1)
        && buff[0] == 'B')
        if (is_just_b(buff))
            return (6);
    if (buff[(get_length(buff))[0] - 1] == 'A')
        if (is_third(buff))
            return (3);
    if (buff[my_strlen(buff) - 2] == 'A')
        if (is_fifth(buff))
            return (5);
    if (buff[my_strlen(buff) - 2] == 'C')
        if (is_fourth(buff))
            return (4);
    return (84);
}
