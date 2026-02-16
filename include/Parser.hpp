/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef PARSER_HPP
    #define PARSER_HPP

#include <cerrno>
#include <cstring>
#include <exception>
#include <fstream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <linux/limits.h>
#include "IComponent.hpp"

namespace nts {

using chipsetName = std::string;
using chipsetType = std::string;
using pin = std::size_t;
using Component = std::string;
using token = std::string;

class Parser {
public:

    struct Link {
        Link(chipsetName c1_name, std::string c1_pin, chipsetName c2_name, std::string c2_pin) {
            this->component1.first = c1_name;
            this->component1.second = std::stoul(c1_pin);
            this->component2.first = c2_name;
            this->component2.second = std::stoul(c2_pin);
        }
        std::pair<chipsetName, pin> component1;
        std::pair<chipsetName, pin> component2;
    };

    explicit Parser(const std::string &filename) noexcept;
    Parser(const Parser &parser) noexcept = delete;

    ~Parser() noexcept {};

    void start();

    std::vector<std::pair<Component, chipsetName>> getChipsets() const noexcept;
    std::vector<Link> getLinks() const noexcept;
   
    class ParserFileException : public std::exception {
    public :
        explicit ParserFileException(std::string what) : _what(what) {}
        explicit ParserFileException() {}

        const char *what() const noexcept override {
            return _what.empty() ? std::strerror(errno) : _what.c_str();
        }
    private:
        std::string _what;
    };

    class ParserSyntaxException : public std::exception {
    public :
        explicit ParserSyntaxException(std::string what) : _what(what) {}

        const char *what() const noexcept override {
            return _what.c_str();
        }
    private:
        std::string _what;
    };

private:
    void verifySyntax(std::vector<std::string> vec);
    void verifyLinkSyntax(std::vector<std::string> left, std::vector<std::string> right);
    void verifyChipsetSyntax(std::vector<std::string> tokens);
    void verifySyntax(std::string str);

    std::vector<std::pair<Component, chipsetName>> _chipsets;
    std::vector<Link> _links;
    std::ifstream _stream;
    bool parsing_components_section = false;
    bool parsing_links_section = false;
    bool bad_extention = false;
};

}
#endif
