/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** koalatchi
*/

#include <stdint.h>
#include <stdio.h>

//-------------------------
// Actions
//-------------------------

static const uint32_t HEADER_ACTION_ID[16] = {
    0x01010001,
    0x01010002,
    0x01020001,
    0x01020002,
    0x01040001,
    0x01040002,
    0x02010001,
    0x02010002,
    0x02020001,
    0x02020002,
    0x02020003,
    0x02040001,
    0x04010001,
    0x04010002,
    0x04020001,
    0x04040001
};

static const char *HEADER_ACTION_STRING[16] = {
    "Eat",
    "Defecate",
    "Ball",
    "Bite",
    "TeachCoding",
    "BeAwesome",
    "Hungry",
    "Thirsty",
    "NeedAffection",
    "WannaPlay",
    "Hug",
    "FeelStupid",
    "Indigestion",
    "Starving",
    "Bored",
    "BrainDamage"
};

//-------------------------
// Domain
//-------------------------

static const uint32_t HEADER_DOMAIN_CLEAR = 0x00FF0000;

static const uint32_t HEADER_DOMAIN_ID[3] = {
    0x00010000,
    0x00020000,
    0x00040000
};

static const char *HEADER_DOMAIN_STRING[3] = {
    "Nutrition",
    "Entertainment",
    "Education"
};

//-------------------------
// Types
//-------------------------

static const uint32_t HEADER_TYPE_CLEAR = 0xFF000000;

static const uint32_t HEADER_TYPE_ID[3] = {
    0x01000000,
    0x02000000,
    0x04000000
};

static const char *HEADER_TYPE_STRING[3] = {
    "Notification",
    "Request",
    "Error"
};

static int is_valid_header(uint32_t header)
{
    for (int i = 0; i < 16; ++i)
        if (header == HEADER_ACTION_ID[i])
            return (1);
    return (0);
}

static void print_header(uint32_t header)
{
    for (int i = 0; i < 3; ++i)
        if (!((header & HEADER_TYPE_CLEAR) ^ HEADER_TYPE_ID[i]))
            printf("%s ", HEADER_TYPE_STRING[i]);
    for (int i = 0; i < 3; ++i)
        if (!((header & HEADER_DOMAIN_CLEAR) ^ HEADER_DOMAIN_ID[i]))
            printf("%s ", HEADER_DOMAIN_STRING[i]);
    for (int i = 0; i < 16; ++i)
        if (header == HEADER_ACTION_ID[i])
            printf("%s", HEADER_ACTION_STRING[i]);
}

int prettyprint_message(uint32_t header, const char *content)
{
    if (!is_valid_header(header)) {
        printf("Invalid message.\n");
        return (1);
    }
    print_header(header);
    if (!content)
        printf("\n");
    else
        printf(" %s\n", content);
    return (0);
}