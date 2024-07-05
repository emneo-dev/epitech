/*
** EPITECH PROJECT, 2021
** Day07A
** File description:
** Phaser
*/

#ifndef PHASER_HPP_
#define PHASER_HPP_

class Ammo;

class Phaser {
public:
    enum AmmoType {
        Regular,
        Plasma,
        Rocket
    };

    Phaser(int maxAmmo = 20, AmmoType type = AmmoType::Regular);
    ~Phaser();

    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);

    int getCurrentAmmos() const;

protected:
private:
    const int m_maxAmmo;
    Ammo *m_ammo;
    AmmoType m_defaultType;

    static const int Empty;
};

class Ammo {
public:
    Ammo(Phaser::AmmoType type);
    Ammo *next;
    Phaser::AmmoType type;
};

#endif /* !PHASER_HPP_ */
