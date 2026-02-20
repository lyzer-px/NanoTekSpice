/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ShellCommandNotFound
*/

#ifndef NANOTEKSPICE_SHELLCOMMANDNOTFOUND_HPP
#define NANOTEKSPICE_SHELLCOMMANDNOTFOUND_HPP

#include <exception>
#include <string>

namespace shell {
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
}

#endif // NANOTEKSPICE_SHELLCOMMANDNOTFOUND_HPP
