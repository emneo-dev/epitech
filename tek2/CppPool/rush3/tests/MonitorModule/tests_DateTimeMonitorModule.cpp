/*
** EPITECH PROJECT, 2021
** TESTS_DATETIMEMONITORMODULE
** File description:
** Test DateTimeMonitorModule
*/

#include <criterion/criterion.h>
#include "DateTimeMonitorModule.hpp"

Test(DateTimeMonitorModule, basic)
{
    DateTimeMonitorModule module;

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

class TestDateTimeMonitorModule : public DateTimeMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestDateTimeMonitorModule::checkIfThereIsNotOutliers()
{
    update();
    cr_assert_neq(_dateTime.size(), 0);
}

Test(DateTimeMonitorModule, checkIfThereIsNotOutliers)
{
    TestDateTimeMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}