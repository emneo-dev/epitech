/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Compare two strings
*/

int compute_diff_strncmp(char const s1, char const s2);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while ((s1[i] != '\0' || s2[i] != '\0') && i < n) {
        if (s1[i] != s2[i])
            return (compute_diff_strncmp(s1[i], s2[i]));
        i++;
    }
    return (0);
}

int compute_diff_strncmp(char const s1, char const s2)
{
    return ((int) s1 - s2);
}
