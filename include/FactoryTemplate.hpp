/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FactoryTemplate
*/

#ifndef NANOTEKSPICE_FACTORY_TEMPLATE_HPP
#define NANOTEKSPICE_FACTORY_TEMPLATE_HPP

#include <functional>
#include <memory>
#include <sstream>
#include <unordered_map>

template <typename BaseClass, typename ConcreteClass, typename... Args>
concept HasCreateMethod = requires(Args... args)
{
    {
        ConcreteClass::create(args...)
    } -> std::same_as<std::unique_ptr<BaseClass>>;
};

template <typename BaseClass, typename KeyType, typename... Args>
class FactoryTemplate {
public:
    using CreatorCallable = std::function<std::unique_ptr<BaseClass>(Args...)>;
    using CreatorMap      = std::unordered_map<KeyType,
        std::function<std::unique_ptr<BaseClass>(Args...)>>;

    FactoryTemplate() = default;

    ~FactoryTemplate() = default;

    FactoryTemplate(const FactoryTemplate &) = delete;

    FactoryTemplate(const FactoryTemplate &&) = delete;

    FactoryTemplate &operator=(const FactoryTemplate &) = delete;

    FactoryTemplate &operator=(const FactoryTemplate &&) = delete;

    template <typename ConcreteClass>
        requires HasCreateMethod<BaseClass, ConcreteClass>
    void registerCreator(KeyType key)
    {
        _creators[key] = &ConcreteClass::create;
    }

    void unregisterCreator(KeyType key)
    {
        _creators.erase(key);
    }

    std::unique_ptr<BaseClass> create(const KeyType &key, Args... args)
    {
        for (const auto &itt: _creators) {
            if (itt.first == key) {
                return itt.second(args...);
            }
        }

        std::stringstream sstream;
        sstream << "No creator found for key: " << key;
        throw std::runtime_error(sstream.str());
    }

private:
    CreatorMap _creators;
};

#endif // NANOTEKSPICE_FACTORY_TEMPLATE_HPP
