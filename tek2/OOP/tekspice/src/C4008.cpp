/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** C4008
*/

#include "C4008.hpp"
#include "Factory.hpp"

namespace nts
{
    C4008::C4008()
    {
        _totalPins.push_back({1, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({2, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({3, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({4, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({5, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({6, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({7, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({9, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({15, nts::Tristate::UNDEFINED, nullptr, 0, 0});

        _totalPins.push_back({10, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({11, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({12, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({13, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({14, nts::Tristate::UNDEFINED, nullptr, 0, 0});

        auto _factory = nts::Factory();
        _components[0] = std::move(_factory.createComponent("CNOT"));
        _components[1] = std::move(_factory.createComponent("CNOR"));
        _components[2] = std::move(_factory.createComponent("CNAND"));
        _components[3] = std::move(_factory.createComponent("CNOR"));
        _components[4] = std::move(_factory.createComponent("CNAND"));
        _components[5] = std::move(_factory.createComponent("CNOR"));
        _components[6] = std::move(_factory.createComponent("CNAND"));
        _components[7] = std::move(_factory.createComponent("CNOR"));
        _components[8] = std::move(_factory.createComponent("CNAND"));

        _components[9] = std::move(_factory.createComponent("CNOT"));
        _components[10] = std::move(_factory.createComponent("CNOT"));
        _components[11] = std::move(_factory.createComponent("CAND"));
        _components[12] = std::move(_factory.createComponent("CAND"));
        _components[13] = std::move(_factory.createComponent("CNOT"));
        _components[14] = std::move(_factory.createComponent("CAND"));
        _components[15] = std::move(_factory.createComponent("CAND")); // AND 3 inputs
        _components[16] = std::move(_factory.createComponent("CAND")); // AND 3 inputs

        _components[17] = std::move(_factory.createComponent("CAND"));

        _components[18] = std::move(_factory.createComponent("CNOT")); //
        _components[19] = std::move(_factory.createComponent("CAND")); // not a AND b

        _components[20] = std::move(_factory.createComponent("CAND")); //AND 4inputs
        _components[21] = std::move(_factory.createComponent("CAND")); //AND 4inputs
        _components[22] = std::move(_factory.createComponent("CAND")); //AND 4inputs

        _components[23] = std::move(_factory.createComponent("CAND")); // AND 3 inputs
        _components[24] = std::move(_factory.createComponent("CAND")); // AND 3 inputs

        _components[25] = std::move(_factory.createComponent("CAND")); // AND 2 inputs

        _components[26] = std::move(_factory.createComponent("CNOT")); //
        _components[27] = std::move(_factory.createComponent("CAND")); // not a AND b

        _components[28] = std::move(_factory.createComponent("CAND")); //AND 5inputs
        _components[29] = std::move(_factory.createComponent("CAND")); //AND 5inputs
        _components[30] = std::move(_factory.createComponent("CAND")); //AND 5inputs
        _components[31] = std::move(_factory.createComponent("CAND")); //AND 5inputs

        _components[32] = std::move(_factory.createComponent("CAND")); //AND 4inputs
        _components[33] = std::move(_factory.createComponent("CAND")); //AND 4inputs
        _components[34] = std::move(_factory.createComponent("CAND")); //AND 4inputs

        _components[35] = std::move(_factory.createComponent("CAND")); // AND 3 inputs
        _components[36] = std::move(_factory.createComponent("CAND")); // AND 3 inputs

        _components[37] = std::move(_factory.createComponent("CAND"));

        _components[38] = std::move(_factory.createComponent("CXOR"));

        _components[39] = std::move(_factory.createComponent("CNOR"));
        _components[40] = std::move(_factory.createComponent("CXOR"));

        _components[41] = std::move(_factory.createComponent("CNOR"));
        _components[42] = std::move(_factory.createComponent("CNOR")); // NOR 3 imputs
        _components[43] = std::move(_factory.createComponent("CXOR"));

        _components[44] = std::move(_factory.createComponent("CNOR"));
        _components[45] = std::move(_factory.createComponent("CNOR"));
        _components[46] = std::move(_factory.createComponent("CNOR")); // NOR 4 imputs
        _components[47] = std::move(_factory.createComponent("CXOR"));

        _components[48] = std::move(_factory.createComponent("CNOR"));
        _components[49] = std::move(_factory.createComponent("CNOR"));
        _components[50] = std::move(_factory.createComponent("CNOR"));
        _components[51] = std::move(_factory.createComponent("CNOR")); // NOR 5 imputs

        _components[0]->setLink(1, *this, 9);

        _components[1]->setLink(1, *this, 7);
        _components[1]->setLink(2, *this, 6);

        _components[2]->setLink(1, *this, 7);
        _components[2]->setLink(2, *this, 6);

        _components[3]->setLink(1, *this, 5);
        _components[3]->setLink(2, *this, 4);

        _components[4]->setLink(1, *this, 5);
        _components[4]->setLink(2, *this, 4);

        _components[5]->setLink(1, *this, 3);
        _components[5]->setLink(2, *this, 2);

        _components[6]->setLink(1, *this, 3);
        _components[6]->setLink(2, *this, 2);

        _components[7]->setLink(1, *this, 1);
        _components[7]->setLink(2, *this, 15);

        _components[8]->setLink(1, *this, 1);
        _components[8]->setLink(2, *this, 15);

        _components[9]->setLink(1, *(_components[0]), 2);

        _components[10]->setLink(1, *_components[1], 3);

        _components[11]->setLink(1, *_components[10], 2);
        _components[11]->setLink(2, *_components[2], 3);

        _components[12]->setLink(1, *_components[0], 2);
        _components[12]->setLink(2, *_components[2], 3);

        _components[13]->setLink(1, *_components[3], 3);

        _components[14]->setLink(1, *_components[13], 2);
        _components[14]->setLink(2, *_components[4], 3);

        _components[15]->setLink(1, *_components[0], 2);
        _components[15]->setLink(2, *_components[2], 3);
        _components[16]->setLink(1, *_components[15], 3);
        _components[16]->setLink(2, *_components[4], 3); //AND 3 inputs

        _components[17]->setLink(1, *_components[4], 3);
        _components[17]->setLink(2, *_components[1], 3);

        _components[18]->setLink(1, *_components[5], 3);
        _components[19]->setLink(1, *_components[18], 2);
        _components[19]->setLink(2, *_components[6], 3); //not a AND b

        _components[20]->setLink(1, *_components[0], 2);
        _components[20]->setLink(2, *_components[2], 3);
        _components[21]->setLink(1, *_components[4], 3);
        _components[21]->setLink(2, *_components[6], 3);
        _components[22]->setLink(1, *_components[20], 3);
        _components[22]->setLink(2, *_components[21], 3); //a AND b AND c AND d

        _components[23]->setLink(1, *_components[4], 3);
        _components[23]->setLink(2, *_components[6], 3);
        _components[24]->setLink(1, *_components[23], 3);
        _components[24]->setLink(2, *_components[1], 3); //a AND b AND c

        _components[25]->setLink(1, *_components[6], 3);
        _components[25]->setLink(2, *_components[3], 3); //a AND b

        _components[26]->setLink(1, *_components[7], 3);
        _components[27]->setLink(1, *_components[26], 2);
        _components[27]->setLink(2, *_components[8], 3); //not a AND b

        _components[28]->setLink(1, *_components[0], 2);
        _components[28]->setLink(2, *_components[2], 3);
        _components[29]->setLink(1, *_components[4], 3);
        _components[29]->setLink(2, *_components[6], 3);
        _components[30]->setLink(1, *_components[28], 3);
        _components[30]->setLink(2, *_components[29], 3);
        _components[31]->setLink(1, *_components[30], 3);
        _components[31]->setLink(2, *_components[8], 3); //a AND b AND c AND d AND e

        _components[32]->setLink(1, *_components[4], 3);
        _components[32]->setLink(2, *_components[6], 3);
        _components[33]->setLink(1, *_components[8], 3);
        _components[33]->setLink(2, *_components[3], 3);
        _components[34]->setLink(1, *_components[32], 3);
        _components[34]->setLink(2, *_components[33], 3); //a AND b AND c AND d

        _components[35]->setLink(1, *_components[6], 3);
        _components[35]->setLink(2, *_components[8], 3);
        _components[36]->setLink(1, *_components[35], 3);
        _components[36]->setLink(2, *_components[3], 3); //AND 3 inputs

        _components[37]->setLink(1, *_components[8], 3);
        _components[37]->setLink(2, *_components[5], 3); //a AND b

        _components[38]->setLink(1, *_components[9], 2);
        _components[38]->setLink(2, *_components[11], 3);
        setLink(10, *_components[38], 3); //end

        _components[39]->setLink(1, *_components[12], 3);
        _components[39]->setLink(2, *_components[1], 3);

        _components[40]->setLink(1, *_components[39], 3);
        _components[40]->setLink(2, *_components[14], 3);
        setLink(11, *_components[40], 3); //end

        _components[41]->setLink(1, *_components[16], 3);
        _components[41]->setLink(2, *_components[17], 3);
        _components[42]->setLink(1, *_components[41], 3);
        _components[42]->setLink(2, *_components[3], 3);
        _components[43]->setLink(1, *_components[42], 3);
        _components[43]->setLink(2, *_components[19], 3);
        setLink(12, *_components[43], 3); //end

        _components[44]->setLink(1, *_components[22], 3);
        _components[44]->setLink(2, *_components[24], 3);
        _components[45]->setLink(1, *_components[25], 3);
        _components[45]->setLink(2, *_components[5], 3);
        _components[46]->setLink(1, *_components[44], 3);
        _components[46]->setLink(2, *_components[45], 3);
        _components[47]->setLink(1, *_components[46], 3);
        _components[47]->setLink(2, *_components[27], 3);
        setLink(13, *_components[47], 3); //end

        _components[48]->setLink(1, *_components[31], 3);
        _components[48]->setLink(2, *_components[34], 3);
        _components[49]->setLink(1, *_components[36], 3);
        _components[49]->setLink(2, *_components[37], 3);
        _components[50]->setLink(1, *_components[48], 3);
        _components[50]->setLink(2, *_components[49], 3);
        _components[51]->setLink(1, *_components[50], 3);
        _components[51]->setLink(2, *_components[7], 3);
        setLink(14, *_components[51], 3); //end
    }

    void C4008::simulate(std::size_t tick)
    {
        for (size_t i = 0; i < _totalPins.size(); i++)
            updatePin(_totalPins[i].id, tick);
    }

    void C4008::dump() const
    {
        for (const auto &totalPin : _totalPins)
        {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
        std::cout << getPinState(9) << "  " << getPinState(7) << "  " << getPinState(6) << std::endl;
    }
}