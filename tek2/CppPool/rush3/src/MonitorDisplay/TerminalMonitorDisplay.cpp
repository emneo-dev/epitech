/*
** EPITECH PROJECT, 2021
** TERMINALMONITORDISPLAY
** File description:
** TerminalMonitorDisplay class
*/

#include <ncurses.h>
#include <unistd.h>
#include "InfoMonitorModule.hpp"
#include "TerminalMonitorDisplay.hpp"

TerminalMonitorDisplay::TerminalMonitorDisplay(unsigned char tags) : MonitorDisplay(tags)
{
    _isOpen = true;
    _height = 0;
    _width = 0;

    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, true);
    reorganizeModules();
    draw();
}

TerminalMonitorDisplay::~TerminalMonitorDisplay()
{
    endwin();
}

static void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2 - x1);
    mvhline(y2, x1, 0, x2 - x1);
    mvvline(y1, x1, 0, y2 - y1);
    mvvline(y1, x2, 0, y2 - y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void TerminalMonitorDisplay::reorganizeModules()
{
    int width = 0;
    int height = 0;

    getmaxyx(stdscr, height, width);
    if (height != _height || width != _width) {
        _height = height;
        _width = width;
    }
    _modules[INFO_MODULE]->setDrawInfo(DrawInfo(1, 2, width / 2, height / 2));
    _modules[RAM_MODULE]->setDrawInfo(DrawInfo(width/ 2+1, 2, width / 2, height / 2));
    _modules[CPU_MODULE]->setDrawInfo(DrawInfo(1, height/2, width / 2, height / 2));
    _modules[CPU_CORE_MODULE]->setDrawInfo(DrawInfo(1, height/2 +1, width / 2, height / 2 +1));
    _modules[NETWORK_MODULE]->setDrawInfo(DrawInfo(width /2+1, height /2 , width / 2, height / 2 ));
}

int TerminalMonitorDisplay::isOpen()
{
    return _isOpen;
}

void TerminalMonitorDisplay::updateEvent()
{
    int ch = getch();

    if (ch == ERR)
        return;
    switch (ch)
    {
    case 'q':
    case 'Q':
        _isOpen = false;
        break;
    case 'c':
    case 'C':
        changeModuleState(CPU_MODULE);
        break;
    case 'k':
    case 'K':
        changeModuleState(CPU_CORE_MODULE);
        break;
    case 'r':
    case 'R':
        changeModuleState(RAM_MODULE);
        break;
    case 'n':
    case 'N':
        changeModuleState(NETWORK_MODULE);
        break;
    case 'i':
    case 'I':
        changeModuleState(INFO_MODULE);
        break;
    case 'h':
    case 'H':
        static_cast<InfoMonitorModule *>(_modules[INFO_MODULE])->_hostname->changeStatus();
        break;
    case 'd':
    case 'D':
        static_cast<InfoMonitorModule *>(_modules[INFO_MODULE])->_dateTime->changeStatus();
        break;
    case 'o':
    case 'O':
        static_cast<InfoMonitorModule *>(_modules[INFO_MODULE])->_os->changeStatus();
        break;
    case 'u':
    case 'U':
        static_cast<InfoMonitorModule *>(_modules[INFO_MODULE])->_uptime->changeStatus();
        break;
    default:
        break;
    }
}

void TerminalMonitorDisplay::update()
{
    reorganizeModules();
    for (int type = 0; type < NB_MODULES; type++)
        _modules[(ModuleType)type]->update();
}

void TerminalMonitorDisplay::draw()
{
    if (!isOpen())
        return;
    clear();
    for (int type = 0; type < NB_MODULES; type++)
    {
        if (_modules[(ModuleType)type]->isEnabled())
            _modules[(ModuleType)type]->draw();
        refresh();
    }
    rectangle(0,0,_height-1,_width-1);
    mvprintw(0, _width/2 - sizeof(" mygkrellm ")/2, "|MyGKrellm|");
    refresh();
    sleep(1);
}