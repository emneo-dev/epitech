/*
** EPITECH PROJECT, 2021
** TERMINALMONITORDISPLAY
** File description:
** TerminalMonitorDisplay header
*/

#ifndef TERMINALMONITORDISPLAY_H_
#define TERMINALMONITORDISPLAY_H_

#include "MonitorDisplay.hpp"
#include "UPTimeMonitorModule.hpp"
#include "DateTimeMonitorModule.hpp"
#include "RAMMonitorModule.hpp"
#include "OSNameKernelVersionMonitorModule.hpp"
#include "HostnameUsernameMonitorModule.hpp"

class TerminalMonitorDisplay : public MonitorDisplay
{
public:
    TerminalMonitorDisplay(unsigned char tags);
    ~TerminalMonitorDisplay() override;

    void reorganizeModules() override;

    void updateEvent() override;
    void update() override;
    void draw() override;

    int isOpen() override;

protected:
    bool _isOpen;
};

#endif /* !TERMINALMONITORDISPLAY_H_ */