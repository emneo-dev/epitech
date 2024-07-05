/*
** EPITECH PROJECT, 2019
** get_color
** File description:
** Some desc
*/

struct colors
{
    char a;
    char r;
    char g;
    char b;
};

union Data {
    struct colors tab;
    int ucolor;
};

int swap_endian_color(int color)
{
    union Data data;
    int tmp;

    data.ucolor = color;
    tmp = data.tab.a;
    data.tab.a = data.tab.b;
    data.tab.b = tmp;
    tmp = data.tab.r;
    data.tab.r = data.tab.g;
    data.tab.g = tmp;
    return (data.ucolor);
}