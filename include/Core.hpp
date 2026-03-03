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
#include "parser/Parser.hpp"
#include "parser/CustomParser.hpp"
#include "shell/NtsShell.hpp"
#include "components/Circuit.hpp"
#include "components/IComponent.hpp"

namespace nts {
class Core {
public:
    explicit Core(const std::string &filename) noexcept;
    explicit Core(Core &core) noexcept = delete;

    void run();
private:
    Parser _parser;
    CustomParser _customParser;
    std::unique_ptr<NtsShell> _shell;
    std::unique_ptr<IComponent> _circuit;
};
}
#endif // NANOTEKSPICE_CORE_HPP
