/*
** EPITECH PROJECT, 2021
** CPUMONITORMODULE
** File description:
** CPUMonitorModule class
*/

#include <cstdint>
#include <sys/sysinfo.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <thread>
#include <string>
#include <ncurses.h>
#include "CPUMonitorModule.hpp"

CPUMonitorModule::CPUMonitorModule()
{
    _nbCore = (int)std::thread::hardware_concurrency();
    _previousTotalJiffies = -1;
    _previousWorkJiffies = -1;

    std::string buffer;
    std::ifstream stats("/proc/cpuinfo");
    if (!stats.good())
        abort();
    for (int k = 0; k < 5; k++)
        getline(stats, buffer, '\n');
    _model = buffer.substr(13);
    stats.close();
}

CPUMonitorModule::CPUMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
    _previousTotalJiffies = -1;
    _previousWorkJiffies = -1;
}

CPUMonitorModule::~CPUMonitorModule()
{
}

void CPUMonitorModule::update()
{
    std::string buffer;
    std::vector<std::string> infos;
    std::ifstream stats("/proc/stat");
    if (!stats.good())
        abort();
    getline(stats, buffer, '\n');
    stats.close();
    std::stringstream stm(buffer);
    std::string tmpBuffer;
    while (stm.good())
    {
        tmpBuffer.clear();
        stm >> tmpBuffer;
        infos.push_back(tmpBuffer);
    }
    float currentTotalJiffies = 0;
    for (int i = 1; i < (int)infos.size(); i++)
        currentTotalJiffies += std::stoi(infos.at(i));
    float currentWorkJiffies = std::stoi(infos.at(1)) + std::stoi(infos.at(2)) + std::stoi(infos.at(3));
    if (_previousTotalJiffies != -1 && _previousWorkJiffies != -1 && currentTotalJiffies - _previousTotalJiffies != 0)
    {
        float cpuUsage = (currentWorkJiffies - _previousWorkJiffies) / (currentTotalJiffies - _previousTotalJiffies) * 100;
        _cpuUsage.push_back(cpuUsage);
        if (_cpuUsage.size() > _nbPlotPerInterval + 1)
            _cpuUsage.pop_front();
    }
    _previousTotalJiffies = currentTotalJiffies;
    _previousWorkJiffies = currentWorkJiffies;
}

void CPUMonitorModule::draw()
{
    char buff[1024];
    sprintf(buff,"Model: %s", _model.c_str());
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY()-1, _infos.getX(), "%s", buff);
    sprintf(buff, "CPU: %.2f%%", _cpuUsage.back());
    if ((int)strlen(buff) < _infos.getWidth())
        mvprintw(_infos.getY(), _infos.getX(), "%s", buff);
    sprintf(buff, "Nb core: %d", _nbCore);
    if ((int)strlen(buff) < _infos.getWidth()/2)
        mvprintw(_infos.getY(), _infos.getX()+_infos.getWidth() / 2, "%s", buff);
}

void CPUMonitorModule::draw(sf::RenderWindow &window)
{
    MonitorModule::draw(window);

    DrawInfo plotDrawInfo(_infos, 6);
    plotDrawInfo.setHeight(plotDrawInfo.getHeight() - 60);
    plotDrawInfo.setY(plotDrawInfo.getY() + 60);

    char buff[100];
    _label.setCharacterSize(20);
    sprintf(buff, "Cpu: %0.2f%%\tNb cores: %d", _cpuUsage.back(), _nbCore);
    _label.setString(buff);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 5));
    _label.setFillColor(sf::Color::Red);
    window.draw(_label);
    sprintf(buff, "Model :%s", _model.c_str());
    _label.setString(buff);
    _label.setCharacterSize(15);
    _label.setPosition(sf::Vector2f(_infos.getX() + 5, _infos.getY() + 35));
    _label.setFillColor(sf::Color::Red);
    window.draw(_label);

    GraphicalHelper::DrawPlots(window, _label, plotDrawInfo, _cpuUsage, _nbPlotPerInterval, sf::Color::Red, sf::Color(160, 160, 160), sf::Color::Black);
}