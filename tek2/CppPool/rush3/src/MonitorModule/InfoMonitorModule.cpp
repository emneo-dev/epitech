/*
** EPITECH PROJECT, 2020
** B-CPP-300-TLS-3-1-CPPrush3-pauline.faure
** File description:
** InfoMonitorModule.cpp
*/

#include <assert.h>
#include <ncurses.h>
#include "HostnameUsernameMonitorModule.hpp"
#include "DateTimeMonitorModule.hpp"
#include "OSNameKernelVersionMonitorModule.hpp"
#include "UPTimeMonitorModule.hpp"
#include "InfoMonitorModule.hpp"

InfoMonitorModule::InfoMonitorModule()
{
    _hostname = new HostnameUsernameMonitorModule();
    _dateTime = new DateTimeMonitorModule();
    _os = new OSNameKernelVersionMonitorModule();
    _uptime = new UPTimeMonitorModule();
    assert(_hostname);
    assert(_dateTime);
    assert(_os);
    assert(_uptime);
}

InfoMonitorModule::InfoMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
}

InfoMonitorModule::~InfoMonitorModule()
{
    delete _hostname;
    delete _dateTime;
    delete _os;
    delete _uptime;
}

static void terminalReorganizeModules(InfoMonitorModule &_infoMonitorModule)
{
    int w = _infoMonitorModule.getDrawInfo().getWidth();
    int h = _infoMonitorModule.getDrawInfo().getHeight();
    int x = _infoMonitorModule.getDrawInfo().getX();
    int y = _infoMonitorModule.getDrawInfo().getY();

    _infoMonitorModule._hostname->setDrawInfo(DrawInfo(x, y, w, h / 4));
    _infoMonitorModule._os->setDrawInfo(DrawInfo(x, y + 1 , w, h / 4));
    _infoMonitorModule._dateTime->setDrawInfo(DrawInfo(x, y + 2, w, h / 4));
    _infoMonitorModule._uptime->setDrawInfo(DrawInfo(y+3, x , w, h / 4));
}

static void graphicalReorganizeModules(InfoMonitorModule &_infoMonitorModule)
{
    int w = _infoMonitorModule.getDrawInfo().getWidth();
    int h = _infoMonitorModule.getDrawInfo().getHeight();
    int x = _infoMonitorModule.getDrawInfo().getX();
    int y = _infoMonitorModule.getDrawInfo().getY();

    _infoMonitorModule._hostname->setDrawInfo(DrawInfo(x, y, w, h / 4));
    _infoMonitorModule._os->setDrawInfo(DrawInfo(x, y + h / 4, w, h / 4));
    _infoMonitorModule._dateTime->setDrawInfo(DrawInfo(x, y + h / 2, w, h / 4));
    _infoMonitorModule._uptime->setDrawInfo(DrawInfo(x, y + h * 3 / 4, w, h / 4));
}

void InfoMonitorModule::update()
{
    _hostname->update();
    _dateTime->update();
    _os->update();
    _uptime->update();
}

void InfoMonitorModule::draw()
{
    terminalReorganizeModules(*this);
    if (_hostname->isEnabled())
        _hostname->draw();
    if (_dateTime->isEnabled())
        _dateTime->draw();
    if (_os->isEnabled())
        _os->draw();
    if (_uptime->isEnabled())
        _uptime->draw();
}

void InfoMonitorModule::draw(sf::RenderWindow &window)
{
    MonitorModule::draw(window);
    graphicalReorganizeModules(*this);
    if (_hostname->isEnabled())
        _hostname->draw(window);
    if (_dateTime->isEnabled())
        _dateTime->draw(window);
    if (_os->isEnabled())
        _os->draw(window);
    if (_uptime->isEnabled())
        _uptime->draw(window);
}