//
// Created by kotti on 22/02/2026.
//

#include "../../include/Exception/FileNotFoundException.hpp"

namespace nts {
namespace error {
const char * FileNotFoundException::what() const noexcept
{
    return "File not found";
}
} // error
} // nts