/*
** EPITECH PROJECT, 2021
** CPUCOREMONITORMODULE
** File description:
** CPUCoreMonitorModule class
*/

#include <cstdint>
#include <sys/sysinfo.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string>
#include <thread>
#include <assert.h>
#include <ncurses.h>
#include <math.h>
#include "CPUCoreMonitorModule.hpp"

void CPUCoreMonitorModule::init()
{
    _nbCore = (int)std::thread::hardware_concurrency();
    assert(_nbCore > 0);
    _cpuUsage = new std::list<float>[_nbCore];
    _previousTotalJiffies = new float[_nbCore];
    _previousWorkJiffies = new float[_nbCore];
    assert(_cpuUsage);
    assert(_previousTotalJiffies);
    assert(_previousWorkJiffies);
    for (int k = 0; k < _nbCore; k++)
    {
        _previousTotalJiffies[k] = -1;
        _previousWorkJiffies[k] = -1;
    }
}

CPUCoreMonitorModule::CPUCoreMonitorModule()
{
    init();
}

CPUCoreMonitorModule::CPUCoreMonitorModule(const DrawInfo &infos) : MonitorModule(infos)
{
    init();
}

CPUCoreMonitorModule::~CPUCoreMonitorModule()
{
    delete[] _cpuUsage;
    delete[] _previousTotalJiffies;
    delete[] _previousWorkJiffies;
}

void CPUCoreMonitorModule::update()
{
    std::string buffer;
    std::ifstream stats("/proc/stat");
    if (!stats.good())
        abort();
    getline(stats, buffer, '\n');
    for (int coreId = 0; coreId < _nbCore; coreId++)
    {
        getline(stats, buffer, '\n');
        std::vector<std::string> infos;
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
        if (_previousTotalJiffies[coreId] != -1 && _previousWorkJiffies[coreId] != -1 && currentTotalJiffies - _previousTotalJiffies[coreId] != 0 && currentWorkJiffies - _previousWorkJiffies[coreId] != 0)
        {
            float cpuUsage = (currentWorkJiffies - _previousWorkJiffies[coreId]) / (currentTotalJiffies - _previousTotalJiffies[coreId]) * 100;
            _cpuUsage[coreId].push_back(cpuUsage);
            if (_cpuUsage[coreId].size() > _nbPlotPerInterval + 1)
                _cpuUsage[coreId].pop_front();
        }
        _previousTotalJiffies[coreId] = currentTotalJiffies;
        _previousWorkJiffies[coreId] = currentWorkJiffies;
    }
    stats.close();
}

void CPUCoreMonitorModule::draw()
{
    char buff[1024];
    for (int i = 0; i < _nbCore; i++)
        if (i%2 == 0) {
            sprintf(buff, "CPU%d: %.1f%%", i + 1, _cpuUsage[i].back());
            if ((int)strlen(buff) < _infos.getWidth()/2)
                mvprintw(_infos.getY() + i, _infos.getX(), "%s", buff);
         } else {
             sprintf(buff, "CPU%d: %.1f%%", i + 1, _cpuUsage[i].back());
            if ((int)strlen(buff) < _infos.getWidth()/2)
                mvprintw(_infos.getY() + (i-1), _infos.getX()+ _infos.getWidth()/2, "%s", buff);
         }

}

void CPUCoreMonitorModule::draw(sf::RenderWindow &window)
{
    MonitorModule::draw(window);

    int nbLayers = ceil(_nbCore / 4.0);
    DrawInfo plotDrawInfo(_infos, 6);
    plotDrawInfo.setHeight(plotDrawInfo.getHeight() - 30 * nbLayers);
    plotDrawInfo.setY(plotDrawInfo.getY() + 30 * nbLayers);

    char buff[100];
    _label.setCharacterSize(15);
    for (int y = 0; y < nbLayers; y++)
        for (int x = 0; x < 4; x++)
        {
            if (y * 4 + x >= _nbCore)
                break;
            sprintf(buff, "Cpu%d: %0.1f%%", y * 4 + x, _cpuUsage[y * 4 + x].back());
            _label.setString(buff);
            _label.setPosition(sf::Vector2f(_infos.getX() + _infos.getWidth() * x / 4 + 5, _infos.getY() + 5 + y * 30));
            _label.setFillColor(GraphicalHelper::COLORS[(y * 4 + x) % 14]);
            window.draw(_label);
        }

    GraphicalHelper::DrawMultiPlots(window, _label, plotDrawInfo, _cpuUsage, _nbCore, _nbPlotPerInterval, sf::Color(160, 160, 160), sf::Color::Black);
}