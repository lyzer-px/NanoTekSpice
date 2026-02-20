/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsSetInputCommand
*/

#ifndef NANOTEKSPICE_NTSSETINPUTCOMMAND_HPP
#define NANOTEKSPICE_NTSSETINPUTCOMMAND_HPP

#include <memory>

#include "IShellCommand.hpp"

namespace nts {
class NtsSetInputCommand: public shell::IShellCommand {
public:
    NtsSetInputCommand() = default;

    ~NtsSetInputCommand() override = default;

    bool operator()(shell::Shell &shell, std::vector<std::string> cmd) override;

    bool execute(shell::Shell &shell, std::vector<std::string> cmd) override;

    static std::unique_ptr<IShellCommand> create();
};
} // nts

#endif //NANOTEKSPICE_NTSSETINPUTCOMMAND_HPP