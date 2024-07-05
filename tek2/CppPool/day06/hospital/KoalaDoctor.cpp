/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** KoalaDoctor
*/

#include <iostream>
#include <fstream>

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->isWorking = false;
    this->say("I'm Dr." + this->name + "! How do you kreog?");
}

KoalaDoctor::~KoalaDoctor()
{
}

static const std::string DRUGS[5] = {
    "Mars",
    "Kinder",
    "Crunch",
    "Maroilles",
    "Eucalyptus leaf"
};

void KoalaDoctor::diagnose(SickKoala *patient)
{
    this->say("So what's goerking you Mr." + patient->getName() + "?");
    patient->poke();
    std::ofstream os(patient->name + ".report");
    os << DRUGS[random() % 5];
}

void KoalaDoctor::timeCheck()
{
    if (this->isWorking) {
        this->isWorking = false;
        this->say("Time to go to my eucalyptus forest!");
    }
    else {
        this->isWorking = true;
        this->say("Time to get to work!");
    }
}

void KoalaDoctor::say(std::string input)
{
    std::cout << "Dr." << this->name << ": " << input << std::endl;
}
