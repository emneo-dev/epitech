/*
** EPITECH PROJECT, 2021
** RAMMONITORMODULE
** File description:
** RAMMonitorModule class
*/

#include <sys/sysinfo.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <assert.h>
#include "RAMMonitorModule.hpp"
#include <ncurses.h>

RAMMonitorModule::RAMMonitorModule()
{
    _ramSwapUsage = new std::list<float>[2];
    assert(_ramSwapUsage);
}

RAMMonitorModule::RAMMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
}

RAMMonitorModule::~RAMMonitorModule()
{
    delete[] _ramSwapUsage;
}
#include <iostream>
void RAMMonitorModule::update()
{
    struct sysinfo sysInfos;

    if (sysinfo(&sysInfos))
        return;
    _totalRam = sysInfos.totalram;
    _freeRam = sysInfos.freeram;
    _sharedRam = sysInfos.sharedram;
    _bufferRam = sysInfos.bufferram;
    _totalSwap = sysInfos.totalswap;
    _freeSwap = sysInfos.freeswap;
    _cachedRam = 0;

    std::ifstream meminfo("/proc/meminfo");
    std::string buffer;
    for (int i = 0; i < 5; i++)
        getline(meminfo, buffer, '\n');
    std::stringstream stm(buffer);
    std::string tmp;
    stm >> tmp;
    stm >> _cachedRam;

    _cachedRam *= 1024;

    _ramSwapUsage[0].push_back((_totalRam - _freeRam - _cachedRam) * 100 / _totalRam);
    if (_totalSwap == 0)
        _ramSwapUsage[1].push_back(0);
    else
        _ramSwapUsage[1].push_back((_totalSwap - _freeSwap) * 100 / _totalSwap);
    if (_ramSwapUsage[0].size() > _nbPlotPerInterval + 1)
        _ramSwapUsage[0].pop_front();
    if (_ramSwapUsage[1].size() > _nbPlotPerInterval + 1)
        _ramSwapUsage[1].pop_front();
}

void RAMMonitorModule::draw()
{
    char buff[1024];
    sprintf(buff, "Mem: %.2f GB used: %.1f MB free: %.1f MB", ((_totalRam / 1024) / 1024) / 1024.00, ((_totalRam - _freeRam - _cachedRam) / 1024) / 1024.00, ((_freeRam + _cachedRam) / 1024) / 1024.00);
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY(),_infos.getX(), "%s", buff);
    sprintf(buff, "Swp: %.2f GB used: %.1f MB free: %.1f MB", ((_totalSwap / 1024) / 1024) / 1024.00, ((_totalSwap-_freeSwap)/1024)/1024.00, (_freeSwap / 1024)/1024.00);
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY() + 1,_infos.getX(), "%s", buff);
}

void RAMMonitorModule::draw(sf::RenderWindow &window)
{
    MonitorModule::draw(window);

    DrawInfo plotDrawInfo(_infos, 6);
    plotDrawInfo.setHeight(plotDrawInfo.getHeight() - 60);
    plotDrawInfo.setY(plotDrawInfo.getY() + 60);

    _label.setCharacterSize(18);
    char buff[100];
    sprintf(buff, "Ram total: %0.1fGB", _totalRam / 1024 / 1024 / 1024.0);
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 5));
    _label.setFillColor(sf::Color::Red);
    window.draw(_label);
    sprintf(buff, "Ram used: %0.1f%%", _ramSwapUsage[0].back());
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5 + _infos.getWidth() / 2, _infos.getY() + 5));
    _label.setFillColor(sf::Color::Red);
    window.draw(_label);
    sprintf(buff, "Swap total: %0.1fGB", _totalSwap / 1024 / 1024 / 1024.0);
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 35));
    _label.setFillColor(sf::Color::Green);
    window.draw(_label);
    sprintf(buff, "Swap used: %0.1f%%", _ramSwapUsage[1].back());
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5 + _infos.getWidth() / 2, _infos.getY() + 35));
    _label.setFillColor(sf::Color::Green);
    window.draw(_label);
    GraphicalHelper::DrawMultiPlots(window, _label, plotDrawInfo, _ramSwapUsage, 2, _nbPlotPerInterval, sf::Color(160, 160, 160), sf::Color::Black);
}