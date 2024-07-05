/*
** EPITECH PROJECT, 2021
** TESTS_RAMMONITORMODULE
** File description:
** Test RAMMonitorModule
*/

#include <criterion/criterion.h>
#include "RAMMonitorModule.hpp"

Test(RAMMonitorModule, basic)
{
    RAMMonitorModule module;

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

class TestRAMMonitorModule : public RAMMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestRAMMonitorModule::checkIfThereIsNotOutliers()
{
    update();
    cr_assert_gt(_ramSwapUsage[0].back(), -1.0);
    cr_assert_lt(_ramSwapUsage[0].back(), 101.0);
    cr_assert_gt(_ramSwapUsage[1].back(), -1.0);
    cr_assert_lt(_ramSwapUsage[1].back(), 101.0);
}

Test(RAMMonitorModule, checkIfThereIsNotOutliers)
{
    TestRAMMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}