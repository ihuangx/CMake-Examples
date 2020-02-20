#include "Animal.hpp"

#include <string>

Animal::Animal(const std::string& name)
    : name_(name)
{}

std::string Animal::name() const
{
    return nameImpl();
}