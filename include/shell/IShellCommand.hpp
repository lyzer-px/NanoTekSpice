//
// Created by kotti on 12/02/2026.
//

#ifndef NANOTEKSPICE_IDEFAULTSHELLCOMMAND_HPP
#define NANOTEKSPICE_IDEFAULTSHELLCOMMAND_HPP

#include <string>
#include <vector>

namespace shell {
class Shell;

class IShellCommand {
public:
    IShellCommand() = default;

    virtual ~IShellCommand() = default;

    virtual bool operator()(
        Shell &shell,
        std::vector<std::string> cmd) = 0;

    virtual bool execute(Shell &shell,
        std::vector<std::string> cmd) = 0;
};
}

#endif //NANOTEKSPICE_IDEFAULTSHELLCOMMAND_HPP
