/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ShellExitException
*/

#ifndef NANOTEKSPICE_SHELLEXITEXCEPTION_HPP
#define NANOTEKSPICE_SHELLEXITEXCEPTION_HPP

#include <exception>

namespace shell {
class ShellExitException: public std::exception {
public:
    ShellExitException() = default;

    ~ShellExitException() override = default;

    [[nodiscard]] const char *what() const noexcept override;
};
} // shell

#endif //NANOTEKSPICE_SHELLEXITEXCEPTION_HPP