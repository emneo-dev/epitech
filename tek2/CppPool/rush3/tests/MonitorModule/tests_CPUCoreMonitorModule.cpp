/*
** EPITECH PROJECT, 2021
** TESTS_CPUCOREMONITORMODULE
** File description:
** Test CPUCoreMonitorModule
*/

#include <criterion/criterion.h>
#include "CPUCoreMonitorModule.hpp"

Test(CPUCoreMonitorModule, basic)
{
    CPUCoreMonitorModule module;

    module.setDrawInfo(DrawInfo(1, 2, 3, 4));
    cr_assert_eq(module.getDrawInfo().getX(), 1);
    cr_assert_eq(module.getDrawInfo().getY(), 2);
    cr_assert_eq(module.getDrawInfo().getWidth(), 3);
    cr_assert_eq(module.getDrawInfo().getHeight(), 4);
    cr_assert_eq(module.isEnabled(), true);
    module.disable();
    cr_assert_eq(module.isEnabled(), false);
    module.enable();
    cr_assert_eq(module.isEnabled(), true);
    module.changeStatus();
    cr_assert_eq(module.isEnabled(), false);
}

class TestCPUCoreMonitorModule : public CPUCoreMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestCPUCoreMonitorModule::checkIfThereIsNotOutliers()
{
    update();
    cr_assert_gt(_nbCore, 0);
    for (int i = 0; i < _nbCore; i++)
    {
        cr_assert_gt(_cpuUsage[i].back(), -1);
        cr_assert_lt(_cpuUsage[i].back(), 101);
    }
}

Test(CPUCoreMonitorModule, checkIfThereIsNotOutliers)
{
    TestCPUCoreMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}