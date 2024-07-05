/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include <stddef.h>
#include <sys/stat.h>
#include <elf.h>

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

int check_arch(file_t *file);
int load_file_in_memory(file_t *file, const char *filename, const char *call);
int objdump(int argc, char **argv);
void print_sections_64(const file_t *file, const char *filename,
    const char *call);
void print_start_64(const Elf64_Ehdr *header,
    const Elf64_Shdr *sections,
    const char *filename);
size_t get_size_max_addr(size_t i);
void print_sections_32(const file_t *file, const char *filename,
    const char *call);
void print_start_32(const Elf32_Ehdr *header,
    const Elf32_Shdr *sections,
    const char *filename);

#endif /* !OBJDUMP_H_ */
