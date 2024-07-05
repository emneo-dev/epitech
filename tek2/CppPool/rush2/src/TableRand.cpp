/*
** EPITECH PROJECT, 2021
** TableRand
** File description:
** TableRand
*/

#include <random>

#include "TableRand.hpp"
#include "Teddy.hpp"
#include "LittlePoney.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

static const char *TEDDY_NAMES[20] = {
    "Cuddles",
    "Snuggles",
    "Softy",
    "Cookie",
    "Charly",
    "Theo",
    "Honey",
    "Pooh",
    "Snugglebug",
    "Winnie",
    "Sunny",
    "Buttons",
    "Bubbles",
    "Elmar",
    "Paws",
    "Fluffles",
    "Barney",
    "Buddy",
    "Coco",
    "Eddy"
};

static const char *PONEY_NAMES[20] = {
    "Cookie",
    "Sadie",
    "Peony",
    "Sedona",
    "Britney",
    "Bonnie",
    "Suzy Q",
    "Laura",
    "Izzy",
    "Treasure",
    "Chanel",
    "Patsy",
    "Sebastian",
    "Chet",
    "Angus",
    "Khan",
    "Jake",
    "Fargo",
    "Darryl",
    "Tripper"
};

TableRand::TableRand()
{
    for (int i = 0; i < 10; i++)
    {
        switch (random() % 4)
        {
        case 0:
            this->_content[i] = new Teddy(TEDDY_NAMES[random() % 20]);
            break;
        case 1:
            this->_content[i] = new LittlePoney(PONEY_NAMES[random() % 20]);
            break;
        case 2:
            this->_content[i] = new GiftPaper();
            break;
        case 3:
            this->_content[i] = new Box();
            break;
        }
    }
    this->generateBuffer();
}

TableRand::~TableRand()
{
}