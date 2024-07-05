/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** print_symbols_32
*/

#include <stddef.h>
#include <elf.h>
#include <stdio.h>
#include <string.h>

#include "nm.h"

static int get_symbol_section(const Elf32_Ehdr *header,
    const Elf32_Shdr *sections,
    sym_section_32_t *sym_section)
{
    for (size_t i = 0; i < header->e_shnum; i++)
        if (sections[i].sh_type == SHT_SYMTAB) {
            sym_section->symtab = (Elf32_Sym *)
                ((char *)header + sections[i].sh_offset);
            sym_section->size = sections[i].sh_size / sections[i].sh_entsize;
            sym_section->array =
                (char *)header + sections[sections[i].sh_link].sh_offset;
            return 0;
        }
    return -1;
}

void print_symbols_32(const file_t *file, const char *filename,
    const char *call)
{
    const Elf32_Ehdr *header = (Elf32_Ehdr *)file->buffer;
    const Elf32_Shdr *sections = (Elf32_Shdr *)
        ((char *)file->buffer + header->e_shoff);
    sym_section_32_t sym_section;

    if (get_symbol_section(header, sections, &sym_section)) {
        fprintf(stderr, "%s: %s: no symbols\n", call, filename);
        return;
    }
    for (size_t i = 0; i < sym_section.size; i++)
        print_symbol_32(&sym_section, sections, i);
}