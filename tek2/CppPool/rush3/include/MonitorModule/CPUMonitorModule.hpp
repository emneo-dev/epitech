/*
** EPITECH PROJECT, 2021
** CPUMONITORMODULE
** File description:
** CPUMonitorModule header
*/

#ifndef CPUMONITORMODULE_H_
#define CPUMONITORMODULE_H_

#include <list>
#include "MonitorModule.hpp"

class CPUMonitorModule : public MonitorModule
{
public:
    CPUMonitorModule();
    CPUMonitorModule(const DrawInfo &infos);
    ~CPUMonitorModule() override;

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;

protected:
    int _nbCore;
    std::string _model;
    std::list<float> _cpuUsage;
    float _previousTotalJiffies;
    float _previousWorkJiffies;
};

#endif /* !CPUMONITORMODULE_H_ */