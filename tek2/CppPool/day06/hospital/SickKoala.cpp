/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** SickKoala
*/

#include <regex>

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    say("Kreooogg!! I'm cuuuured!");
}

void SickKoala::poke()
{
    say("Gooeeeeerrk!!");
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars")
        say("Mars, and it kreogs!");
    else if (drug == "Kinder")
        say("There is a toy inside!");
    else {
        say("Goerkreog!");
        return false;
    }
    return true;
}

void SickKoala::overDrive(std::string input)
{
    std::regex re("Kreog!");
    say(std::regex_replace(input, re, "1337!"));
}

std::string SickKoala::getName()
{
    return this->name;
}

void SickKoala::say(std::string input)
{
    std::cout << "Mr." << this->name << ": " << input << std::endl;
}