/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
** Some desc
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    int half_len;
    int i;
    char c;

    half_len = ((len % 2 == 0) ? len / 2 : len / 2 + 0.5);
    for (i = 0; i <= half_len - 1; i++) {
        c = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = c;
    }
    return (str);
}
