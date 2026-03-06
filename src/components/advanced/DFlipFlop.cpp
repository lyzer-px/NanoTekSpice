/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** DFlipFlop
*/

#include "components/advanced/DFlipFlop.hpp"
#include "components/elementary/Nand.hpp"
#include "components/elementary/Not.hpp"

namespace nts {
DFlipFlop::DFlipFlop(std::string name): ACompositeComponent{std::move(name)}
{
    _type        = D_FLIPFLOP_TYPE;
    _numberOfPin = 4;

    _components.push_back(std::make_unique<Not>("not"));
    _components.push_back(std::make_unique<Nand>("nand_1"));
    _components.push_back(std::make_unique<Nand>("nand_2"));
    _components.push_back(std::make_unique<Nand>("nand_3"));
    _components.push_back(std::make_unique<Nand>("nand_4"));

    DFlipFlop::registerInternComponentsPins();

    DFlipFlop::setPinsType();
}

std::unique_ptr<IComponent> DFlipFlop::create(std::string name)
{
    return std::make_unique<DFlipFlop>(name);
}

void DFlipFlop::registerInternComponentsPins()
{
    _components[0]->setLink(0, *_components[1], 1);
    _components[0]->setLink(1, *_components[2], 1);

    _components[1]->setLink(2, *_components[2], 2);
    _components[1]->setLink(3, *_components[3], 1);

    _components[2]->setLink(3, *_components[4], 2);

    _components[3]->setLink(2, *_components[4], 3);
    _components[3]->setLink(1, *_components[3], 3);



    _internalPins[1] = {std::pair{_components[0].get(), 1},
                        std::pair{_components[2].get(), 2}};
    _internalPins[2] = {std::pair{_components[1].get(), 2},
                        std::pair{_components[2].get(), 1}};
    _internalPins[3] = {std::pair{_components[3].get(), 3}};
    _internalPins[4] = {std::pair{_components[3].get(), 4}};
}

void DFlipFlop::setPinsType()
{
    _pins[1] = _pins[2] = Pin{PinType::INPUT};
    _pins[3] = _pins[4] = Pin{PinType::OUTPUT};
}
} // nts
