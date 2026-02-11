/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef PARSER_HPP
    #define PARSER_HPP

#include <string>
#include <utility>
#include <vector>
#include "IComponent.hpp"

namespace nts {

using chipsetName = std::string;
using chipsetType = std::string;
using pin = std::size_t;

class Parser {
public:

    struct Link
    {
        std::pair<chipsetName, pin> component1;
        std::pair<chipsetName, pin> component2;
    };

    explicit Parser() noexcept;
    ~Parser() noexcept {}
    void parse(const std::string &filename);
    std::vector<std::pair<IComponent&, chipsetName>> get_chipsets() const noexcept;
    std::vector<Link> get_links() const noexcept;

private:
    std::vector<std::pair<IComponent, chipsetName>> _chipsets;
    std::vector<Link> _links;
};

}
#endif
