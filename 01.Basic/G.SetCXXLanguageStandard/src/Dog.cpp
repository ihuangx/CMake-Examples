#include "Dog.hpp"

std::string Dog::nameImpl() const
{
    return "I'm " + name_ + " the dog!";
}