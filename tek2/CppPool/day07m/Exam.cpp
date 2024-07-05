/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** Exam
*/

#include <iostream>

#include "Exam.hpp"

Exam::Exam(bool *cheat)
{
    myCheat = cheat;
}

void Exam::start(int enemies)
{
    std::cout << "[The exam is starting]" << std::endl <<
    enemies << " Klingon vessels appeared out of nowhere." << std::endl <<
    "they are fully armed and shielded" << std::endl;
    if (*(this->myCheat))
        std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
    else
        std::cout << "This exam is hard... you lost again." << std::endl;
}

bool Exam::isCheating()
{
    return *(this->myCheat);
}

bool Exam::cheat;