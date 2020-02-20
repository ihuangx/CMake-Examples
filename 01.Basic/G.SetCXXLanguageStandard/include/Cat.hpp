#pragma once

#include "Animal.hpp"

class Cat final : public Animal
{
public:
    Cat(const std::string& name)
        : Animal(name)
    {}

private:
    std::string nameImpl() const override;
};