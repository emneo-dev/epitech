//
// Created by huntears on 1/18/21.
//

#ifndef EX00_PICTURE_HPP
#define EX00_PICTURE_HPP

#include <iostream>

class Picture {
public:
    std::string data;
    bool getPictureFromFile(const std::string &file);
    Picture(const std::string &file);
    Picture();
    ~Picture();
    Picture(const Picture &obj);
    Picture& operator =(const Picture &obj);
};


#endif //EX00_PICTURE_HPP
