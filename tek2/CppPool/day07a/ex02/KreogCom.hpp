/*
** EPITECH PROJECT, 2021
** Day07A
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

class KreogCom {
public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();

    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom *getCom();

    void ping() const;
    void locateSquad() const;
protected:
private:
    const int m_serial;
    int _x;
    int _y;
    KreogCom *_next;
};

#endif /* !KREOGCOM_HPP_ */
