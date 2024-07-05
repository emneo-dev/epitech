/*
** EPITECH PROJECT, 2021
** htop
** File description:
** HostnameUsernameMonitorModule
*/

#ifndef HOSTNAMEUSERNAMEMONITORMODULE_HPP_
#define HOSTNAMEUSERNAMEMONITORMODULE_HPP_

#include "MonitorModule.hpp"

class HostnameUsernameMonitorModule : public MonitorModule
{
public:
    HostnameUsernameMonitorModule();
    HostnameUsernameMonitorModule(const DrawInfo &infos);
    ~HostnameUsernameMonitorModule() override;

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;

protected:
    std::string _data;
};

#endif /* !HOSTNAMEUSERNAMEMONITORMODULE_HPP_ */
