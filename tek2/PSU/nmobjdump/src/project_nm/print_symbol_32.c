/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** print_symbol_32
*/

#include <stddef.h>
#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "nm.h"

static int is_from_section(const sym_section_32_t *sym_section,
    const Elf32_Shdr *sections,
    const char *section_name)
{
    return (!strcmp(
        &(sym_section->array)[sections[sym_section->symtab->st_shndx].sh_name]
        , section_name));
}

static char get_type_sym_bis(const sym_section_32_t *sym_section,
    const Elf32_Shdr *sections,
    const Elf32_Sym *sym)
{
    if (sections[sym->st_shndx].sh_type == SHT_NOBITS
            && sections[sym->st_shndx].sh_flags & (SHF_ALLOC | SHF_WRITE))
        return 'B';
    else if (sections[sym->st_shndx].sh_flags & SHF_EXECINSTR)
        return 'T';
    else if (sections[sym->st_shndx].sh_flags & SHF_ALLOC &&
        !(sections[sym->st_shndx].sh_flags & SHF_WRITE))
        return 'R';
    else if ((sections[sym->st_shndx].sh_type == SHT_PROGBITS
            || is_from_section(sym_section, sections, ".data")
            || is_from_section(sym_section, sections, ".data1")
            || ELF32_ST_TYPE(sym->st_info) == STT_OBJECT
            || ELF32_ST_TYPE(sym->st_info) == STT_NOTYPE)
            && sections[sym->st_shndx].sh_flags & (SHF_ALLOC | SHF_WRITE))
        return 'D';
    return 'N';
}

static char get_type_sym(const sym_section_32_t *sym_section,
    const Elf32_Shdr *sections,
    size_t index)
{
    char c = '?';
    const Elf32_Sym *sym = &sym_section->symtab[index];

    if (ELF32_ST_BIND(sym->st_info) == STB_WEAK)
        return (sym->st_shndx == SHN_UNDEF) ? 'w' : 'W';
    else if (sym->st_shndx == SHN_UNDEF)
        c = 'U';
    else if (sym->st_shndx == SHN_ABS)
        c = 'A';
    else if (sym->st_shndx == SHN_COMMON)
        c = 'C';
    else
        c = get_type_sym_bis(sym_section, sections, sym);
    if (ELF32_ST_BIND(sym->st_info) == STB_LOCAL && c != '?' && c != 'd'
        && c != 'N')
        c = tolower(c);
    return c;
}

void print_symbol_32(const sym_section_32_t *sym_section,
    const Elf32_Shdr *sections,
    size_t index)
{
    if (sym_section->symtab[index].st_info != STT_FILE &&
        sym_section->symtab[index].st_name != 0) {
        char type = get_type_sym(sym_section, sections, index);
        if (sym_section->symtab[index].st_value != 0 ||
            type == 't' || type == 'T')
            printf("%08x %c %s\n",
                sym_section->symtab[index].st_value,
                type,
                &sym_section->array[sym_section->symtab[index].st_name]);
        else
            printf("         %c %s\n",
                type,
                &sym_section->array[sym_section->symtab[index].st_name]);
    }
}