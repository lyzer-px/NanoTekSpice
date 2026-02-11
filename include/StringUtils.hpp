/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef STRING_UTILS_HPP
    #define STRING_UTILS_HPP

#include <string>
#include <regex>
#include <vector>
#include <sstream>

namespace strutils {

inline std::vector<std::string> splitStr(std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream stream(str);
    std::string token;

    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

inline void sanitize(std::string &str)
{
    std::regex whitespaces("[\\s]+");
    str = std::regex_replace(str, whitespaces, " ");
}

}

#endif
