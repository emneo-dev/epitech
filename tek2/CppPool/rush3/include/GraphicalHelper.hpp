/*
** EPITECH PROJECT, 2021
** GRAPHICALHELPER
** File description:
** GraphicalHelper header
*/

#ifndef GRAPHICALHELPER_H_
#define GRAPHICALHELPER_H_

#include <list>
#include <SFML/Graphics.hpp>
#include "DrawInfo.hpp"

class GraphicalHelper
{
public:
    static sf::Color COLORS[];

    static void DrawContainer(sf::RenderWindow &window, DrawInfo &drawInfo, sf::Color outlineColor, sf::Color inColor);
    static void DrawPlots(sf::RenderWindow &window, sf::Text &text, DrawInfo &drawInfo,
                          std::list<float> &plots, int maxPlots = -1,
                          sf::Color plotColor = sf::Color::Red, sf::Color outlineColor = sf::Color::White, sf::Color inColor = sf::Color::Black);
    static void DrawMultiPlots(sf::RenderWindow &window, sf::Text &text, DrawInfo &drawInfo,
                               std::list<float> *(&plots), int nbPlot, int maxPlots = -1,
                               sf::Color outlineColor = sf::Color::White, sf::Color inColor = sf::Color::Black);
    static void DrawMultiPlots(sf::RenderWindow &window, sf::Text &text, DrawInfo &drawInfo,
                               std::list<unsigned long long> *(&plots), int nbPlot, int maxPlots = -1,
                               sf::Color outlineColor = sf::Color::White, sf::Color inColor = sf::Color::Black);
};

#endif /* !GRAPHICALHELPER_H_ */