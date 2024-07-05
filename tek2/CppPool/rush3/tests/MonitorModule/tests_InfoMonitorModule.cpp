/*
** EPITECH PROJECT, 2021
** TESTS_INFOMONITORMODULE
** File description:
** Test InfoMonitorModule
*/

#include <criterion/criterion.h>
#include "InfoMonitorModule.hpp"

Test(InfoMonitorModule, basic)
{
    InfoMonitorModule module;

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

class TestInfoMonitorModule : public InfoMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestInfoMonitorModule::checkIfThereIsNotOutliers()
{
    update();
}

Test(InfoMonitorModule, checkIfThereIsNotOutliers)
{
    TestInfoMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}