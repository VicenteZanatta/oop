#include "animal.h"
#include <iostream>

#ifndef CACHORRO_H
#define CACHORRO_H

class Cachorro : public Animal {
public:
    Cachorro(const std::string& name, int age) : Animal(name, age) {}

    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

#endif // CACHORRO_H