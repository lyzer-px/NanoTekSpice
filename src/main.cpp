/*
** EPITECH PROJECT, 2026
** Tek2
** File description:
**
*/

#include "Core.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Invalid argument count" << std::endl;
        return 84;
    }
    try {
        nts::Core core(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
