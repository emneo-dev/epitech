/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compare two strings
*/

static int compute_diff_strcmp(char const s1, char const s2)
{
    return ((int) s1 - s2);
}

/*
*  Compare two strings
*  Return 0 if they are identical
*  Return the diff of the first different
*  character if they are not identical
*/
int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; ++i)
        if (s1[i] != s2[i])
            return (compute_diff_strcmp(s1[i], s2[i]));
    return (0);
}