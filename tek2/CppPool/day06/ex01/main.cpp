/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** main
*/

#include <iomanip>
#include <iostream>

static void far_to_cel(float temp)
{
    std::cout << std::fixed << std::setprecision(3) << std::setw(16) << (temp - 32) / 1.8 << std::setw(16) << "Celsius" << std::endl;
}

static void cel_to_far(float temp)
{
    std::cout << std::fixed << std::setprecision(3) << std::setw(16) << temp * 9 / 5 + 32 << std::setw(16) << "Fahrenheit" << std::endl;
}

int main(void)
{
    std::string input;
    std::string scale;
    std::string temp_str;
    float temp;

    std::cin >> temp_str >> scale;
    temp = std::stod(temp_str, nullptr);
    if (scale == "Celsius")
        cel_to_far(temp);
    else if (scale == "Fahrenheit")
        far_to_cel(temp);
    else
        return 1;
    return 0;
}