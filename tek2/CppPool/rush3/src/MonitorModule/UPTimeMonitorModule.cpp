/*
** EPITECH PROJECT, 2020
** B-CPP-300-TLS-3-1-CPPrush3-pauline.faure
** File description:
** UPTimeMonitorModule.cpp
*/

#include <sys/sysinfo.h>
#include <iostream>
#include <ctime>
#include <string.h>
#include "UPTimeMonitorModule.hpp"

UPTimeMonitorModule::UPTimeMonitorModule()
{
}

UPTimeMonitorModule::UPTimeMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
}

UPTimeMonitorModule::~UPTimeMonitorModule()
{
}

void UPTimeMonitorModule::update()
{
    struct sysinfo info;
    sysinfo(&info);
    long time = info.uptime;

    _sec = time % 60;
    _min = time / 60 % 60;
    _hour = time / 3600 % 24;
    _day = time / (3600 * 24);
}

void UPTimeMonitorModule::draw()
{
    char buff[1024];
    if (_day > 100) {
        sprintf(buff,"Uptime: %d days(!), %02dh:%02dm:%02ds", _day, _hour, _min, _sec);
        if ((int)strlen(buff) < _infos.getWidth())
            mvprintw(_infos.getX(), _infos.getY(), "%s", buff);
    } else if (_day == 1) {
        sprintf(buff,"Uptime: %d day, %02dh:%02dm:%02ds", _day, _hour, _min, _sec);
        if ((int)strlen(buff) < _infos.getWidth())
            mvprintw(_infos.getX(), _infos.getY(), "%s", buff);
    } else if (_day > 1) {
        sprintf(buff, "Uptime: %d days, %02dh:%02dm:%02ds", _day, _hour, _min, _sec);
        if ((int)strlen(buff) < _infos.getWidth())
            mvprintw(_infos.getX(), _infos.getY(), "%s", buff);
    } else {
        sprintf(buff, "Uptime: %02dh:%02dm:%02ds", _hour, _min, _sec);
        if ((int)strlen(buff) < _infos.getWidth())
            mvprintw(_infos.getX(), _infos.getY(), "%s", buff);
    }
}

void UPTimeMonitorModule::draw(sf::RenderWindow &window)
{
    char buff[1024];
    sprintf(buff, "Uptime: %d day(s) %02dh:%02dm:%02ds", _day, _hour, _min, _sec);
    _label.setString(buff);
    _label.setCharacterSize(20);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 5));
    _label.setFillColor(sf::Color::White);
    window.draw(_label);
}