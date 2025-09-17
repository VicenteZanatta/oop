#include <iostream>
#include <string>
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
    Animal(const std::string& name, int age) : name(name), age(age) {}

    virtual ~Animal() {}

    virtual void makeSound() const = 0; // Pure virtual function

    void info() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
protected:
    std::string name;
    int age;
};

#endif // ANIMAL_H
