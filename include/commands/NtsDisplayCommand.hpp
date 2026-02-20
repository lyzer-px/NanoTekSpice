/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsDisplayCommand
*/

#ifndef NANOTEKSPICE_NTSDISPLAYCOMMAND_HPP
#define NANOTEKSPICE_NTSDISPLAYCOMMAND_HPP

#include <memory>

#include "shell/IShellCommand.hpp"

namespace nts {
class NtsDisplayCommand: public shell::IShellCommand {
public:
    NtsDisplayCommand() = default;

    ~NtsDisplayCommand() override = default;

    bool operator()(shell::Shell &shell, std::vector<std::string> cmd) override;

    bool execute(shell::Shell &shell, std::vector<std::string> cmd) override;

    static std::unique_ptr<IShellCommand> create();
};
} // nts

#endif //NANOTEKSPICE_NTSDISPLAYCOMMAND_HPP
