/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** print_start_64
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flags.h"

#include "objdump.h"

static uint32_t get_flags_64(const Elf64_Ehdr *header,
    const Elf64_Shdr *sections)
{
    uint32_t flags = 0;

    if (header->e_type == ET_REL)
        flags |= HAS_RELOC;
    if (header->e_type == ET_EXEC)
        flags |= EXEC_P;
    if (header->e_type == ET_DYN)
        flags |= DYNAMIC;
    for (int i = 0; i < header->e_shnum; i++)
        if (sections[i].sh_type != SHT_SYMTAB ||
            sections[i].sh_type != SHT_DYNAMIC)
            flags |= HAS_SYMS;
    if (header->e_phnum != 0)
        flags |= D_PAGED;
    return flags;
}

static void append(char **string, const char *to_append)
{
    *string = realloc(*string, strlen(*string) + strlen(to_append) + 1);
    strcat(*string + strlen(*string), to_append);
}

static const char *flag_strings[] = {
    "HAS_RELOC",
    "EXEC_P",
    "HAS_SYMS",
    "HAS_DEBUG",
    "DYNAMIC",
    "D_PAGED",
    "HAS_LINENO",
    "HAS_LOCALS",
    "WP_TEXT"
};

static const uint32_t flags_value[] = {
    HAS_RELOC,
    EXEC_P,
    HAS_SYMS,
    HAS_DEBUG,
    DYNAMIC,
    D_PAGED,
    HAS_LINENO,
    HAS_LOCALS,
    WP_TEXT
};

static char *get_flag_string(uint32_t flags)
{
    char *string = malloc(sizeof(char));

    string[0] = '\0';
    for (size_t i = 0; i < 9; i++) {
        if (flags & flags_value[i] && !string[0])
            append(&string, flag_strings[i]);
        else if (flags & flags_value[i]) {
            append(&string, ", ");
            append(&string, flag_strings[i]);
        }
    }
    return string;
}

void print_start_64(const Elf64_Ehdr *header,
    const Elf64_Shdr *sections,
    const char *filename)
{
    const uint32_t flags = get_flags_64(header, sections);
    char *string_flags = get_flag_string(flags);

    printf("\n%s:     file format elf64-x86-64\n"
        "architecture: i386:x86-64, flags 0x%.8x:\n"
        "%s\n"
        "start address 0x%016x\n\n", filename, flags, string_flags,
        header->e_entry);
    free(string_flags);
}