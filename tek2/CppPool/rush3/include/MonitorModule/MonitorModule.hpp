/*
** EPITECH PROJECT, 2021
** MONITORMODULE
** File description:
** MonitorModule header
*/

#ifndef MONITORMODULE_H_
#define MONITORMODULE_H_

#include "IMonitorModule.hpp"
#include "GraphicalHelper.hpp"

class MonitorModule : public IMonitorModule
{
public:
    MonitorModule();
    MonitorModule(const DrawInfo &infos);
    ~MonitorModule() override;

    void draw() override;
    void draw(sf::RenderWindow &window) override;

    void setDrawInfo(const DrawInfo &infos) override;
    DrawInfo getDrawInfo() const override;

    bool isEnabled() const override;
    void enable() override;
    void disable() override;
    void changeStatus() override;

    void setNbPlotPerInterval(unsigned int nbPlotPerInterval) override;

protected:
    DrawInfo _infos;
    bool _enable;

    unsigned int _nbPlotPerInterval;

    sf::Font _font;
    sf::Text _label;
};

#endif /* !MONITORMODULE_H_ */