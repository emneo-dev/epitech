/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include <iostream>
#include <unistd.h>
#include "LibraryHandler.hpp"
#include "MainMenu.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 2) {
        std::cerr << "Error: too many or too few arguments" << std::endl;
        return 84;
    }
    
    std::unique_ptr<arcade::lib::LibHandler> lib;
    try {
        lib = std::make_unique<arcade::lib::LibHandler>(std::string(av[1]));
        if (lib->getInfo().type == library_info::GAME)
            throw std::runtime_error("Given library is not a graphic library");
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught during library loading :" << std::endl;
        std::cerr << e.what() << std::endl;
        return 84;
    }

    arcade::MainMenu menu(std::move(lib));
    try {
        menu.run();
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught during runtime :" << std::endl;
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}