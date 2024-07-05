/*
** EPITECH PROJECT, 2021
** MyUnitTests
** File description:
** MyUnitTests
*/

#include "MyUnitTests.hpp"
#include "Wrap.hpp"
#include "Elf.hpp"

Object **MyUnitTests()
{
    Object **obj = new Object*[2];

    obj[0] = new Teddy("cuddles");
    obj[1] = new LittlePoney("happy pony");
    return (obj);
}

Object *MyUnitTests(Object **objList)
{
    objList[1]->openMe();
    objList[1]->wrapMeThat(objList[0]);
    objList[1]->closeMe();
    objList[2]->wrapMeThat(objList[1]);
    return (objList[2]);
}