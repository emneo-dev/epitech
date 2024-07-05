/*
** EPITECH PROJECT, 2021
** MYGKRELLM
** File description:
** MyGKrellm header
*/

#ifndef MYGKRELLM_H_
#define MYGKRELLM_H_

#include "IMonitorDisplay.hpp"

class MyGKrellm
{
public:
    enum DisplayType
    {
        UNKNOWN,
        TERMINAL,
        GRAPHICAL
    };
    MyGKrellm(DisplayType type, unsigned char tags);
    ~MyGKrellm();

    int run();

protected:
    DisplayType _type;
    IMonitorDisplay *_display;
};

#endif /* !MYGKRELLM_H_ */