/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>

class Object
{
public:
    enum objType
    {
        BOX,
        PAPER,
        TOY
    };

    Object(objType type, std::string const &title);

    virtual ~Object();
    virtual void openMe();
    virtual void closeMe();
    virtual bool isOpen() const;
    virtual bool wrapMeThat(Object *);
    virtual Object *isTaken() = 0;
    virtual Object *getContent() const;

    objType getType() const;
    std::string getTitle() const;
    const std::string getTypeName() const;

    void setTaken(bool take);
    bool getTaken() const;

    std::string xmlObject() const;

protected:
    bool m_taken;
    std::string m_title;
    objType m_type;
    std::string enumToStringType(objType obj) const;

private:
};

std::ostream &operator<<(std::ostream &os, const Object &obj);

#endif /* !OBJECT_HPP_ */
