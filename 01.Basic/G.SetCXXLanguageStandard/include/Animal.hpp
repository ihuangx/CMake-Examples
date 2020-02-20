#pragma once

#include <string>

class Animal
{
public:
    Animal() = default;
    explicit Animal(const std::string& name);
    std::string name() const;

protected:
    std::string name_;

private:
    virtual std::string nameImpl() const = 0;
};