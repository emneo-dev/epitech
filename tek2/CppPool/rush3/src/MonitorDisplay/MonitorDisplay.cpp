/*
** EPITECH PROJECT, 2021
** MONITORDISPLAY
** File description:
** MonitorDisplay class
*/

#include <assert.h>
#include "MonitorDisplay.hpp"
#include "RAMMonitorModule.hpp"
#include "NetworkMonitorModule.hpp"
#include "CPUMonitorModule.hpp"
#include "CPUCoreMonitorModule.hpp"
#include "InfoMonitorModule.hpp"

MonitorDisplay::MonitorDisplay(unsigned char tags)
{
    _modules[CPU_MODULE] = new CPUMonitorModule();
    _modules[CPU_CORE_MODULE] = new CPUCoreMonitorModule();
    _modules[RAM_MODULE] = new RAMMonitorModule();
    _modules[NETWORK_MODULE] = new NetworkMonitorModule();
    _modules[INFO_MODULE] = new InfoMonitorModule();
    assert(_modules[CPU_MODULE]);
    assert(_modules[CPU_CORE_MODULE]);
    assert(_modules[RAM_MODULE]);
    assert(_modules[NETWORK_MODULE]);
    assert(_modules[INFO_MODULE]);
    _nbEnabledModule = 5;
    if (!(tags & (0b1 << (int)IMonitorDisplay::CPU_MODULE))) {
        _modules[CPU_MODULE]->disable();
        _nbEnabledModule--;
    }
    if (!(tags & (0b1 << (int)IMonitorDisplay::CPU_CORE_MODULE))) {
        _modules[CPU_CORE_MODULE]->disable();
        _nbEnabledModule--;
    }
    if (!(tags & (0b1 << (int)IMonitorDisplay::RAM_MODULE))) {
        _modules[RAM_MODULE]->disable();
        _nbEnabledModule--;
    }
    if (!(tags & (0b1 << (int)IMonitorDisplay::NETWORK_MODULE))) {
        _modules[NETWORK_MODULE]->disable();
        _nbEnabledModule--;
    }
    if (!(tags & (0b1 << (int)IMonitorDisplay::INFO_MODULE))) {
        _modules[INFO_MODULE]->disable();
        _nbEnabledModule--;
    }
}

MonitorDisplay::~MonitorDisplay()
{
    delete _modules[CPU_MODULE];
    delete _modules[CPU_CORE_MODULE];
    delete _modules[RAM_MODULE];
    delete _modules[NETWORK_MODULE];
    delete _modules[INFO_MODULE];
}

void MonitorDisplay::enableModule(ModuleType moduleType)
{
    if (!_modules[moduleType]->isEnabled())
    {
        _modules[moduleType]->enable();
        _nbEnabledModule++;
    }
    reorganizeModules();
}

void MonitorDisplay::disableModule(ModuleType moduleType)
{
    if (_modules[moduleType]->isEnabled())
    {
        _modules[moduleType]->disable();
        _nbEnabledModule--;
    }
    reorganizeModules();
}

void MonitorDisplay::changeModuleState(ModuleType moduleType)
{
    if (_modules[moduleType]->isEnabled())
        disableModule(moduleType);
    else
        enableModule(moduleType);
}

int MonitorDisplay::getNbEnabledModule() const
{
    return _nbEnabledModule;
}
