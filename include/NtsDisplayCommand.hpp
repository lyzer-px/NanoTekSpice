/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsDisplayCommand
*/

#ifndef NANOTEKSPICE_NTSDISPLAYCOMMAND_HPP
#define NANOTEKSPICE_NTSDISPLAYCOMMAND_HPP
#include "INtsCommand.hpp"

namespace nts {
class NtsDisplayCommand: public INtsCommand {
public:
    NtsDisplayCommand() = default;

    ~NtsDisplayCommand() override = default;

    bool operator()(Circuit &circuit, std::vector<std::string> cmd) override;

    bool execute(Circuit &circuit, std::vector<std::string> cmd) override;

    static std::unique_ptr<INtsCommand> create();
};
} // nts

#endif //NANOTEKSPICE_NTSDISPLAYCOMMAND_HPP
