/*
** EPITECH PROJECT, 2020
** B-CPP-300-TLS-3-1-CPPrush3-pauline.faure
** File description:
** InfoMonitorModule.hpp
*/

#ifndef INFOMONITORMODULE_HPP
#define INFOMONITORMODULE_HPP

#include "MonitorModule.hpp"

class InfoMonitorModule : public MonitorModule
{
public:
    InfoMonitorModule();
    InfoMonitorModule(const DrawInfo &infos);
    ~InfoMonitorModule() override;

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;
    

    IMonitorModule *_hostname;
    IMonitorModule *_dateTime;
    IMonitorModule *_os;
    IMonitorModule *_uptime;
};

#endif /* !INFOMONITORMODULE_HPP_ */