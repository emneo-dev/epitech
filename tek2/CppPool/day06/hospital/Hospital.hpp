/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** Hospital
*/

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"
#include "SickKoalaList.hpp"

class Hospital {
public:
    Hospital();
    ~Hospital();
    void run();
    void addNurse(KoalaNurseList *nurse);
    void addSick(SickKoalaList *sick);
    void addDoctor(KoalaDoctorList *doctor);

protected:
private:
    KoalaDoctorList *doctorList;
    KoalaNurseList *nurseList;
    SickKoalaList *sickList;
};

#endif /* !HOSPITAL_HPP_ */
