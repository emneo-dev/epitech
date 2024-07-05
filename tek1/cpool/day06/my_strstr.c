/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Some desc
*/

int my_strncmp(char const *s1, char const *s2, int n);

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(str + i, to_find, my_strlen(to_find)) == 0)
            return (str + i);
    }
    return (0);
}
