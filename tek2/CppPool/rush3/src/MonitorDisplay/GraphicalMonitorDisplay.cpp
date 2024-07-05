/*
** EPITECH PROJECT, 2021
** GRAPHICALMONITORDISPLAY
** File description:
** GraphicalMonitorDisplay class
*/

#include <assert.h>
#include <unistd.h>
#include <iostream>
#include "InfoMonitorModule.hpp"
#include "GraphicalMonitorDisplay.hpp"

GraphicalMonitorDisplay::GraphicalMonitorDisplay(unsigned char tags, int width, int height) : MonitorDisplay(tags), _window(sf::VideoMode(width, height), "MyGKrellm", sf::Style::Default, sf::ContextSettings(0, 0, 5))
{
    _window.setFramerateLimit(30);
    _width = width;
    _height = height;
    reorganizeModules();
}

GraphicalMonitorDisplay::~GraphicalMonitorDisplay()
{
}

int GraphicalMonitorDisplay::isOpen()
{
    return _window.isOpen();
}

static void reorganizeModules_setPos(std::unordered_map<IMonitorDisplay::ModuleType, IMonitorModule *> &_modules, int moduleId, DrawInfo drawinfo)
{
    int count = 0;
    for (int k = 0; k < (int)IMonitorDisplay::NB_MODULES; k++)
    {
        if (_modules[(IMonitorDisplay::ModuleType)k]->isEnabled())
        {
            if (count == moduleId)
            {
                _modules[(IMonitorDisplay::ModuleType)k]->setDrawInfo(drawinfo);
                return;
            }
            count++;
        }
    }
}

void GraphicalMonitorDisplay::reorganizeModules()
{
    if (getNbEnabledModule() == 1)
    {
        reorganizeModules_setPos(_modules, 0, DrawInfo(0, 0, _width, _height));
    }
    else if (getNbEnabledModule() == 2)
    {
        reorganizeModules_setPos(_modules, 0, DrawInfo(0, 0, _width, _height / 2));
        reorganizeModules_setPos(_modules, 1, DrawInfo(0, _height / 2, _width, _height / 2));
    }
    else if (getNbEnabledModule() == 3)
    {
        reorganizeModules_setPos(_modules, 0, DrawInfo(0, 0, _width / 2, _height / 2));
        reorganizeModules_setPos(_modules, 1, DrawInfo(_width / 2, 0, _width / 2, _height / 2));
        reorganizeModules_setPos(_modules, 2, DrawInfo(0, _height / 2, _width, _height / 2));
    }
    else if (getNbEnabledModule() == 4)
    {
        reorganizeModules_setPos(_modules, 0, DrawInfo(0, 0, _width / 2, _height / 2));
        reorganizeModules_setPos(_modules, 1, DrawInfo(_width / 2, 0, _width / 2, _height / 2));
        reorganizeModules_setPos(_modules, 2, DrawInfo(0, _height / 2, _width / 2, _height / 2));
        reorganizeModules_setPos(_modules, 3, DrawInfo(_width / 2, _height / 2, _width / 2, _height / 2));
    }
    else
    {
        reorganizeModules_setPos(_modules, 0, DrawInfo(0, 0, _width / 3, _height / 2));
        reorganizeModules_setPos(_modules, 1, DrawInfo(_width / 3, 0, _width / 3, _height / 2));
        reorganizeModules_setPos(_modules, 2, DrawInfo(_width * 2 / 3, 0, _width / 3, _height / 2));
        reorganizeModules_setPos(_modules, 3, DrawInfo(0, _height / 2, _width / 2, _height / 2));
        reorganizeModules_setPos(_modules, 4, DrawInfo(_width / 2, _height / 2, _width / 2, _height / 2));
    }
}

void GraphicalMonitorDisplay::updateEvent()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q))
            _window.close();
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case(sf::Keyboard::C):
                changeModuleState(CPU_MODULE);
                break;
            case(sf::Keyboard::K):
                changeModuleState(CPU_CORE_MODULE);
                break;
            case(sf::Keyboard::R):
                changeModuleState(RAM_MODULE);
                break;
            case(sf::Keyboard::N):
                changeModuleState(NETWORK_MODULE);
                break;
            case(sf::Keyboard::I):
                changeModuleState(INFO_MODULE);
                break;
            case(sf::Keyboard::H):
                static_cast<InfoMonitorModule *>(_modules[INFO_MODULE])->_hostname->changeStatus();
                break;
            case(sf::Keyboard::D):
                static_cast<InfoMonitorModule *>(_modules[INFO_MODULE])->_dateTime->changeStatus();
                break;
            case(sf::Keyboard::O):
                static_cast<InfoMonitorModule *>(_modules[INFO_MODULE])->_os->changeStatus();
                break;
            case(sf::Keyboard::U):
                static_cast<InfoMonitorModule *>(_modules[INFO_MODULE])->_uptime->changeStatus();
                break;
            default:
                break;
            }
        }
    }
}

void GraphicalMonitorDisplay::update()
{
    reorganizeModules();
    for (int type = 0; type < NB_MODULES; type++)
        _modules[(ModuleType)type]->update();
}

void GraphicalMonitorDisplay::draw()
{
    if (!isOpen())
        return;
    _window.clear(sf::Color::Black);
    for (int type = 0; type < NB_MODULES; type++)
        if (_modules[(ModuleType)type]->isEnabled())
            _modules[(ModuleType)type]->draw(_window);
    _window.display();
}