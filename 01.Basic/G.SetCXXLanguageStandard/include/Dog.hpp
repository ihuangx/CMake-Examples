#pragma once

#include "Animal.hpp"

class Dog final : public Animal
{
public:
    Dog(const std::string& name)
        : Animal(name)
    {}

private:
    std::string nameImpl() const override;
};