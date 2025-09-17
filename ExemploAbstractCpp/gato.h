#include "animal.h"
#include <iostream>

#ifndef GATO_H
#define GATO_H

class Gato : public Animal {
public:
    Gato(const std::string& name, int age) : Animal(name, age) {}

    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }

    Gato* operator+(const Gato& other) {
        std::string newName = this->name + " & " + other.name;
        int newAge = 0;
        return new Gato(newName, newAge);
    }
};

#endif // GATO_H
