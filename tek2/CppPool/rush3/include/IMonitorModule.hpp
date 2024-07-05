/*
** EPITECH PROJECT, 2021
** IMONITORMODULE
** File description:
** IMonitorModule header
*/

#ifndef IMONITORMODULE_H_
#define IMONITORMODULE_H_

#include <SFML/Graphics.hpp>
#include "DrawInfo.hpp"

class IMonitorModule
{
public:
    virtual ~IMonitorModule(){};

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;

    virtual void setDrawInfo(const DrawInfo &infos) = 0;
    virtual DrawInfo getDrawInfo() const = 0;

    virtual bool isEnabled() const = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual void setNbPlotPerInterval(unsigned int nbPlotPerInterval) = 0;
    virtual void changeStatus() = 0;
};

#endif /* !IMONITORMODULE_H_ */