/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** DLatch
*/

#include "../../../include/components/advanced/DLatch.hpp"

#include "../../../include/components/advanced/ActiveHighSrLatch.hpp"
#include "../../../include/components/elementary/And.hpp"
#include "../../../include/components/elementary/Not.hpp"

namespace nts {
DLatch::DLatch(std::string name): ACompositeComponent{std::move(name)}
{
    _type        = D_LATCH_TYPE;
    _numberOfPin = 4;

    _components.push_back(std::make_unique<Not>("not"));
    _components.push_back(std::make_unique<And>("and_1"));
    _components.push_back(std::make_unique<And>("and_2"));
    _components.push_back(std::make_unique<ActiveHighSRLatch>("sr_latch"));

    DLatch::registerInternComponentsPins();

    DLatch::setPinsType();
}

std::unique_ptr<IComponent> DLatch::create(std::string name)
{
    return std::make_unique<DLatch>(name);
}

void DLatch::registerInternComponentsPins()
{
    _components[0]->setLink(2, *_components[1], 1);
    _components[1]->setLink(3, *_components[3], 1);
    _components[2]->setLink(3, *_components[3], 2);

    _internalPins[1] = {std::pair{_components[0].get(), 1},
                        std::pair{_components[2].get(), 2}};
    _internalPins[2] = {std::pair{_components[1].get(), 2},
                        std::pair{_components[2].get(), 1}};
    _internalPins[3] = {std::pair{_components[3].get(), 3}};
    _internalPins[4] = {std::pair{_components[3].get(), 4}};
}

void DLatch::setPinsType()
{
    _pins[1] = _pins[2] = Pin{PinType::INPUT};
    _pins[3] = _pins[4] = Pin{PinType::OUTPUT};
}
} // nts
