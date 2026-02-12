//
// Created by kotti on 12/02/2026.
//

#ifndef NANOTEKSPICE_IDEFAULTSHELLCOMMAND_HPP
#define NANOTEKSPICE_IDEFAULTSHELLCOMMAND_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace shell {
template <typename CommandBase>
class Shell;

class IDefaultShellCommand {
public:
    IDefaultShellCommand() = default;

    virtual ~IDefaultShellCommand() = default;

    virtual bool operator()(
        Shell<IDefaultShellCommand> &shell,
        std::vector<std::string> cmd) = 0;

    virtual bool execute(Shell<IDefaultShellCommand> &shell,
        std::vector<std::string> cmd) = 0;

    static std::unique_ptr<IDefaultShellCommand> create()
    {
        return nullptr;
    }
};
}

#endif //NANOTEKSPICE_IDEFAULTSHELLCOMMAND_HPP
