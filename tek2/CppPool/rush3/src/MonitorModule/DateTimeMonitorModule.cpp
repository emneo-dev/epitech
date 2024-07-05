/*
** EPITECH PROJECT, 2020
** B-CPP-300-TLS-3-1-CPPrush3-pauline.faure
** File description:
** DateTimeMonitorModule.cpp
*/

#include <ctime>
#include <ncurses.h>
#include <string.h>
#include "DateTimeMonitorModule.hpp"

DateTimeMonitorModule::DateTimeMonitorModule()
{
}

DateTimeMonitorModule::DateTimeMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
}

DateTimeMonitorModule::~DateTimeMonitorModule()
{
}

void DateTimeMonitorModule::update()
{
    time_t now = time(0);
    _dateTime = ctime(&now);
}

void DateTimeMonitorModule::draw()
{
    char buff[1024];
    sprintf(buff,"Time: %s", _dateTime.c_str());
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY(), _infos.getX(), "%s", buff);
}

void DateTimeMonitorModule::draw(sf::RenderWindow &window)
{
    char buff[1024];
    sprintf(buff, "Time: %s", _dateTime.c_str());
    _label.setString(buff);
    _label.setCharacterSize(20);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 5));
    _label.setFillColor(sf::Color::White);
    window.draw(_label);
}