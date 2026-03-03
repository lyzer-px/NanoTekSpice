/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** HalfAdder
*/

#include "../../../include/components/composite/HalfAdder.hpp"

#include "../../../include/components/elementary/And.hpp"
#include "../../../include/components/elementary/Xor.hpp"

namespace nts {
HalfAdder::HalfAdder(std::string name): ACompositeComponent{std::move(name)}
{
    _type        = HALF_ADDER_TYPE;
    _numberOfPin = 4;

    _components.push_back(std::make_unique<And>("and"));
    _components.push_back(std::make_unique<Xor>("xor"));

    HalfAdder::registerInternComponentsPins();

    HalfAdder::setPinsType();
}

std::unique_ptr<IComponent> HalfAdder::create(std::string name)
{
    return std::make_unique<HalfAdder>(std::move(name));
}

void HalfAdder::registerInternComponentsPins()
{
    _internalPins[1] = {std::pair{_components[0].get(), 1},
                        std::pair{_components[1].get(), 1}};
    _internalPins[2] = {std::pair{_components[0].get(), 2},
                        std::pair{_components[1].get(), 2}};
    _internalPins[3] = {std::pair{_components[1].get(), 3}};
    _internalPins[4] = {std::pair{_components[0].get(), 3}};
}

void HalfAdder::setPinsType()
{
    _pins[1] = _pins[2] = Pin{PinType::INPUT};
    _pins[3] = _pins[4] = Pin{PinType::OUTPUT};
}
} // nts
