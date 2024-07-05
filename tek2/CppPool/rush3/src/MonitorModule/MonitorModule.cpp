/*
** EPITECH PROJECT, 2021
** MONITORMODULE
** File description:
** MonitorModule class
*/

#include <iostream>
#include "MonitorModule.hpp"

MonitorModule::MonitorModule()
{
    _infos = DrawInfo();
    _enable = true;
    _nbPlotPerInterval = 60;

    if (!_font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Cannot load font" << std::endl;
        abort();
    }
    _label.setFont(_font);
}

MonitorModule::MonitorModule(const DrawInfo &infos)
{
    _infos = infos;
    _enable = true;
    _nbPlotPerInterval = 60;

    if (!_font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Cannot load font" << std::endl;
        abort();
    }
    _label.setFont(_font);
}

MonitorModule::~MonitorModule()
{
}

void MonitorModule::draw()
{
}

void MonitorModule::draw(sf::RenderWindow &window)
{
    GraphicalHelper::DrawContainer(window, _infos, sf::Color::White, sf::Color::Black);
}

void MonitorModule::setDrawInfo(const DrawInfo &infos)
{
    _infos = infos;
}

DrawInfo MonitorModule::getDrawInfo() const
{
    return _infos;
}

bool MonitorModule::isEnabled() const
{
    return _enable;
}

void MonitorModule::enable()
{
    _enable = true;
}

void MonitorModule::disable()
{
    _enable = false;
}

void MonitorModule::setNbPlotPerInterval(unsigned int nbPlotPerInterval)
{
    _nbPlotPerInterval = nbPlotPerInterval;
}

void MonitorModule::changeStatus()
{
    _enable = !_enable;
}