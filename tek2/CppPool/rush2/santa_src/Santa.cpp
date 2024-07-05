/*
** EPITECH PROJECT, 2021
** Santa
** File description:
** Santa
*/

#include "Santa.hpp"

int printError(std::string error)
{
    std::cerr << error << std::endl;
    return (84);
}

int verifSanta(std::string gift)
{
    std::regex regexTeddy("Teddy");
    std::regex regexLittlePoney("LittlePoney");

    if (std::regex_search(gift, regexTeddy))
    {
        if (std::regex_search(gift, (std::regex)"<GiftPaper><Box><Teddy>") == false
            || std::regex_search(gift, (std::regex)"</Teddy></Box></GiftPaper>") == false)
            return (printError("The object has no Teddy..."));
    }
    else if (std::regex_search(gift, regexLittlePoney))
    {
        if (std::regex_search(gift, (std::regex)"<GiftPaper><Box><LittlePoney>") == false
            || std::regex_search(gift, (std::regex)"</LittlePoney></Box></GiftPaper>") == false)
            return (printError("The object has no LittlePoney..."));
    }
    else
        return (printError("The gift has no toy"));
    std::cout << "The gift is perfect !" << std::endl;
    return (0);
}

int main(int argc, char **argv)
{
    std::ifstream file;
    std::string fileString;

    for (int i = 1; i < argc; fileString = "", i++)
    {
        file.open(argv[i]);
        if (!file.is_open())
        {
            std::cerr << "The file : " << argv[i] << " is unreadable..." << std::endl;
            return (84);
        }
        for (std::string str; !file.eof(); )
        {
            getline(file, str);
            fileString += str;
        }
        file.close();
        if (verifSanta(fileString) == 84)
            return (84);
    }
    return (0);
}