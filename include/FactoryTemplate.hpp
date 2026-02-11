/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** FactoryTemplate
*/

#ifndef NANOTEKSPICE_FACTORYTEMPLATE_HPP
#define NANOTEKSPICE_FACTORYTEMPLATE_HPP

#include <functional>
#include <memory>
#include <sstream>
#include <unordered_map>

template <typename T, typename... Args>
concept HasCreateMethod = requires(Args... args)
{
    { T::create(args...) } -> std::same_as<std::unique_ptr<T>>;
};

template <typename BaseClass, typename KeyType, typename... Args>
    requires HasCreateMethod<BaseClass, Args...>
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

    void registerCreator(KeyType key, CreatorCallable creator)
    {
        _creators[key] = creator;
    }

    void unregisterCreator(KeyType key)
    {
        _creators.erase(key);
    }

    std::unique_ptr<BaseClass> create(const KeyType &key, Args... args)
    {
        auto itt = std::find(_creators.begin(), _creators.end(), key);

        if (itt == _creators.end()) {
            std::stringstream sstream;

            sstream << "No creator found for key: " << key;
            throw std::runtime_error(sstream.str());
        }

        return itt->second(args...);
    }

private:
    CreatorMap _creators;
};

#endif // NANOTEKSPICE_FACTORYTEMPLATE_HPP
