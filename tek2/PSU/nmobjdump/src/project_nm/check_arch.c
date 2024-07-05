/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** check_arch
*/

#include <stddef.h>
#include <elf.h>

#include "nm.h"

static int is_valid_elf32(const Elf32_Ehdr *header)
{
    if (header->e_ident[EI_MAG0] == 0x7f &&
        header->e_ident[EI_MAG1] == 'E' &&
        header->e_ident[EI_MAG2] == 'L' &&
        header->e_ident[EI_MAG3] == 'F' &&
        header->e_ident[EI_CLASS] == 0x01)
        return 1;
    return 0;
}

static int is_valid_elf64(const Elf32_Ehdr *header)
{
    if (header->e_ident[EI_MAG0] == 0x7f &&
        header->e_ident[EI_MAG1] == 'E' &&
        header->e_ident[EI_MAG2] == 'L' &&
        header->e_ident[EI_MAG3] == 'F' &&
        header->e_ident[EI_CLASS] == 0x02)
        return 1;
    return 0;
}

int check_arch(file_t *file)
{
    const Elf32_Ehdr *header = file->buffer;

    if (!file || (size_t)file->s.st_size < sizeof(Elf32_Ehdr))
        return arch_error;
    if (is_valid_elf32(header))
        return arch_32;
    else if (is_valid_elf64(header))
        return arch_64;
    return arch_error;
}