/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsSimulateCommand
*/

#ifndef NANOTEKSPICE_NTSSIMULATECOMMAND_HPP
#define NANOTEKSPICE_NTSSIMULATECOMMAND_HPP

#include <memory>

#include "shell/IShellCommand.hpp"

namespace nts {
class NtsSimulateCommand: public shell::IShellCommand {
public:
    NtsSimulateCommand() = default;

    ~NtsSimulateCommand() override = default;

    bool operator()(shell::Shell &shell, std::vector<std::string> cmd) override;

    bool execute(shell::Shell &shell, std::vector<std::string> cmd) override;

    static std::unique_ptr<IShellCommand> create();
};
} // nts

#endif //NANOTEKSPICE_NTSSIMULATECOMMAND_HPP
