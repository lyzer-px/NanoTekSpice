/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Shell
*/

#ifndef NANOTEKSPICE_SHELL_HPP
#define NANOTEKSPICE_SHELL_HPP

#include <string>

#include "FactoryTemplate.hpp"
#include "IShellCommand.hpp"

namespace shell {
class Shell {
public:
    using ExternCommandFactory = FactoryTemplate<IShellCommand, std::string>;
    using ShellCommandFactory  = FactoryTemplate<IShellCommand, std::string>;

    Shell();

    virtual ~Shell() = default;

    explicit Shell(std::string name, std::string prompt);

    explicit Shell(std::string prompt);

    void run();

protected:
    std::string _name;
    std::string _prompt;
    // ExternCommandFactory _externCommandFactory;
    ShellCommandFactory _shellCommandFactory;

    virtual bool executeExternCommand(const std::vector<std::string> &cmd);
};

bool isEmptyLine(const std::string &line) noexcept;
}

bool isEmptyLine(const std::string &line) noexcept;

std::vector<std::string> split(const std::string &line, const char delim);

#endif //NANOTEKSPICE_SHELL_HPP
