/*
** EPITECH PROJECT, 2019
** my_advanced_sort_word_array
** File description:
** Sort word in an array while using pointers on function
*/

//This function passes through the array and if 2 words are not in the good
//order it swaps them, while using pointer on a function.
//It does that while everything is not sorted
int my_advanced_sort_word_array(char **tab,
                                int (*cmp)(char const *, char const *))
{
    char *tmp;
    int h = 1;

    for (int i = 0; h == 1; ++i) {
        h = 0;
        for (int z = 0; tab[z + 1] != 0; z++) {
            if (cmp(tab[z], tab[z + 1]) > 0) {
                tmp = tab[z];
                tab[z] = tab[z + 1];
                tab[z + 1] = tmp;
                h = 1;
            }
        }
    }
    return (0);
}