/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *patient)
{
    this->data = patient;
    this->next = nullptr;
}

bool KoalaNurseList::isEnd()
{
    return this->next == nullptr;
}

void KoalaNurseList::append(KoalaNurseList *new_node)
{
    KoalaNurseList *node = this;
    while (node->next)
        node = node->next;
    node->next = new_node;
}

KoalaNurse *KoalaNurseList::getFromID(int ID)
{
    KoalaNurseList *node = this;
    while (node) {
        if (node->data && node->data->ID == ID)
            return node->data;
        node = node->next;
    }
    return nullptr;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *rmNode)
{
    KoalaNurseList *node = this;
    KoalaNurseList *previousNode = this;
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

KoalaNurseList *KoalaNurseList::removeFromID(int ID)
{
    KoalaNurseList *node = this;
    KoalaNurseList *previousNode = this;
    if (node->data && node->data->ID == ID)
        return node->next;
    node = node->next;
    while (node) {
        if (node->data && node->data->ID == ID) {
            previousNode->next = node->next;
            node->next = nullptr;
            return this;
        }
        previousNode = node;
        node = node->next;
    }
    return this;
}

KoalaNurse *KoalaNurseList::getContent()
{
    return this->data;
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return this->next;
}

void KoalaNurseList::dump()
{
    std::cout << "Patients:";
    KoalaNurseList *node = this;
    while (node) {
        if (node->data)
            std::cout << " " << node->data->ID;
        else
            std::cout << " [nullptr]";
        if (node->next)
            std::cout << ",";
        else
            std::cout << "." << std::endl;
        node = node->next;
    }
}

KoalaNurseList::~KoalaNurseList()
{
}
