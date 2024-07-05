/*
** EPITECH PROJECT, 2021
** TESTS_HOSTNAMEUSERNAMEMONITORMODULE
** File description:
** Test HostnameUsernameMonitorModule
*/

#include <criterion/criterion.h>
#include "HostnameUsernameMonitorModule.hpp"

Test(HostnameUsernameMonitorModule, basic)
{
    HostnameUsernameMonitorModule module;

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

class TestHostnameUsernameMonitorModule : public HostnameUsernameMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestHostnameUsernameMonitorModule::checkIfThereIsNotOutliers()
{
    update();
    cr_assert_neq(_data.size(), 0);
}

Test(HostnameUsernameMonitorModule, checkIfThereIsNotOutliers)
{
    TestHostnameUsernameMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}