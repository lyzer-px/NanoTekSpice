//
// Created by kotti on 12/02/2026.
//

#ifndef NANOTEKSPICE_SHELLEXIT_HPP
#define NANOTEKSPICE_SHELLEXIT_HPP

#include "IDefaultShellCommand.hpp"

namespace shell {
template <typename ShellType>
class ShellExit: public IDefaultShellCommand<ShellType> {
public:
    ShellExit() = default;

    ~ShellExit() override = default;

    bool operator()(ShellType &shell,
        std::vector<std::string> cmd) override;

    bool execute(ShellType &shell,
        std::vector<std::string> cmd) override;

    static std::unique_ptr<IDefaultShellCommand<ShellType>> create();
};
}

#include "../src/ShellExit.tpp"

#endif //NANOTEKSPICE_SHELLEXIT_HPP
