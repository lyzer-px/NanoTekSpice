/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CustomParser
*/

#ifndef NANOTEKSPICE_CUSTOMPARSER_HPP
#define NANOTEKSPICE_CUSTOMPARSER_HPP

#include <fstream>
#include <string>
#include <vector>

#include "types.hpp"

namespace nts {

class CustomParser {
public:
    CustomParser() noexcept;

    explicit CustomParser(std::string filename) noexcept;

    void parse();

    void parse(const std::string &filename);

    ParsedChipsets getChipsets() const noexcept;

    std::vector<Link> getLinks() const noexcept;

private:
    std::string _filename;
    ParsedChipsets _chipsets;
    std::vector<Link> _links;
    std::ifstream _stream;
    std::string _line;
    std::size_t _lineNumber = 0;

    void openFile();

    std::vector<std::string> preprocessLine();

    void findChipsetCommand();

    static std::string sanitize(std::string &str);

    void checkChipsetType(const std::vector<std::string> &words);

    bool checkChipsetName(const std::vector<std::string> &words);

    void parseChipsets();

    void checkLink(bool isFirst, const std::string &str);

    void parseLinks();
};

} // namespace nts

#endif // NANOTEKSPICE_CUSTOMPARSER_HPP
