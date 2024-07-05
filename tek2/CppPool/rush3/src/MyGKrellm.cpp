/*
** EPITECH PROJECT, 2021
** MYGKRELLM
** File description:
** MyGKrellm class
*/

#include <unistd.h>
#include <thread>

#include "TerminalMonitorDisplay.hpp"
#include "GraphicalMonitorDisplay.hpp"
#include "MyGKrellm.hpp"

MyGKrellm::MyGKrellm(DisplayType type, unsigned char tags)
{
    _type = type;
    if (_type == TERMINAL)
        _display = new TerminalMonitorDisplay(tags);
    else
        _display = new GraphicalMonitorDisplay(tags);
}

MyGKrellm::~MyGKrellm()
{
    delete _display;
}

int MyGKrellm::run()
{
    _display->update();
    auto update = [](IMonitorDisplay *display) {
        while (display->isOpen())
        {
            display->update();
            usleep(1000000);
        }
    };
    std::thread tUpdate(update, this->_display);
    while (_display->isOpen())
    {
        _display->updateEvent();
        _display->draw();
    }
    tUpdate.join();
    return EXIT_SUCCESS;
}