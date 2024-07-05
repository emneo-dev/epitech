/*
** EPITECH PROJECT, 2021
** IMONITORDISPLAY
** File description:
** IMonitorDisplay header
*/

#ifndef IMONITORDISPLAY_H_
#define IMONITORDISPLAY_H_

#include "DrawInfo.hpp"

class IMonitorDisplay
{
public:
    enum ModuleType
    {
        CPU_MODULE,
        CPU_CORE_MODULE,
        RAM_MODULE,
        NETWORK_MODULE,
        INFO_MODULE,
        NB_MODULES
    };
    virtual ~IMonitorDisplay(){};

    virtual void enableModule(ModuleType moduleType) = 0;
    virtual void disableModule(ModuleType moduleType) = 0;
    virtual void changeModuleState(ModuleType moduleType) = 0;
    virtual int getNbEnabledModule() const = 0;

    virtual void reorganizeModules() = 0;

    virtual void updateEvent() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

    virtual int isOpen() = 0;
};

#endif /* !IMONITORDISPLAY_H_ */