/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef NANOTEKSPICE_CORE_HPP
    #define NANOTEKSPICE_CORE_HPP

#include <memory>
#include <string>
#include "Parser.hpp"
#include "NtsShell.hpp"
#include "Circuit.hpp"
#include "IComponent.hpp"

namespace nts {
class Core {
public:
    explicit Core(const std::string &filename) noexcept;
    explicit Core(Core &core) noexcept = delete;

    void run();
private:
    Parser _parser;
    std::unique_ptr<NtsShell> _shell;
    std::unique_ptr<IComponent> _circuit;
};
}
#endif // NANOTEKSPICE_CORE_HPP
