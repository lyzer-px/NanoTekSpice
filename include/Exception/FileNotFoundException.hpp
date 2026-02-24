//
// Created by kotti on 22/02/2026.
//

#ifndef NANOTEKSPICE_FILENOTFOUNDEXCEPTION_HPP
#define NANOTEKSPICE_FILENOTFOUNDEXCEPTION_HPP

#include <exception>

namespace nts {
namespace error {
class FileNotFoundException: public std::exception {
public:
    const char *what() const noexcept override;
};
} // error
} // nts

#endif //NANOTEKSPICE_FILENOTFOUNDEXCEPTION_HPP