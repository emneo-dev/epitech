/*
** EPITECH PROJECT, 2021
** GRAPHICALHELPER
** File description:
** GraphicalHelper class
*/

#include "GraphicalHelper.hpp"

sf::Color GraphicalHelper::COLORS[14] = {
    sf::Color(255, 0, 0),
    sf::Color(0, 255, 0),
    sf::Color(0, 0, 255),
    sf::Color(255, 255, 0),
    sf::Color(0, 255, 255),
    sf::Color(255, 0, 255),
    sf::Color(192, 192, 192),
    sf::Color(128, 128, 128),
    sf::Color(128, 0, 0),
    sf::Color(128, 128, 0),
    sf::Color(0, 128, 0),
    sf::Color(128, 0, 128),
    sf::Color(0, 128, 128),
    sf::Color(0, 0, 128)};

void GraphicalHelper::DrawContainer(sf::RenderWindow &window, DrawInfo &drawInfo, sf::Color outlineColor, sf::Color inColor)
{
    int border = 1;
    sf::RectangleShape rectangleOutline(sf::Vector2f(drawInfo.getWidth(), drawInfo.getHeight()));
    rectangleOutline.setPosition(sf::Vector2f(drawInfo.getX(), drawInfo.getY()));
    rectangleOutline.setFillColor(outlineColor);
    window.draw(rectangleOutline);
    sf::RectangleShape rectangleFill(sf::Vector2f(drawInfo.getWidth() - border * 2, drawInfo.getHeight() - border * 2));
    rectangleFill.setPosition(sf::Vector2f(drawInfo.getX() + border, drawInfo.getY() + border));
    rectangleFill.setFillColor(inColor);
    window.draw(rectangleFill);
}
#include <iostream>
static void DrawPlot(sf::RenderWindow &window, DrawInfo &drawInfo, std::list<float> &plots, int maxPlots, sf::Color plotColor)
{
    if (maxPlots < 0)
        maxPlots = plots.size();
    float withPlot = drawInfo.getWidth() / (float)maxPlots;
    for (int plotId = 0; plotId < (int)plots.size() - 1 && plotId < maxPlots; plotId++)
    {
        int plotX = drawInfo.getX() + (maxPlots - plots.size() + plotId + 1) * withPlot;

        auto plot = plots.begin();
        std::advance(plot, plotId);
        sf::Vertex line[2];
        line[0].position = sf::Vector2f(plotX, drawInfo.getY() + drawInfo.getHeight() * (100 - *plot) / 100);
        std::advance(plot, 1);
        line[1].position = sf::Vector2f(plotX + withPlot, drawInfo.getY() + drawInfo.getHeight() * (100 - *plot) / 100);
        line[0].color = line[1].color = plotColor;

        window.draw(line, 2, sf::Lines);
    }
}

void GraphicalHelper::DrawPlots(sf::RenderWindow &window, sf::Text &text, DrawInfo &drawInfo, std::list<float> &plots, int maxPlots, sf::Color plotColor, sf::Color outlineColor, sf::Color inColor)
{
    DrawContainer(window, drawInfo, outlineColor, inColor);
    drawInfo = DrawInfo(drawInfo, 1);

    char buff[1024];
    text.setCharacterSize(10);
    for (int k = 0; k < 4; k++)
    {
        if (k < 3)
        {
            float yLine = drawInfo.getHeight() * (k + 1) / 4;
            sf::Vertex line[2];
            line[0].position = sf::Vector2f(drawInfo.getX(), drawInfo.getY() + yLine);
            line[1].position = sf::Vector2f(drawInfo.getX() + drawInfo.getWidth(), drawInfo.getY() + yLine);
            line[0].color = line[1].color = sf::Color(outlineColor.r * 0.5, outlineColor.g * 0.5, outlineColor.b * 0.5);

            window.draw(line, 2, sf::Lines);
        }

        sprintf(buff, "%d%%", 100 / 4 * (5 - k - 1));
        text.setString(buff);
        text.setPosition(sf::Vector2f(drawInfo.getX() + drawInfo.getWidth() - 30, drawInfo.getY() + drawInfo.getHeight() * k / 4));
        text.setFillColor(outlineColor);
        window.draw(text);
    }
    DrawPlot(window, drawInfo, plots, maxPlots, plotColor);
}

