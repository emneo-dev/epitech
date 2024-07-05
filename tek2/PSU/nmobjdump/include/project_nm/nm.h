/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

#include <stddef.h>
#include <elf.h>
#include <sys/stat.h>

enum arch_e {
    arch_32,
    arch_64,
    arch_error
};

typedef struct file_s {
    void *buffer;
    struct stat s;
} file_t;

typedef struct sym_section_64_s {
    Elf64_Sym *symtab;
    size_t size;
    char *array;
} sym_section_64_t;

typedef struct sym_section_32_s {
    Elf32_Sym *symtab;
    size_t size;
    char *array;
} sym_section_32_t;

void print_symbol_64(const sym_section_64_t *sym_section,
    const Elf64_Shdr *sections,
    size_t index);
void print_symbols_64(const file_t *file, const char *filename,
    const char *call);
void print_symbol_32(const sym_section_32_t *sym_section,
    const Elf32_Shdr *sections,
    size_t index);
void print_symbols_32(const file_t *file, const char *filename,
    const char *call);
int check_arch(file_t *file);
int nm(int argc, char **argv);
int load_file_in_memory(file_t *file, const char *filename, const char *call);

#endif /* !NM_H_ */
