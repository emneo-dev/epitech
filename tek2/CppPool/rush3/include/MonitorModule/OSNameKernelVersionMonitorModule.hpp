/*
** EPITECH PROJECT, 2021
** htop
** File description:
** OSNameKernelVersionMonitorModule
*/

#ifndef OSNAMEKERNELVERSIONMONITORMODULE_HPP_
#define OSNAMEKERNELVERSIONMONITORMODULE_HPP_

#include "MonitorModule.hpp"

class OSNameKernelVersionMonitorModule : public MonitorModule
{
public:
    OSNameKernelVersionMonitorModule();
    OSNameKernelVersionMonitorModule(const DrawInfo &infos);
    ~OSNameKernelVersionMonitorModule() override;

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;
protected:
    std::string _data;
};

#endif /* !OSNAMEKERNELVERSIONMONITORMODULE_HPP_ */
