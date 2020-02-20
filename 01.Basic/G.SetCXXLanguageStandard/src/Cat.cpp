#include "Cat.hpp"

std::string Cat::nameImpl() const
{
    return "I'm " + name_ + " the cat!";
}