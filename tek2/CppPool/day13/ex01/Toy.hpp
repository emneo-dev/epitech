//
// Created by huntears on 1/18/21.
//

#ifndef EX00_TOY_HPP
#define EX00_TOY_HPP


#include <string>
#include "Picture.hpp"

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN
    };
    ToyType getType() const;
    const std::string &getName() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &filename);
    const std::string &getAscii() const;
    Toy();
    Toy(ToyType type, const std::string &name, const std::string &filename);
    Toy(const Toy &obj);
    Toy &operator =(const Toy &obj);
    ~Toy();

private:
    std::string _name;
    const ToyType _type;
    Picture _picture;
};


#endif //EX00_TOY_HPP
