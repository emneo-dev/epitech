/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *patient)
{
    this->data = patient;
    this->next = nullptr;
}

bool SickKoalaList::isEnd()
{
    return this->next == nullptr;
}

void SickKoalaList::append(SickKoalaList *new_node)
{
    SickKoalaList *node = this;
    while (node->next)
        node = node->next;
    node->next = new_node;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *node = this;
    while (node) {
        if (node->data && node->data->name == name)
            return node->data;
        node = node->next;
    }
    return nullptr;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *rmNode)
{
    SickKoalaList *node = this;
    SickKoalaList *previousNode = this;
    if (node == rmNode)
        return node->next;
    node = node->next;
    while (node) {
        if (node == rmNode) {
            previousNode->next = node->next;
            node->next = nullptr;
            return this;
        }
        previousNode = node;
        node = node->next;
    }
    return this;
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *node = this;
    SickKoalaList *previousNode = this;
    if (node->data && node->data->name == name)
        return node->next;
    node = node->next;
    while (node) {
        if (node->data && node->data->name == name) {
            previousNode->next = node->next;
            node->next = nullptr;
            return this;
        }
        previousNode = node;
        node = node->next;
    }
    return this;
}

SickKoala *SickKoalaList::getContent()
{
    return this->data;
}

SickKoalaList *SickKoalaList::getNext()
{
    return this->next;
}

void SickKoalaList::dump()
{
    std::cout << "Patients:";
    SickKoalaList *node = this;
    while (node) {
        if (node->data)
            std::cout << " " << node->data->name;
        else
            std::cout << " [nullptr]";
        if (node->next)
            std::cout << ",";
        else
            std::cout << "." << std::endl;
        node = node->next;
    }
}

SickKoalaList::~SickKoalaList()
{
}
