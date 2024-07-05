/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *patient)
{
    this->data = patient;
    this->next = nullptr;
}

bool KoalaDoctorList::isEnd()
{
    return this->next == nullptr;
}

void KoalaDoctorList::append(KoalaDoctorList *new_node)
{
    KoalaDoctorList *node = this;
    while (node->next)
        node = node->next;
    node->next = new_node;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *node = this;
    while (node) {
        if (node->data && node->data->name == name)
            return node->data;
        node = node->next;
    }
    return nullptr;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *rmNode)
{
    KoalaDoctorList *node = this;
    KoalaDoctorList *previousNode = this;
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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    KoalaDoctorList *node = this;
    KoalaDoctorList *previousNode = this;
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

KoalaDoctor *KoalaDoctorList::getContent()
{
    return this->data;
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return this->next;
}

void KoalaDoctorList::dump()
{
    std::cout << "Patients:";
    KoalaDoctorList *node = this;
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

KoalaDoctorList::~KoalaDoctorList()
{
}
