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

#include "types.hpp"

namespace nts {
class Parser {
public:
    explicit Parser(const std::string &filename) noexcept;

    Parser(const Parser &parser) noexcept = delete;

    ~Parser() noexcept = default;

    void start();
    void parse();
    bool toggleParsingSections(std::vector<std::string> tokens, size_t &index);
    bool pushToChipsets(std::vector<std::string> tokens);
    void pushToLinks(std::vector<std::string> tokens);
    std::vector<std::pair<ChipsetType, ChipsetName>>
        getChipsets() const noexcept;

    std::vector<Link> getLinks() const noexcept;

    class ParserFileException: public std::exception {
    public :
        explicit ParserFileException(std::string what): _what(std::move(what))
        {}

        explicit ParserFileException() = default;

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

    std::ifstream _stream;
    std::string _filename;
    bool _parsingComponentsSection;
    bool _parsingLinksSection;
    std::size_t _currentLineIndex = 0;
    std::string _currentLine;
    std::vector<std::pair<ChipsetType, ChipsetName>> _chipsets;
    std::vector<Link> _links;
};

}
#endif
