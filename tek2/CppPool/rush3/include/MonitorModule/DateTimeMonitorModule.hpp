/*
** EPITECH PROJECT, 2020
** B-CPP-300-TLS-3-1-CPPrush3-pauline.faure
** File description:
** DateTimeMonitorModule.hpp
*/

#ifndef DATETIMEMONITORMODULE_HPP_
#define DATETIMEMONITORMODULE_HPP_

#include "MonitorModule.hpp"

class DateTimeMonitorModule : public MonitorModule
{
public:
    DateTimeMonitorModule();
    DateTimeMonitorModule(const DrawInfo &);
    ~DateTimeMonitorModule();

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;

protected:
    std::string _dateTime;
};

#endif