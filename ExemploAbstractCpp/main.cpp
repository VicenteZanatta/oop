#include "animal.h"
#include "cachorro.h"
#include "gato.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Animal*> animals;

    animals.push_back(new Cachorro("Rex", 5));
    Gato *g1 = new Gato("Whiskers", 2);
    animals.push_back(g1);
    Gato *g2 = new Gato("The second", 3);
    animals.push_back(g2);
    Gato *g3 = *g1 + *g2; // Using overloaded + operator
    animals.push_back(g3); 
    
    for (const auto& animal : animals) {
        animal->info();
        animal->makeSound();
    }
    // Clean up
    for (const auto& animal : animals) {
        delete animal;
    }

    return 0;
}