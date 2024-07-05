/*
** EPITECH PROJECT, 2020
** CPE_solostumper_1_2019
** File description:
** find_needle
*/

#include <unistd.h>

/*
* Main function for the current
* project.
* It always returns 0, no matter what.
* Usage:
*    find_needle(char *word_to_find, char *to_search_in);
* 
* I could be doing Doxygen but i'm
* way too lazy to do so...
*/
int find_needle(char *needle, char *hay)
{
    int i = 0;

    for (int z = 0; hay[z]; z++)
        if(hay[z] == needle[i])
            i++;
    if (needle[i])
        write(1, "0\n", 2);
    else
        write(1, "1\n", 2);
    return (0);
}
