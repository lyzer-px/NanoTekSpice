/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef COMPONENT_FACTPORY_HPP
    #define COMPONENT_FACTPORY_HPP


#include <functional>
#include <map>
#include <memory>
#include <string>

namespace nts {

class IComponent;

#define GATE_CREATOR(serial_nb) std::unique_ptr<IComponent> create##serial_nb()

GATE_CREATOR(AndGate);
GATE_CREATOR(NandGate);
GATE_CREATOR(OrGate);
GATE_CREATOR(NorGate);
GATE_CREATOR(XorGate);
GATE_CREATOR(NotGate);

class ComponentFactory {
public:
    const std::map<std::string, std::function<std::unique_ptr<IComponent()>>> Factory = {{"and", createAndGate()},
        {"nand", createNandGate()},
        {"or", createOrGate()},
        {"nor", createNorGate()},
        {"xor", createXorGate()},
        {"not", createNotGate()},
        {"and", createAndGate()},
    };
private:
    
};
}

#endif // !COMPONENT_FACTPORY_HPP
