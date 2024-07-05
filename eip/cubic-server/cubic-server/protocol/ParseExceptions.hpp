#ifndef CUBICSERVER_PROTOCOL_PARSEEXCEPTIONS_HPP
#define CUBICSERVER_PROTOCOL_PARSEEXCEPTIONS_HPP

#include "exceptions.hpp"

namespace protocol {
DEFINE_EXCEPTION(VarIntOverflow);
DEFINE_EXCEPTION(PacketEOF);
DEFINE_EXCEPTION(ZeroLengthString);
DEFINE_EXCEPTION(MaxLengthString);
DEFINE_EXCEPTION(OutOfRangeEnum);
DEFINE_EXCEPTION(OutOfRangeBoolean);
DEFINE_EXCEPTION(WrongObjectType);
}

#endif // CUBICSERVER_PROTOCOL_PARSEEXCEPTIONS_HPP