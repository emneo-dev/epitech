/*
** EPITECH PROJECT, 2021
** TESTS_CPUMONITORMODULE
** File description:
** Test CPUMonitorModule
*/

#include <criterion/criterion.h>
#include "CPUMonitorModule.hpp"

Test(CPUMonitorModule, basic)
{
    CPUMonitorModule module;

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

class TestCPUMonitorModule : public CPUMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestCPUMonitorModule::checkIfThereIsNotOutliers()
{
    update();
    cr_assert_gt(_nbCore, 0);
    cr_assert_gt(_cpuUsage.back(), -1);
    cr_assert_lt(_cpuUsage.back(), 101);
}

Test(CPUMonitorModule, checkIfThereIsNotOutliers)
{
    TestCPUMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}