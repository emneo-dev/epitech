/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** Some desc
*/

int my_sort_int_array(int *array, int size)
{
    int tmp;
    int h = 1;

    for (int i = 0; h == 1; ++i) {
        h = 0;
        for (int z = 0; z < size - 1; z++) {
            if (array[z] > array[z + 1]) {
                tmp = array[z];
                array[z] = array[z + 1];
                array[z + 1] = tmp;
                h = 1;
            }
        }
    }
}
