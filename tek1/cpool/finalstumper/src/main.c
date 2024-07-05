/*
** EPITECH PROJECT, 2019
** CPool_finalstumper_2019
** File description:
** Main file for the finalstumper project
*/

#include <unistd.h>
#include <rush3.h>

int main(void)
{
    char buff[10000];
    int offset = 0;
    int len;

    len = read(0, buff + offset, 10000 - offset);
    if (len < 0)
        return (84);
    while (len > 0){
        offset = offset + len;
        len = read(0, buff + offset, 10000 - offset);
    }
    buff[offset] = '\0';
    return (rush3(buff));
}
