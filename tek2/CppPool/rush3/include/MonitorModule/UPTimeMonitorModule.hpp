/*
** EPITECH PROJECT, 2020
** B-CPP-300-TLS-3-1-CPPrush3-pauline.faure
** File description:
** UPTimeMonitorModule.hpp
*/

#ifndef UPTIMEMONITORMODULE_HPP_
#define UPTIMEMONITORMODULE_HPP_

#include <chrono>
#include <ncurses.h>
#include "MonitorModule.hpp"

class UPTimeMonitorModule : public MonitorModule
{
public:
    UPTimeMonitorModule();
    UPTimeMonitorModule(const DrawInfo &);
    ~UPTimeMonitorModule();

    void update() override;
    void draw() override;
    void draw(sf::RenderWindow &window) override;

protected:
    int _day;
    int _hour;
    int _min;
    int _sec;
};

#endif