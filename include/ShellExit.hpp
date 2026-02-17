//
// Created by kotti on 12/02/2026.
//

#ifndef NANOTEKSPICE_SHELLEXIT_HPP
#define NANOTEKSPICE_SHELLEXIT_HPP

#include <memory>

#include "IShellCommand.hpp"

namespace shell {
class ShellExit: public IShellCommand {
public:
    ShellExit() = default;

    ~ShellExit() override = default;

    bool operator()(Shell &shell,
        std::vector<std::string> cmd) override;

    bool execute(Shell &shell,
        std::vector<std::string> cmd) override;

    static std::unique_ptr<IShellCommand> create();
};
}

// #include "../src/ShellExit.tpp"

#endif //NANOTEKSPICE_SHELLEXIT_HPP
