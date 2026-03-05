/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ActiveHighSrLatch
*/

#include "../../../include/components/composite/ActiveHighSrLatch.hpp"

#include "../../../include/components/elementary/Nor.hpp"

namespace nts {
ActiveHighSRLatch::ActiveHighSRLatch(std::string name): ACompositeComponent{
    std::move(name)}
{
    _type        = HALF_ADDER_TYPE;
    _numberOfPin = 4;

    _components.push_back(std::make_unique<Nor>("nor_1"));
    _components.push_back(std::make_unique<Nor>("nor_2"));

    ActiveHighSRLatch::registerInternComponentsPins();

    ActiveHighSRLatch::setPinsType();
}

std::unique_ptr<IComponent> ActiveHighSRLatch::create(std::string name)
{
    return std::make_unique<ActiveHighSRLatch>(std::move(name));
}

void ActiveHighSRLatch::registerInternComponentsPins()
{
    _components[0]->setLink(3, *_components[1], 1);
    _components[1]->setLink(3, *_components[0], 2);

    _internalPins[1] = {std::pair{_components[0].get(), 1}};
    _internalPins[2] = {std::pair{_components[1].get(), 2}};
    _internalPins[3] = {std::pair{_components[1].get(), 3}};
    _internalPins[4] = {std::pair{_components[0].get(), 3}};
}

void ActiveHighSRLatch::setPinsType()
{
    _pins[1] = _pins[2] = Pin{PinType::INPUT};
    _pins[3] = _pins[4] = Pin{PinType::OUTPUT};
}
} // nts
