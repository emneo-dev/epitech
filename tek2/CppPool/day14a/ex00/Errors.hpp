/*
** EPITECH PROJECT, 2021
** Day14A
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
public:
    NasaError(std::string const &message, std::string const &component);
    std::string const &getComponent() const;
protected:
    std::string     _component;
private:
    std::string _message;
};

class MissionCriticalError : public NasaError
{
public:
    MissionCriticalError(std::string const &message, std::string const &component);
};

class LifeCriticalError : public NasaError
{
public:
    LifeCriticalError(std::string const &message, std::string const &component);
};

class UserError : public NasaError
{
public:
    UserError(std::string const &message, std::string const &component);
};

class CommunicationError : public NasaError
{
public:
    CommunicationError(std::string const &message);
};

#endif /* !ERRORS_HPP_ */
