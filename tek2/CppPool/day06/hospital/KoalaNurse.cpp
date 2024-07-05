/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** KoalaNurse
*/

#include <iostream>
#include <fstream>
#include <regex>

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int ID)
{
    this->ID = ID;
    this->isWorking = false;
}

KoalaNurse::~KoalaNurse()
{
    this->say("Finally some rest!");
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

void KoalaNurse::say(std::string input)
{
    std::cout << "Nurse " << this->ID << ": " << input << std::endl;
}

std::string KoalaNurse::readReport(std::string fileName)
{
    std::regex re(".report$");
    std::string name = std::regex_replace(fileName, re, "");
    if (name == fileName)
        return "";
    std::ifstream is(fileName);
    if (!is.is_open())
        return "";
    std::string drug;
    std::getline(is, drug);
    if (drug != "")
        this->say("Kreog! Mr." + name + " needs a " + drug + "!");
    return drug;
}

void KoalaNurse::timeCheck()
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