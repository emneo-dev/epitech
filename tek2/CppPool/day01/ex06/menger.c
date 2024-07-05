/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** menger
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "bitmap.h"
#include "drawing.h"

static uint32_t calculate_color(const point_t *lvl)
{
    uint32_t color = 0;

    for (int i = 0; i < 3; i++) {
        color <<= 8;
        color += 255 / lvl->x;
    }
    return (color);
}

static void print_hole(int size, point_t *pos, uint32_t **buffer, point_t *lvl)
{
    draw_square(buffer, pos, (size_t) size, calculate_color(lvl));
}

void menger(int size, point_t *lvl, point_t *pos, uint32_t **buffer)
{
    if (!lvl->x)
        return;
    size /= 3;
    lvl->y++;
    print_hole(size, &(point_t) {size + pos->x, size + pos->y}, buffer, lvl);
    lvl->x--;
    menger(size, lvl, &(point_t) {pos->x, pos->y}, buffer);
    menger(size, lvl, &(point_t) {pos->x, pos->y + size}, buffer);
    menger(size, lvl, &(point_t) {pos->x, pos->y + size * 2}, buffer);
    menger(size, lvl, &(point_t) {pos->x + size, pos->y}, buffer);
    menger(size, lvl, &(point_t) {pos->x + size, pos->y + size * 2}, buffer);
    menger(size, lvl, &(point_t) {pos->x + size * 2, pos->y}, buffer);
    menger(size, lvl, &(point_t) {pos->x + size * 2, pos->y + size}, buffer);
    menger(size, lvl, &(point_t) {pos->x + size * 2, pos->y + size * 2},
        buffer);
    lvl->x++;
    lvl->y--;
}

static void initialize_image(size_t size, unsigned int *buffer,
    unsigned int **img, int fd)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; ++i)
        img[i] = buffer + i * size;
    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
}

int main(int argc, char **argv)
{
    size_t size = 0;
    int fd = 0;
    unsigned int *buffer = NULL;
    unsigned int **img = NULL;

    if (argc != 4) {
        fprintf(stderr, "menger_face file_name size level\n");
        return (84);
    }
    size = atoi(argv[2]);
    fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    buffer = malloc(size * size * sizeof(*buffer));
    img = malloc(size * sizeof(*img));
    initialize_image(size, buffer, img, fd);
    draw_square(img, &(point_t) {0, 0}, size, 0x00000000);
    menger(size, &(point_t) {atoi(argv[3]), 0}, &(point_t) {0, 0}, img);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
    return (EXIT_SUCCESS);
}