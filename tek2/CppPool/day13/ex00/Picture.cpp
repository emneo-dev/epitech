//
// Created by huntears on 1/18/21.
//

#include <fstream>

#include "Picture.hpp"

bool Picture::getPictureFromFile(const std::string &file) {
    std::ifstream stream(file.c_str());
    std::string tmp;
    if (!stream) {
        this->data = "ERROR";
        return false;
    }
    this->data = "";
    while (getline(stream, tmp, '\0'))
        this->data += tmp;
    stream.close();
    return true;
}

Picture::Picture(const std::string &file) {
    this->getPictureFromFile(file);
}

Picture::Picture() {
    this->data = "";
}
