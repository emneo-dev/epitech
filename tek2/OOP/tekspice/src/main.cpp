#include <iostream>
#include "C4001.hpp"
#include "C4069.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "CAND.hpp"
#include "CNAND.hpp"
#include "CNOR.hpp"
#include "COR.hpp"
#include "CXOR.hpp"
#include "CTrue.hpp"
#include "CFalse.hpp"
#include "IComponent.hpp"
#include "C4008.hpp"
#include <map>

#include "../include/Factory.hpp"

int main()
{
    auto test = nts::C4008();
    auto n = nts::CTrue();
    auto o = nts::CFalse();
    test.setLink(9, o, 1);
    test.setLink(7, o, 1);
    test.setLink(6, o, 1);
    test.simulate(1);
    test.dump();
    auto c = nts::C4001();
    ////auto d = C4069();
    ////auto e = C4011();
    ////auto f = C4030();
    ////auto g = C4071();
    ////auto h = C4081();
    auto i = nts::CAND();
    ////auto j = CNAND();
    ////auto NOR1 = CNOR();
    ////NOR1.setLink(1, n, 1);
    ////NOR1.setLink(2, n, 1);
    ////NOR1.simulate(0);
    ////NOR1.dump();
    c.setLink(1, n, 1);
    c.setLink(2, n, 1);
    c.simulate(1);
    c.dump();
    i.setLink(1, n, 1);
    i.setLink(2, n, 1);
    i.simulate(1);
    i.dump();
    //j.setLink(1, n, 1);
    //j.setLink(2, o, 1);
    //j.simulate(0);

    //i.setLink(3, j, 1);
    //j.setLink(1, i, 3);

    //c.dump();
    //d.dump();
    //e.dump();
    //f.dump();
    //g.dump();
    //h.dump();
    //i.dump();
    //j.dump();
    ////    //d.getPin(1).state = nts::Tristate::CTrue;
    //    //d.getPin(2).state = nts::Tristate::CTrue;
    //    //d.setLink(1, c, 5);
    //    //d.setLink(2, c, 6);
    //    //d.setLink(3, c, 7);
    //    //d.setLink(4, c, 8);
    //    //d.simulate(3);
    //    ////std::cout << d.getPin(3).state << '\n';
    //    ////d.getPin(2).state = nts::Tristate::CFalse;
    //    ////d.getPin(1).state = nts::Tristate::CFalse;
    //    ////d.simulate(3);
    //    ////std::cout << d.getPin(3).state << '\n';
    //    ////d.getPin(2).state = nts::Tristate::CTrue;
    //    ////d.getPin(1).state = nts::Tristate::CFalse;
    //    ////d.simulate(3);
    //    ////std::cout << d.getPin(3).state << '\n';
    //    ////d.getPin(2).state = nts::Tristate::CFalse;
    //    ////d.getPin(1).state = nts::Tristate::CTrue;
    //    ////d.simulate(3);
    //    ////std::cout << d.getPin(3).state << '\n';
    //    ////d.getPin(2).state = nts::Tristate::CTrue;
    //    ////d.getPin(1).state = nts::Tristate::CTrue;
    //    ////d.simulate(3);
    //    ////std::cout << d.getPin(3).state << '\n';
    //    ////d.getPin(2).state = nts::Tristate::UNDEFINED;
    //    ////d.getPin(1).state = nts::Tristate::UNDEFINED;
    //    ////d.simulate(3);
    //    ////std::cout << d.getPin(3).state << '\n';
    //    ////d.getPin(2).state = nts::Tristate::UNDEFINED;
    //    ////d.getPin(1).state = nts::Tristate::CTrue;
    //    ////d.simulate(3);
    //    ////std::cout << d.getPin(3).state << '\n';
    //    ////d.getPin(2).state = nts::Tristate::UNDEFINED;
    //    ////d.getPin(1).state = nts::Tristate::CFalse;
    //    ////d.simulate(3);
    //    ////std::cout << d.getPin(3).state << '\n';
    //    //d.dump();
    //    //c.dump();
    //    //return 0;
}
