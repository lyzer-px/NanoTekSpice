/*
** EPITECH PROJECT, 2026
** Tek2
** File description:
**
*/

#include "Shell.hpp"

int main(int, char **)
{
    Shell<IDefaultShellCommand> shell;
    shell.run();
    return 84;
}
