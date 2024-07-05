/*
** EPITECH PROJECT, 2021
** asm
** File description:
** libasm
*/

#ifndef LIBASM_H_
#define LIBASM_H_

#include <stddef.h>

size_t strlen(const char *s);
char *strchr(const char *s, int c);
void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
int strcmp(const char *s1, const char *s2);
void *memmove(void *dest, const void *src, size_t n);
int strncmp(const char *s1, const char *s2, size_t n);
int strcasecmp(const char *s1, const char *s2);
char *rindex(const char *s, int c);
char *strstr(const char *haystack, const char *needle);
char *strpbrk(const char *s, const char *accept);
size_t strcspn(const char *s, const char *reject);

#endif /* !LIBASM_H_ */
