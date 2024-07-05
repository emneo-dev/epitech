/*
** EPITECH PROJECT, 2021
** NETWORKMONITORMODULE
** File description:
** NetworkMonitorModule class
*/

#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <ncurses.h>
#include "NetworkMonitorModule.hpp"

NetworkMonitorModule::NetworkMonitorModule()
{
    _networks = new std::list<unsigned long long>[2];
    assert(_networks);
    _previousReceive = 0;
    _previousTransmit = 0;
}

NetworkMonitorModule::NetworkMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
}

NetworkMonitorModule::~NetworkMonitorModule()
{
    delete[] _networks;
}

void NetworkMonitorModule::update()
{
    unsigned long long currentReceive = 0;
    unsigned long long currentTransmit = 0;
    std::string buffer;
    std::ifstream stats("/proc/net/dev");
    if (!stats.good())
        abort();
    getline(stats, buffer, '\n');
    getline(stats, buffer, '\n');
    while (getline(stats, buffer, '\n'))
    {
        std::vector<std::string> infos;
        std::stringstream stm(buffer);
        std::string tmpBuffer;
        while (stm.good())
        {
            tmpBuffer.clear();
            stm >> tmpBuffer;
            infos.push_back(tmpBuffer);
        }
        currentReceive += std::stoull(infos.at(1));
        currentTransmit += std::stoull(infos.at(9));
    }

    if ((_previousReceive != 0 && _previousTransmit != 0) || _networks[0].size() > 0)
    {
        _networks[0].push_back(currentReceive - _previousReceive);
        _networks[1].push_back(currentTransmit - _previousTransmit);
        if (_networks[0].size() > _nbPlotPerInterval + 1)
            _networks[0].pop_front();
        if (_networks[1].size() > _nbPlotPerInterval + 1)
            _networks[1].pop_front();
    }
    _previousReceive = currentReceive;
    _previousTransmit = currentTransmit;
    stats.close();
}

void NetworkMonitorModule::draw()
{
    char buff[1024];
    if (_networks[0].back() / 1024.0 > 1024 * 0.75) {
        sprintf(buff, "Receiving: %.1f MB/s", _networks[0].back() / 1024 / 1024.0);
        if ((int)strlen(buff) < _infos.getWidth())
            mvprintw(_infos.getY(), _infos.getX(), "%s", buff);
    } else {
        sprintf(buff, "Receiving: %.1f KB/s", _networks[0].back() / 1024.0);
        if ((int)strlen(buff) < _infos.getWidth())
            mvprintw(_infos.getY(), _infos.getX(), "%s", buff);
    }
    sprintf(buff, "Total Received: %.1f GB", _previousReceive / 1024 / 1024 / 1024.0);
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY() + 1, _infos.getX(), "%s", buff);

    if (_networks[0].back() / 1024.0 > 1024 * 0.75) {
        sprintf(buff, "Sending: %.1f MB/s", _networks[1].back() / 1024 / 1024.0);
        if ((int)strlen(buff) < _infos.getWidth())
            mvprintw(_infos.getY()+2, _infos.getX(), "%s", buff);
    } else {
        sprintf(buff, "Sending: %.1f KB/s", _networks[1].back() / 1024.0);
        if ((int)strlen(buff) < _infos.getWidth())
            mvprintw(_infos.getY()+2, _infos.getX(), "%s", buff);
    }
    sprintf(buff, "Total Sending: %.1f GB", _previousTransmit / 1024 / 1024 / 1024.0);
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY() + 3, _infos.getX(), "%s", buff);
}

void NetworkMonitorModule::draw(sf::RenderWindow &window)
{
    MonitorModule::draw(window);

    DrawInfo plotDrawInfo(_infos, 6);
    plotDrawInfo.setHeight(plotDrawInfo.getHeight() - 60);
    plotDrawInfo.setY(plotDrawInfo.getY() + 60);

    _label.setCharacterSize(20);
    char buff[100];
    if (_networks[0].back() / 1024.0 > 1024 * 0.75)
        sprintf(buff, "Receiving: %.1f MB/s", _networks[0].back() / 1024 / 1024.0);
    else
        sprintf(buff, "Receiving: %.1f KB/s", _networks[0].back() / 1024.0);
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 5));
    _label.setFillColor(sf::Color::Red);
    window.draw(_label);
    sprintf(buff, "Total Received: %.1f GB", _previousReceive / 1024 / 1024 / 1024.0);
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 35));
    _label.setFillColor(sf::Color::Red);
    window.draw(_label);
    if (_networks[1].back() / 1024.0 > 1024 * 0.75)
        sprintf(buff, "Sending: %.1f MB/s", _networks[1].back() / 1024 / 1024.0);
    else
        sprintf(buff, "Sending: %.1f KB/s", _networks[1].back() / 1024.0);
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + _infos.getWidth() / 2 + 5, _infos.getY() + 5));
    _label.setFillColor(sf::Color::Green);
    window.draw(_label);
    sprintf(buff, "Total Sending: %.1f GB", _previousTransmit / 1024 / 1024 / 1024.0);
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + _infos.getWidth() / 2 + 5, _infos.getY() + 35));
    _label.setFillColor(sf::Color::Green);
    window.draw(_label);

    GraphicalHelper::DrawMultiPlots(window, _label, plotDrawInfo, _networks, 2, _nbPlotPerInterval, sf::Color(160, 160, 160), sf::Color::Black);
}