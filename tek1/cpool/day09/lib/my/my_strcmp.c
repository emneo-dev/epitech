/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compare two strings
*/

static int compute_diff_strcmp(char const s1, char const s2);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (compute_diff_strcmp(s1[i], s2[i]));
        i++;
    }
    return (0);
}

static int compute_diff_strcmp(char const s1, char const s2)
{
    return ((int) s1 - s2);
}
