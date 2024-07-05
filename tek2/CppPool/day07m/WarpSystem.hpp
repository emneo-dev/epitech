/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor
    {
    private:
        bool _stability;
    public:
        QuantumReactor();

        bool isStable();
        void setStability(bool stability);
    };

    class Core
    {
    private:
        QuantumReactor *_coreReactor;
    public:
        Core(QuantumReactor *coreReactor);

        QuantumReactor *checkReactor();
    };
}

#endif /* !WARPSYSTEM_HPP_ */
