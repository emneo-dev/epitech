/*
** EPITECH PROJECT, 2021
** Day14A [SSH: 192.168.0.19]
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) :
    _component(component),
    _message(message)
{}

std::string const &NasaError::getComponent() const
{
    return this->_component;
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) :
    NasaError(message, component)
{}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) :
    NasaError(message, component)
{}

UserError::UserError(std::string const &message, std::string const &component) :
    NasaError(message, component)
{}

CommunicationError::CommunicationError(std::string const &message) :
    NasaError(message, "CommunicationDevice")
{}