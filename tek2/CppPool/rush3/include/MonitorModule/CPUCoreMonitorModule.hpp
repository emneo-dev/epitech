/*
** EPITECH PROJECT, 2021
** CPUCOREMONITORMODULE
** File description:
** CPUCoreMonitorModule header
*/

#ifndef CPUCOREMONITORMODULE_H_
#define CPUCOREMONITORMODULE_H_

#include <list>
#include "MonitorModule.hpp"

class CPUCoreMonitorModule : public MonitorModule
{
public:
    CPUCoreMonitorModule();
    CPUCoreMonitorModule(const DrawInfo &infos);
    ~CPUCoreMonitorModule() override;

    void init();

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;

protected:
    int _nbCore;
    std::list<float> *_cpuUsage;
    float *_previousTotalJiffies;
    float *_previousWorkJiffies;
};

#endif /* !CPUCOREMONITORMODULE_H_ */