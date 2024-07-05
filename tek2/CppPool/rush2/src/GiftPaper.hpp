/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "Wrap.hpp"

class GiftPaper : public Wrap {
    public:
        GiftPaper();
        GiftPaper(const std::string &title);
        virtual ~GiftPaper();
        virtual bool wrapMeThat(Object* obj);
    protected:
    private:
};

#endif /* !GIFTPAPER_HPP_ */
