/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** INtsCommand
*/

#ifndef NANOTEKSPICE_INTSCOMMAND_HPP
#define NANOTEKSPICE_INTSCOMMAND_HPP

#include <string>
#include <vector>

namespace nts {
class Circuit;

class INtsCommand {
public:
    INtsCommand() = default;

    virtual ~INtsCommand() = default;

    INtsCommand(const INtsCommand &) = default;

    INtsCommand &operator=(const INtsCommand &) = default;

    INtsCommand(INtsCommand &&) = default;

    INtsCommand &operator=(INtsCommand &&) = default;

    virtual bool operator()(Circuit &circuit, std::vector<std::string> cmd) = 0;

    virtual bool execute(Circuit &circuit, std::vector<std::string> cmd) = 0;
};
}

#endif // NANOTEKSPICE_INTSCOMMAND_HPP
