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

namespace nts {

using ChipsetName = std::string;
using ChipsetType = std::string;
using PinNumber   = std::size_t;
using Token       = std::string;

struct Link {
    Link(const ChipsetName &chipset1Name, const std::string &chipset1Pin,
        const ChipsetName &chipset2Name, const std::string &chipset2Pin);

    std::pair<ChipsetName, PinNumber> component1;
    std::pair<ChipsetName, PinNumber> component2;
};

class Parser {
public:
    explicit Parser(const std::string &filename) noexcept;

    Parser(const Parser &parser) noexcept = delete;

    ~Parser() noexcept
    {};

    void start();

    std::vector<std::pair<ChipsetType, ChipsetName>>
        getChipsets() const noexcept;

    std::vector<Link> getLinks() const noexcept;

    class ParserFileException: public std::exception {
    public :
        explicit ParserFileException(std::string what): _what(std::move(what))
        {}

        explicit ParserFileException()
        {}

        const char *what() const noexcept override
        {
            return _what.empty() ? std::strerror(errno) : _what.c_str();
        }

    private:
        std::string _what;
    };

    class ParserSyntaxException: public std::exception {
    public :
        explicit ParserSyntaxException(std::string what): _what(std::move(what))
        {}

        const char *what() const noexcept override
        {
            return _what.c_str();
        }

    private:
        std::string _what;
    };

private:
    void verifyLinkSyntax(const std::vector<std::string> &left,
        const std::vector<std::string> &right);

    void verifyChipsetSyntax(const std::vector<std::string> &tokens);

    bool componentExists(const std::string &str);

    std::vector<std::pair<ChipsetType, ChipsetName>> _chipsets;
    std::vector<Link> _links;
    std::ifstream _stream;
    bool _parsingComponentsSection;
    bool _parsingLinksSection;
    bool _badExtention;
};

}
#endif
