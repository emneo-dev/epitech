/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <iostream>
#include <fstream>

#include "Teddy.hpp"
#include "Elf.hpp"
#include "TableRand.hpp"
#include "ConveyorBeltRand.hpp"
#include "LittlePoney.hpp"
#include "PapaXmasTable.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "MyUnitTests.hpp"

void MyUnitTestsGift()
{
    Object *ted = new Teddy("cuddles");
    Object *box = new Box();
    Object *giftPaper = new GiftPaper();
    Object *objList[3] = {ted, box, giftPaper};
    Object *objGift = MyUnitTests(objList);

    if (objList == nullptr)
        return;
    std::cout << "------ MyUnitTestsGift ------" << std::endl;
    std::cout << "Oh look i found a " << objGift->getTitle() << " the expected result is GiftPaper" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

void MyUnitTestsList()
{
    Object **objList = MyUnitTests();

    std::cout << "------ MyUnitTestsList ------" << std::endl;
    std::cout << "Oh look i found a " << objList[0]->getTitle() << " the expected result is cuddles" << std::endl;
    std::cout << "Oh look i found a " << objList[1]->getTitle() << " the expected result is happy pony" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

void MySlave()
{
    Elf *slave = new Elf();
    TableRand *table = new TableRand();
    ConveyorBeltRand *conveyor = new ConveyorBeltRand();

    slave->setTable(table);
    slave->setConveyor(conveyor);
    slave->WorkLoop();
}

void generateXML()
{
    Object *ted = new Teddy("test");
    Object *box = new Box();
    Object *giftPaper = new GiftPaper();
    Object *objList[3] = {ted, box, giftPaper};
    Object *objGift = MyUnitTests(objList);
    std::ofstream outfile("giftTest.xml");

    std::cout << objGift->xmlObject() << std::endl;
    outfile << objGift->xmlObject();
    outfile.close();
}

int main()
{
    MyUnitTestsList();
    MyUnitTestsGift();
    MySlave();
    generateXML();
    return (0);
}