/*
** EPITECH PROJECT, 2021
** MONITORDISPLAY
** File description:
** MonitorDisplay header
*/

#ifndef MONITORDISPLAY_H_
#define MONITORDISPLAY_H_

#include <unordered_map>
#include <thread>

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class MonitorDisplay : public IMonitorDisplay
{
public:
    MonitorDisplay(unsigned char tags);
    ~MonitorDisplay() override;

    void enableModule(ModuleType moduleType) override;
    void disableModule(ModuleType moduleType) override;
    void changeModuleState(ModuleType moduleType) override;
    int getNbEnabledModule() const override;

protected:
    std::unordered_map<ModuleType, IMonitorModule *> _modules;
    int _nbEnabledModule;
    int _width;
    int _height;
};

#endif /* !MONITORDISPLAY_H_ */