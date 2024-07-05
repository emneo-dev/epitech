/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_persons
*/

#include "talk/structs.h"
#include "res.h"
#include "utility.h"

void second_person_init(talk_t *talk, person_t *person)
{
    if (person->name)
        talk->right_name = create_text(person->name, 10, talk->font, sfRed);
    if (person->sprite_path) {
        talk->right_sprite = sfTexture_createFromFile(person->sprite_path,
                                                      NULL);
        if (!talk->right_sprite)
            my_putwarn("Could not create sprite!\n");
    }
}

void first_person_init(talk_t *talk, person_t *person)
{
    if (person->name)
        talk->left_name = create_text(person->name, 10, talk->font, sfRed);
    if (person->sprite_path) {
        talk->left_sprite = sfTexture_createFromFile(person->sprite_path, NULL);
        if (!talk->left_sprite)
            my_putwarn("Could not create sprite!\n");
    }
}