void GraphicalHelper::DrawMultiPlots(sf::RenderWindow &window, sf::Text &text, DrawInfo &drawInfo,
                                     std::list<float> *(&plots), int nbPlot, int maxPlots,
                                     sf::Color outlineColor, sf::Color inColor)
{
    DrawContainer(window, drawInfo, outlineColor, inColor);
    drawInfo = DrawInfo(drawInfo, 1);

    char buff[1024];
    text.setCharacterSize(10);
    for (int k = 0; k < 4; k++)
    {
        if (k < 3)
        {
            float yLine = drawInfo.getHeight() * (k + 1) / 4;
            sf::Vertex line[2];
            line[0].position = sf::Vector2f(drawInfo.getX(), drawInfo.getY() + yLine);
            line[1].position = sf::Vector2f(drawInfo.getX() + drawInfo.getWidth(), drawInfo.getY() + yLine);
            line[0].color = line[1].color = sf::Color(outlineColor.r * 0.5, outlineColor.g * 0.5, outlineColor.b * 0.5);

            window.draw(line, 2, sf::Lines);
        }

        sprintf(buff, "%d%%", 100 / 4 * (5 - k - 1));
        text.setString(buff);
        text.setPosition(sf::Vector2f(drawInfo.getX() + drawInfo.getWidth() - 30, drawInfo.getY() + drawInfo.getHeight() * k / 4));
        text.setFillColor(outlineColor);
        window.draw(text);
    }
    for (int plotId = 0; plotId < nbPlot; plotId++)
    {
        DrawPlot(window, drawInfo, plots[plotId], maxPlots, COLORS[plotId % 14]);
    }
}

static void DrawPlot(sf::RenderWindow &window, DrawInfo &drawInfo, std::list<unsigned long long int> &plots, int maxPlots, int maxHeight, sf::Color plotColor)
{
    if (maxPlots < 0)
        maxPlots = plots.size();
    float withPlot = drawInfo.getWidth() / (float)maxPlots;
    for (int plotId = 0; plotId < (int)plots.size() - 1 && plotId < maxPlots; plotId++)
    {
        int plotX = drawInfo.getX() + (maxPlots - plots.size() + plotId + 1) * withPlot;

        auto plot = plots.begin();
        std::advance(plot, plotId);
        sf::Vertex line[2];
        line[0].position = sf::Vector2f(plotX, drawInfo.getY() + drawInfo.getHeight() * (maxHeight - *plot) / maxHeight);
        std::advance(plot, 1);
        line[1].position = sf::Vector2f(plotX + withPlot, drawInfo.getY() + drawInfo.getHeight() * (maxHeight - *plot) / maxHeight);
        line[0].color = line[1].color = plotColor;

        window.draw(line, 2, sf::Lines);
    }
}

void GraphicalHelper::DrawMultiPlots(sf::RenderWindow &window, __attribute__((unused)) sf::Text &text, DrawInfo &drawInfo,
                                     std::list<unsigned long long> *(&plots), int nbPlot, int maxPlots,
                                     sf::Color outlineColor, sf::Color inColor)
{
    DrawContainer(window, drawInfo, outlineColor, inColor);
    drawInfo = DrawInfo(drawInfo, 1);

    for (int k = 0; k < 3; k++)
    {
        float yLine = drawInfo.getHeight() * (k + 1) / 4;
        sf::Vertex line[2];
        line[0].position = sf::Vector2f(drawInfo.getX(), drawInfo.getY() + yLine);
        line[1].position = sf::Vector2f(drawInfo.getX() + drawInfo.getWidth(), drawInfo.getY() + yLine);
        line[0].color = line[1].color = sf::Color(outlineColor.r * 0.5, outlineColor.g * 0.5, outlineColor.b * 0.5);

        window.draw(line, 2, sf::Lines);
    }
    unsigned long long maxHeight = 10;
    for (int plotId = 0; plotId < nbPlot; plotId++)
        for (auto it = plots[plotId].begin(); it != plots[plotId].end(); it++)
            if (maxHeight < *it)
                maxHeight = *it;
    for (int plotId = 0; plotId < nbPlot; plotId++)
    {
        DrawPlot(window, drawInfo, plots[plotId], maxPlots, maxHeight, COLORS[plotId % 14]);
    }
}