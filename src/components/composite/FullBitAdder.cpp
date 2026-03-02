/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FullBitAdder
*/

#include "../../../include/components/composite/FullBitAdder.hpp"

#include <algorithm>
#include <cstddef>
#include <memory>
#include <string>

#include "../../../include/components/IComponent.hpp"
#include "../../../include/components/elementary/And.hpp"
#include "../../../include/components/elementary/Or.hpp"
#include "../../../include/components/elementary/Xor.hpp"

namespace nts {
FullBitAdder::FullBitAdder(std::string name): ACompositeComponent{
    std::move(name)}
{
    _type        = FULL_ADDER_TYPE;
    _numberOfPin = 5;

    _components.push_back(std::make_unique<Xor>("xor_1"));
    _components.push_back(std::make_unique<Xor>("xor_2"));
    _components.push_back(std::make_unique<And>("and_1"));
    _components.push_back(std::make_unique<And>("and_2"));
    _components.push_back(std::make_unique<Or>("or"));

    FullBitAdder::registerInternComponentsPins();

    FullBitAdder::setPinsType();
}

std::unique_ptr<IComponent> FullBitAdder::create(std::string name)
{
    return std::make_unique<FullBitAdder>(std::move(name));
}

void FullBitAdder::registerInternComponentsPins()
{
    _components[0]->setLink(3, *(_components[1].get()), 1);
    _components[0]->setLink(3, *(_components[3].get()), 1);
    _components[2]->setLink(3, *(_components[4].get()), 2);
    _components[3]->setLink(3, *(_components[4].get()), 1);

    _internalPins[1] = {std::pair{_components[0].get(), 1},
                        std::pair{_components[2].get(), 1}};
    _internalPins[2] = {std::pair{_components[0].get(), 2},
                        std::pair{_components[2].get(), 2}};
    _internalPins[3] = {std::pair{_components[1].get(), 2}};
    _internalPins[4] = {std::pair{_components[1].get(), 3}};
    _internalPins[5] = {std::pair{_components[4].get(), 3}};
}

void FullBitAdder::setPinsType()
{
    for (const auto &pin: {1, 2, 3})
        _pins[pin] = Pin{PinType::INPUT};

    for (const auto &pin: {4, 5})
        _pins[pin] = Pin{PinType::OUTPUT};
}
} // nts
