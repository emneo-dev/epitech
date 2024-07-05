/*
** EPITECH PROJECT, 2021
** TESTS_NETWORKMONITORMODULE
** File description:
** Test NetworkMonitorModule
*/

#include <criterion/criterion.h>
#include "NetworkMonitorModule.hpp"

Test(NetworkMonitorModule, basic)
{
    NetworkMonitorModule module;

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

class TestNetworkMonitorModule : public NetworkMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestNetworkMonitorModule::checkIfThereIsNotOutliers()
{
    update();
}

Test(NetworkMonitorModule, checkIfThereIsNotOutliers)
{
    TestNetworkMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}