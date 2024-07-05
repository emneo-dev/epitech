/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include "Object.hpp"

class Wrap : public Object {
    public:
        Wrap(Object::objType type, const std::string &title);
        ~Wrap();
        Object *getContent() const;
        void openMe();
        void closeMe();
        bool isOpen() const;
        Object *takeContent();
        bool wrapMeThat(Object *obj);
        virtual Object *isTaken();
    protected:
        bool m_isOpen;
        Object *m_content;
};

#endif /* !WRAP_HPP_ */