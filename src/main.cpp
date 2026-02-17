/*
** EPITECH PROJECT, 2026
** Tek2
** File description:
**
*/

#include <iostream>

#include "False.hpp"
#include "IComponent.hpp"
#include "Input.hpp"
#include "NtsShell.hpp"
#include "Output.hpp"
#include "Shell.hpp"
#include "True.hpp"

int main(int, char **)
{
    auto input = std::unique_ptr<nts::IComponent>(new nts::False("in"));
    nts::Circuit circuit("Circuit");

    std::clog << "Input state: " << input->compute(1) << std::endl;
    auto shell = nts::NtsShell();
    shell.run();
    return 84;
}
