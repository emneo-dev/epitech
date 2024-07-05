/*
** EPITECH PROJECT, 2021
** RAMMONITORMODULE
** File description:
** RAMMonitorModule header
*/

#ifndef RAMMONITORMODULE_H_
#define RAMMONITORMODULE_H_

#include "MonitorModule.hpp"

class RAMMonitorModule : public MonitorModule
{
public:
    RAMMonitorModule();
    RAMMonitorModule(const DrawInfo &infos);
    ~RAMMonitorModule() override;

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;

protected:
    unsigned long _totalRam;
    unsigned long _freeRam;
    unsigned long _sharedRam;
    unsigned long _bufferRam;
    unsigned long _totalSwap;
    unsigned long _freeSwap;
    unsigned long _cachedRam;
    std::list<float> *_ramSwapUsage;
};

#endif /* !RAMMONITORMODULE_H_ */