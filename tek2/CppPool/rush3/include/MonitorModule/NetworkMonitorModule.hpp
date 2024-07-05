/*
** EPITECH PROJECT, 2021
** NETWORKMONITORMODULE
** File description:
** NetworkMonitorModule header
*/

#ifndef NETWORKMONITORMODULE_H_
#define NETWORKMONITORMODULE_H_

#include "MonitorModule.hpp"

class NetworkMonitorModule : public MonitorModule
{
public:
    NetworkMonitorModule();
    NetworkMonitorModule(const DrawInfo &infos);
    ~NetworkMonitorModule() override;

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;

protected:
    std::list<unsigned long long> *_networks;
    unsigned long long _previousReceive;
    unsigned long long _previousTransmit;
};
#endif /* !NETWORKMONITORMODULE_H_ */