//
// Created by kotti on 12/02/2026.
//

#ifndef NANOTEKSPICE_SHELLEXIT_HPP
#define NANOTEKSPICE_SHELLEXIT_HPP

#include "IDefaultShellCommand.hpp"

namespace shell {
class ShellExit: public IDefaultShellCommand {
public:
    ShellExit() = default;

    ~ShellExit() override = default;

    bool operator()(Shell<IDefaultShellCommand> &shell,
        std::vector<std::string> cmd) override;

    bool execute(Shell<IDefaultShellCommand> &shell,
        std::vector<std::string> cmd) override;

    static std::unique_ptr<IDefaultShellCommand> create();
};
}

#endif //NANOTEKSPICE_SHELLEXIT_HPP
