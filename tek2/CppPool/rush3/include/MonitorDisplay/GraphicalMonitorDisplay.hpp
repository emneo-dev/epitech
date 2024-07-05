/*
** EPITECH PROJECT, 2021
** GRAPHICALMONITORDISPLAY
** File description:
** GraphicalMonitorDisplay header
*/

#ifndef GRAPHICALMONITORDISPLAY_H_
#define GRAPHICALMONITORDISPLAY_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include "MonitorDisplay.hpp"

class GraphicalMonitorDisplay : public MonitorDisplay
{
public:
    GraphicalMonitorDisplay(unsigned char tags, int width = 1280, int height = 720);
    ~GraphicalMonitorDisplay() override;

    void reorganizeModules() override;

    void updateEvent() override;
    void update() override;
    void draw() override;

    int isOpen() override;

protected:
    sf::RenderWindow _window;
};

#endif /* !GRAPHICALMONITORDISPLAY_H_ */