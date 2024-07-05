/*
** EPITECH PROJECT, 2021
** htop
** File description:
** HostnameUsernameMonitorModule
*/

#include <unistd.h>
#include <ncurses.h>
#include <string.h>

#include "HostnameUsernameMonitorModule.hpp"

HostnameUsernameMonitorModule::HostnameUsernameMonitorModule()
{
}

HostnameUsernameMonitorModule::HostnameUsernameMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
}

HostnameUsernameMonitorModule::~HostnameUsernameMonitorModule()
{
}

void HostnameUsernameMonitorModule::update()
{
    char usernameBuffer[2048] = {0};
    char hostnameBuffer[2048] = {0};
    getlogin_r(usernameBuffer, 2048);
    gethostname(hostnameBuffer, 2048);
    _data = std::string(usernameBuffer) + "@" + std::string(hostnameBuffer);
}

void HostnameUsernameMonitorModule::draw()
{
    char buff[1024];
    sprintf(buff, "Name: %s", _data.c_str());
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY(),_infos.getX(), "%s", buff);
}

void HostnameUsernameMonitorModule::draw(sf::RenderWindow &window)
{
    char buff[1024];
    sprintf(buff, "Name: %s", _data.c_str());
    _label.setString(buff);
    _label.setCharacterSize(20);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 5));
    _label.setFillColor(sf::Color::White);
    window.draw(_label);
}