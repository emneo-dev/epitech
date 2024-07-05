/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** main
*/

#include <iostream>
#include <fstream>

static int displayNotEnoughArgs(void)
{
    std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return displayNotEnoughArgs();

    for (int i = 1; i < argc; i++) {
        std::ifstream myFile(argv[i], std::ios::in);
        std::string buffer;
        if (myFile.is_open()) {
            std::cout << myFile.rdbuf();
            myFile.close();
        }
        else
            std::cerr << "my_cat: " << argv[i] <<": No such file or directory" << std::endl;
    }
    return 0;
}