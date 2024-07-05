/*
** EPITECH PROJECT, 2021
** htop
** File description:
** OSNameKernelVersionMonitorModule
*/

#include <sys/utsname.h>
#include <iostream>
#include <ncurses.h>
#include <string.h>
#include "OSNameKernelVersionMonitorModule.hpp"

OSNameKernelVersionMonitorModule::OSNameKernelVersionMonitorModule()
{
}

OSNameKernelVersionMonitorModule::OSNameKernelVersionMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
}

OSNameKernelVersionMonitorModule::~OSNameKernelVersionMonitorModule()
{
}

void OSNameKernelVersionMonitorModule::update()
{
    struct utsname ver;
    uname(&ver);
    _data = std::string(ver.sysname) + " " + std::string(ver.release);
}

void OSNameKernelVersionMonitorModule::draw()
{
    char buff[1024];
    sprintf(buff, "OS: %s", _data.c_str());
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY(),_infos.getX(), "%s", buff);
}

void OSNameKernelVersionMonitorModule::draw(sf::RenderWindow &window)
{
    char buff[1024];
    sprintf(buff, "OS: %s", _data.c_str());
    _label.setString(buff);
    _label.setCharacterSize(20);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 5));
    _label.setFillColor(sf::Color::White);
    window.draw(_label);
}