/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** print_sections_32
*/

#include <stdio.h>

#include "objdump.h"

static int is_section_to_print(const Elf32_Shdr *section)
{
    return section->sh_type != SHT_NOBITS && section->sh_name
        && section->sh_size > 0 && (section->sh_addr || (!section->sh_addr
        && section->sh_type != SHT_STRTAB && section->sh_type != SHT_RELA
        && section->sh_type != SHT_REL && section->sh_type != SHT_SYMTAB));
}

static void print_str(const Elf32_Shdr *section,
    const unsigned char *str,
    size_t i)
{
    for (size_t j = 0; j < 16; j++) {
        if (i + j < section->sh_size)
            (str[i + j] >= 32 && str[i + j] < 127) ? printf("%c", str[i + j])
                : printf(".");
        else
            printf(" ");
    }
}

static void print_hexa(const Elf32_Shdr *section,
    const unsigned char *str,
    size_t i)
{
    for (size_t j = 0; j < 16; j++) {
        if (i + j < section->sh_size)
            printf("%02x", str[i + j]);
        else
            printf("  ");
        if (j % 4 == 3)
            printf(" ");
    }
}

static void print_section(const void *buffer,
    const Elf32_Shdr *section)
{
    const unsigned char *str = (unsigned char *)buffer + section->sh_offset;

    for (size_t i = 0; i < section->sh_size; i += 16) {
        printf(" %0*x ", get_size_max_addr(i + section->sh_size),
            section->sh_addr + i);
        print_hexa(section, str, i);
        printf(" ");
        print_str(section, str, i);
        printf("\n");
    }
}

void print_sections_32(const file_t *file, const char *filename,
    const char *call)
{
    const Elf32_Ehdr *header = (Elf32_Ehdr *)file->buffer;
    const Elf32_Shdr *sections = (Elf32_Shdr *)
        ((char *)file->buffer + header->e_shoff);
    const char *str_array =
        (char *)header + sections[header->e_shstrndx].sh_offset;

    print_start_32(header, sections, filename);
    for (size_t i = 0; i < header->e_shnum; i++) {
        if (is_section_to_print(&sections[i])) {
            printf("Contents of section %s:\n",
                &str_array[sections[i].sh_name]);
            print_section(file->buffer, &sections[i]);
        }
    }
}