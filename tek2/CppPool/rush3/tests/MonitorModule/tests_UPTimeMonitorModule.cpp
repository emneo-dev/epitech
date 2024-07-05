/*
** EPITECH PROJECT, 2021
** TESTS_UPTIMEMONITORMODULE
** File description:
** Test UPTimeMonitorModule
*/

#include <criterion/criterion.h>
#include "UPTimeMonitorModule.hpp"

Test(UPTimeMonitorModule, basic)
{
    UPTimeMonitorModule module;

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

class TestUPTimeMonitorModule : public UPTimeMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestUPTimeMonitorModule::checkIfThereIsNotOutliers()
{
    update();
    cr_assert_gt(_sec, -1);
    cr_assert_lt(_sec, 61);
    cr_assert_gt(_min, -1);
    cr_assert_lt(_min, 61);
    cr_assert_gt(_hour, -1);
    cr_assert_lt(_hour, 25);
    cr_assert_gt(_day, -1);
}

Test(UPTimeMonitorModule, checkIfThereIsNotOutliers)
{
    TestUPTimeMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}