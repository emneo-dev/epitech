/*
** EPITECH PROJECT, 2021
** DRAWINFO
** File description:
** DrawInfo header
*/

#ifndef DRAWINFO_H_
#define DRAWINFO_H_

class DrawInfo
{
public:
    DrawInfo()
    {
        _x = 0;
        _y = 0;
        _width = 0;
        _height = 0;
    }
    DrawInfo(int x, int y, int width, int height)
    {
        _x = x;
        _y = y;
        _width = width;
        _height = height;
    }
    DrawInfo(const DrawInfo &drawInfo)
    {
        *this = drawInfo;
    }
    DrawInfo &operator=(const DrawInfo &drawInfo)
    {
        _x = drawInfo.getX();
        _y = drawInfo.getY();
        _width = drawInfo.getWidth();
        _height = drawInfo.getHeight();
        return *this;
    }
    DrawInfo(const DrawInfo &info, int pad)
    {
        _x = info.getX() + pad;
        _y = info.getY() + pad;
        _width = info.getWidth() - pad * 2;
        _height = info.getHeight() - pad * 2;
    }

    int getX() const { return _x; }
    int getY() const { return _y; }
    int getWidth() const { return _width; }
    int getHeight() const { return _height; }
    void setX(int x) { _x = x; }
    void setY(int y) { _y = y; }
    void setWidth(int width) { _width = width; }
    void setHeight(int height) { _height = height; }

protected:
    int _x;
    int _y;
    int _width;
    int _height;
};

#endif /* !DRAWINFO_H_ */