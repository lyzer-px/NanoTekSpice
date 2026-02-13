/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Shell
*/

#include "Shell.hpp"

#include <iostream>

#include "ShellCommandNotFound.hpp"
#include "ShellExit.hpp"
#include "ShellExitException.hpp"

namespace shell {
Shell::Shell(): _name{"default_shell"},
    _prompt{"> "}
{
    _shellCommandFactory.registerCreator<ShellExit>("exit");
}

Shell::Shell(std::string name, std::string prompt): _name
    {std::move(name)},
    _prompt{std::move(prompt)}
{
    _shellCommandFactory.registerCreator<ShellExit>("exit");
}

Shell::Shell(std::string prompt): _name{"default_shell"},
    _prompt{std::move(prompt)}
{
    _shellCommandFactory.registerCreator<ShellExit>("exit");
}

void Shell::run()
{
    std::string line;

    while (true) {
        std::cout << _prompt;
        if (!std::getline(std::cin, line)) {
            std::cout << std::endl;
            return;
        }
        if (isEmptyLine(line)) {
            continue;
        }
        std::vector<std::string> cmd = split(line, ' ');

        try {
            const auto command = _shellCommandFactory.create(cmd[0]);
            command->execute(*this, cmd);
        } catch (std::runtime_error &e) {
            try {
                executeExternCommand(cmd);
            } catch (const ShellCommandNotFound &except) {
                std::cerr << except.what() << std::endl;
            }
        } catch (const ShellExitException &) {
            return;
        }
    }
}

bool Shell::executeExternCommand(const std::vector<std::string> &cmd)
{
    try {
        const auto command = _shellCommandFactory.create(cmd[0]);
        return command->execute(*this, cmd);
    } catch (const std::exception &e) {
        throw ShellCommandNotFound(cmd[0]);
    }
}

bool isEmptyLine(const std::string &line) noexcept
{
    std::stringstream sstream{line};
    std::string temp;

    return !(sstream >> temp);
}
}

std::vector<std::string> split(const std::string &line, const char delim)
{
    std::stringstream sstream{line};
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(sstream, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}
