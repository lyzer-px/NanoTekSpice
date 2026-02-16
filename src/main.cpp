/*
** EPITECH PROJECT, 2026
** Tek2
** File description:
**
*/

#include "NtsShell.hpp"
#include "Shell.hpp"

int main(int, char **)
{
    auto shell = nts::NtsShell();
    shell.run();
    return 84;
}
