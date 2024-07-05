//
// Created by hunte on 3/6/2021.
//

#include <C4011.hpp>
#include <C4030.hpp>
#include <C4069.hpp>
#include <C4071.hpp>
#include <C4081.hpp>
#include <CNAND.hpp>
#include <CNOR.hpp>
#include <COR.hpp>
#include <CXOR.hpp>
#include <CNOT.hpp>
#include <CClock.hpp>
#include <COutput.hpp>
#include <CInput.hpp>
#include <CFalse.hpp>
#include "Factory.hpp"
#include "CTrue.hpp"
#include "CAND.hpp"
#include "CUndefined.hpp"
#include "C4001.hpp"

namespace nts
{
    std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &name) const
    {
        if (_functionCallMap.count(name) == 0)
            throw "welp";
        return std::move((this->*(_functionCallMap.at(name)))());
    }

    std::unique_ptr<nts::IComponent> Factory::createTrue() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CTrue()));
    }

    std::unique_ptr<nts::IComponent> Factory::createFalse() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CFalse()));
    }

    std::unique_ptr<nts::IComponent> Factory::createUndefined() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CUndefined()));
    }

    std::unique_ptr<nts::IComponent> Factory::createInput() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CInput()));
    }

    std::unique_ptr<nts::IComponent> Factory::createOutput() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::COutput()));
    }

    std::unique_ptr<nts::IComponent> Factory::createClock() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CClock()));
    }

    std::unique_ptr<nts::IComponent> Factory::createXOR() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CXOR()));
    }

    std::unique_ptr<nts::IComponent> Factory::createOR() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::COR()));
    }

    std::unique_ptr<nts::IComponent> Factory::createNOR() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CNOR()));
    }

    std::unique_ptr<nts::IComponent> Factory::createNAND() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CNAND()));
    }

    std::unique_ptr<nts::IComponent> Factory::createAND() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CAND()));
    }

    std::unique_ptr<nts::IComponent> Factory::create4081() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::C4081()));
    }

    std::unique_ptr<nts::IComponent> Factory::create4071() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::C4071()));
    }

    std::unique_ptr<nts::IComponent> Factory::create4069() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::C4069()));
    }

    std::unique_ptr<nts::IComponent> Factory::create4030() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::C4030()));
    }

    std::unique_ptr<nts::IComponent> Factory::create4011() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::C4011()));
    }

    std::unique_ptr<nts::IComponent> Factory::create4001() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::C4001()));
    }

    std::unique_ptr<nts::IComponent> Factory::createNOT() const noexcept
    {
        return std::move(std::unique_ptr<nts::IComponent>(new nts::CNOT()));
    }

}
