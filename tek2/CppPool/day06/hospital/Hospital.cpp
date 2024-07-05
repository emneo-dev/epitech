/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** Hospital
*/

#include "Hospital.hpp"

Hospital::Hospital()
{
    this->doctorList = nullptr;
    this->nurseList = nullptr;
    this->sickList = nullptr;
}

Hospital::~Hospital()
{
}

void Hospital::addNurse(KoalaNurseList *nurse)
{
    if (this->nurseList && this->nurseList->getFromID(nurse->data->ID) != nullptr)
        return;
    std::cout << "[HOSPITAL] Nurse " << nurse->data->ID << " just arrived!" << std::endl;
    if (!this->nurseList)
        this->nurseList = nurse;
    else
        this->nurseList->append(nurse);
    nurse->data->timeCheck();
}

void Hospital::addSick(SickKoalaList *nurse)
{
    if (this->sickList && this->sickList->getFromName(nurse->data->name) != nullptr)
        return;
    std::cout << "[HOSPITAL] Patient " << nurse->data->name << " just arrived!" << std::endl;
    if (!this->sickList)
        this->sickList = nurse;
    else
        this->sickList->append(nurse);
}

void Hospital::addDoctor(KoalaDoctorList *nurse)
{
    if (this->doctorList && this->doctorList->getFromName(nurse->data->name) != nullptr)
        return;
    std::cout << "[HOSPITAL] Doctor " << nurse->data->name << " just arrived!" << std::endl;
    if (!this->doctorList)
        this->doctorList = nurse;
    else
        this->doctorList->append(nurse);
    nurse->data->timeCheck();
}

void Hospital::run()
{
    // Initialisation
    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    if (doctorList)
        doctorList->dump();
    if (nurseList)
        nurseList->dump();
    if (sickList)
        sickList->dump();
    std::cout << std::endl;

    KoalaDoctorList *currentDoctor = this->doctorList;
    KoalaNurseList *currentNurse = this->nurseList;
    SickKoalaList *currentSick = this->sickList;

    // Execution
    while (currentSick) {
        currentDoctor->data->diagnose(currentSick->data);
        if (currentDoctor->next == nullptr)
            currentDoctor = this->doctorList;
        else
            currentDoctor = currentDoctor->next;
        currentNurse->data->giveDrug(currentNurse->data->readReport(currentSick->data->name + ".report"), currentSick->data);
        if (currentNurse->next == nullptr)
            currentNurse = this->nurseList;
        else
            currentNurse = currentNurse->next;
        currentSick = currentSick->next;
    }

    // Destruction
    currentDoctor = this->doctorList;
    currentNurse = this->nurseList;
    while (!currentNurse->isEnd()) {
        currentNurse->data->timeCheck();
        currentNurse = currentNurse->next;
    }
    currentNurse->data->timeCheck();
    while (!currentDoctor->isEnd()) {
        currentDoctor->data->timeCheck();
        currentDoctor = currentDoctor->next;
    }
    currentDoctor->data->timeCheck();
    this->doctorList->next = nullptr;
    this->nurseList->next = nullptr;
    this->sickList->next = nullptr;
}