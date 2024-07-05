/*
** EPITECH PROJECT, 2019
** match
** File description:
** Main file for the second exercice
*/

//This function uses recurtion to work, and tries every combinations
//possible to test the match statement. That's basically bruteforce uwu
int nmatch(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    else if (*s1 == *s2)
        return (nmatch(s1 + 1, s2 + 1));
    else if (*s2 == '*') {
        if (*s1 != '\0')
            return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
        else
            return (nmatch(s1, s2 + 1));
    }
    else
        return (0);
}
