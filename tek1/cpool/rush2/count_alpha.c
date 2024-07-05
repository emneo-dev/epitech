/*
** EPITECH PROJECT, 2019
** CPool_rush2_2019
** File description:
** count_alpha.c
*/

int *count_alpha (char *str, int *array)
{
    for (int i = 0; i < 26; ++i)
        array[i] = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((97 <= str[i]) && (str[i] <= 122)) {
            array[str[i] - 97] += 1;
        }
    }
    return (array);
}