/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** bitmap_header
*/

#include <stddef.h>

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    header->magic = 0x4D42;
    header->size = sizeof(bmp_header_t) + sizeof(bmp_info_header_t)
            + size * size * 4;
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = sizeof(bmp_info_header_t) + sizeof(bmp_header_t);
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * 4 * size;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}
