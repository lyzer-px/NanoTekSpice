/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsLoopCommand
*/

#ifndef NANOTEKSPICE_NTSLOOPCOMMAND_HPP
#define NANOTEKSPICE_NTSLOOPCOMMAND_HPP

#include <memory>

#include "shell/IShellCommand.hpp"

namespace nts {
class NtsLoopCommand: public shell::IShellCommand {
public:
    NtsLoopCommand() = default;

    ~NtsLoopCommand() override = default;

    bool operator()(shell::Shell &shell, std::vector<std::string> cmd) override;

    bool execute(shell::Shell &shell, std::vector<std::string> cmd) override;

    static std::unique_ptr<IShellCommand> create();
};
} // nts

#endif //NANOTEKSPICE_NTSLOOPCOMMAND_HPP
