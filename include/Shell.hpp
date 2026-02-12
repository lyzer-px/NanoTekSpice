/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Shell
*/

#ifndef NANOTEKSPICE_SHELL_HPP
#define NANOTEKSPICE_SHELL_HPP
#include <iostream>
#include <string>

#include "FactoryTemplate.hpp"
#include "IDefaultShellCommand.hpp"
#include "ShellExit.hpp"

namespace shell {
class ShellExitException: public std::exception {
public:
    ShellExitException() = default;

    ~ShellExitException() override = default;

    [[nodiscard]] const char *what() const noexcept override;
};

class ShellCommandNotFound: public std::exception {
public:
    explicit ShellCommandNotFound(const std::string &commandName): _commandName{
        commandName}
    {
        _message = _commandName + ": command not found";
    }

    ~ShellCommandNotFound() override = default;

    [[nodiscard]] const char *what() const noexcept override;

private:
    std::string _commandName;
    std::string _message;
};

template <typename CommandBase = IDefaultShellCommand>
class Shell {
public:
    using ExternCommandFactory = FactoryTemplate<CommandBase, std::string>;
    using ShellCommandFactory  = FactoryTemplate<IDefaultShellCommand,
        std::string>;

    Shell(): _name{"default_shell"},
        _prompt{"> "}
    {
        _shellCommandFactory.registerCreator("exit", ShellExit::create);
    }

    virtual ~Shell() = default;

    explicit Shell(std::string name, std::string prompt): _name
        {std::move(name)},
        _prompt{std::move(prompt)}
    {}

    explicit Shell(std::string prompt): _name{"default_shell"},
        _prompt{std::move(prompt)}
    {}

    bool isEmptyLine(const std::string &line) noexcept
    {
        std::stringstream sstream{line};
        std::string temp;

        return !(sstream >> temp);
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

    void run()
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
                auto command = _shellCommandFactory.create(cmd[0]);
                (*command)(*this, cmd);
            } catch (std::runtime_error &e) {
                try {
                    executeCommand(cmd);
                } catch (const ShellCommandNotFound &except) {
                    std::cerr << except.what() << std::endl;
                }
            } catch (const ShellExitException &) {
                return;
            }
        }
    }

protected:
    std::string _name;
    std::string _prompt;
    ExternCommandFactory _externCommandFactory;
    ShellCommandFactory _shellCommandFactory;

    virtual bool executeCommand(const std::vector<std::string> &cmd)
    {
        throw ShellCommandNotFound{cmd[0]};
    }
};

template class Shell<IDefaultShellCommand>;

bool isEmptyLine(const std::string &line) noexcept;
}

#endif //NANOTEKSPICE_SHELL_HPP
