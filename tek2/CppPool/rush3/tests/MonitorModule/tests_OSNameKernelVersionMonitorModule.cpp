/*
** EPITECH PROJECT, 2021
** TESTS_OSNAMEKERNELVERSIONMONITORMODULE
** File description:
** Test OSNameKernelVersionMonitorModule
*/

#include <criterion/criterion.h>
#include "OSNameKernelVersionMonitorModule.hpp"

Test(OSNameKernelVersionMonitorModule, basic)
{
    OSNameKernelVersionMonitorModule module;

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

class TestOSNameKernelVersionMonitorModule : public OSNameKernelVersionMonitorModule
{
public:
    void checkIfThereIsNotOutliers();
};

void TestOSNameKernelVersionMonitorModule::checkIfThereIsNotOutliers()
{
    update();
    cr_assert_neq(_data.size(), 0);
}

Test(OSNameKernelVersionMonitorModule, checkIfThereIsNotOutliers)
{
    TestOSNameKernelVersionMonitorModule testModule;

    testModule.checkIfThereIsNotOutliers();
}