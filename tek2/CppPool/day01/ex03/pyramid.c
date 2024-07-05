/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** pyramid
*/

static int search_path(int size, int **map, int x, int y)
{
    int left = 0;
    int right = 0;

    if (y == size - 1)
        return (map[y][x]);
    left = search_path(size, map, x, y + 1);
    right = search_path(size, map, x + 1, y + 1);
    return (map[y][x] + ((left < right) ? left : right));
}

int pyramid_path(int size, int **map)
{
    return (search_path(size, map, 0, 0));
}
