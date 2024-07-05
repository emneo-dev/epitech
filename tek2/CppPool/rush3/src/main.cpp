/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Main function
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "MyGKrellm.hpp"
#include "IMonitorDisplay.hpp"

void print_help()
{
    std::cout << "./MyGKrellm -t\t\t-> terminal" << std::endl;
    std::cout << "./MyGKrellm -g\t\t-> graphical" << std::endl << std::endl;
    std::cout << "To manage modules at launch time use -key" << std::endl;
    std::cout << "  -c   :   CPU Module" << std::endl;
    std::cout << "  -k   :   CPU Core Module" << std::endl;
    std::cout << "  -r   :   RAM Module" << std::endl;
    std::cout << "  -n   :   Network Module" << std::endl;
    std::cout << "  -i   :   Info Module" << std::endl << std::endl;
    std::cout << "Examples:" << std::endl << std::endl;
    std::cout << "./MyGKrellm -g -c -k    -> graphical + CPU and CPU Core modules" << std::endl;
    std::cout << "./MyGKrellm -gi         -> graphical + INFO module and all INFO sub modules" << std::endl << std::endl;
    std::cout << "Press the key to show or hide module at runtime:" << std::endl;
    std::cout << "  Q   :   Quit" << std::endl;
    std::cout << "  C   :   CPU Module" << std::endl;
    std::cout << "  K   :   CPU Core Module" << std::endl;
    std::cout << "  R   :   RAM Module" << std::endl;
    std::cout << "  N   :   Network Module" << std::endl;
    std::cout << "  I   :   Info Module" << std::endl;
    std::cout << "    H   :   HostName Module" << std::endl;
    std::cout << "    U   :   Up time Module" << std::endl;
    std::cout << "    D   :   Date Time Module" << std::endl;
    std::cout << "    O   :   OS Module" << std::endl;
}

int main(int argc, char *const *argv)
{
    MyGKrellm::DisplayType type = MyGKrellm::UNKNOWN;
    unsigned char tags = 0;

    char c;
    while ((c = getopt(argc, argv, "tgckrni")) != -1)
        switch (c)
        {
        case 't':
            type = MyGKrellm::TERMINAL;
            break;
        case 'g':
            type = MyGKrellm::GRAPHICAL;
            break;
        case 'c':
            tags |= 0b1 << (int)IMonitorDisplay::CPU_MODULE;
            break;
        case 'k':
            tags |= 0b1 << (int)IMonitorDisplay::CPU_CORE_MODULE;
            break;
        case 'r':
            tags |= 0b1 << (int)IMonitorDisplay::RAM_MODULE;
            break;
        case 'n':
            tags |= 0b1 << (int)IMonitorDisplay::NETWORK_MODULE;
            break;
        case 'i':
            tags |= 0b1 << (int)IMonitorDisplay::INFO_MODULE;
            break;
        case '?':
            print_help();
            return EXIT_SUCCESS;
        default:
            abort();
        }
    if (type == MyGKrellm::UNKNOWN)
    {
        print_help();
        return EXIT_FAILURE;
    }
    if (tags == 0)
        tags = 0b11111111;
    MyGKrellm myGKrellm(type, tags);
    if (myGKrellm.run())
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}