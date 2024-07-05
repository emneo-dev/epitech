/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** Exam
*/

#ifndef EXAM_HPP_
#define EXAM_HPP_

class Exam {
public:
    Exam(bool *cheat);

    static bool cheat;
    void start(int enemies);
    bool isCheating();
    void (Exam::*kobayashiMaru)(int);
protected:
private:
    bool *myCheat;
};

#endif /* !EXAM_HPP_ */
