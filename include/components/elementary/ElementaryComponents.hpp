/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef ELEMENTARYCOMPONENTS_HPP
    #define ELEMENTARYCOMPONENTS_HPP

#include "AElementaryComponent.hpp"

namespace nts {

class AndComponent : public AElementaryComponent {
    explicit AndComponent() : AElementaryComponent("AND") {
        
    }   
};

}
#endif // !ELEMENTARYCOMPONENTS_HPP
