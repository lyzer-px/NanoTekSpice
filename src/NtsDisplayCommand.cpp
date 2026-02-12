/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsDisplayCommand
*/

#include "../include/NtsDisplayCommand.hpp"

#include <iostream>

namespace nts {
bool NtsDisplayCommand::operator()(Circuit &circuit,
    std::vector<std::string> cmd)
{
    std::clog << "Nts display command" << std::endl;
    return true;
}

bool NtsDisplayCommand::execute(Circuit &circuit, std::vector<std::string> cmd)
{
    return operator ()(circuit, cmd);
}

std::unique_ptr<INtsCommand> NtsDisplayCommand::create()
{
    return std::unique_ptr<INtsCommand>(new NtsDisplayCommand());
}
} // nts
