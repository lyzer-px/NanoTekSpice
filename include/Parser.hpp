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
using token = std::string;

class Circuit;


class Parser {
public:

    struct Link
    {
        std::pair<chipsetName, pin> component1;
        std::pair<chipsetName, pin> component2;
    };

    explicit Parser(const std::string &filename);
    Parser(const Parser &parser) noexcept = delete;

    ~Parser() noexcept;

    std::vector<std::pair<std::string, chipsetName>> getChipsets() const noexcept;

    std::vector<Link> getLinks() const noexcept;
    void setCircuit(std::shared_ptr<Circuit> ptr) {this->_circuit = ptr;}
    std::shared_ptr<Circuit> getCircuit() {return this->_circuit;}
    
    void start();
    void sanitize(std::string &str) const;
    std::vector<std::string> splitStr(std::string &str, char delimiter) const;

    void verifySyntax(std::vector<std::string> vec);
    void addToCircuit(std::vector<std::string> tokens);

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
    std::vector<std::pair<std::string, chipsetName>> _chipsets;
    std::vector<Link> _links;
    std::ifstream _stream;
    std::shared_ptr<Circuit> _circuit;
    bool has_components_section = false;
    bool has_links_section = false;
};

}
#endif
