// Mohammed's Project 2 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"

#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <locale>
#include <cctype>

// Inheritance; "Barbarian" inherits features from the "Character" class
class Barbarian : public Character {
    private:
        std::string main_weapon_;
        std::string secondary_weapon_;
        bool enraged_;

    public:
        Barbarian(); // default constructor
        // Parameterized constructors
        Barbarian(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, 
        const std::string& main_weapon = "NONE", const std::string& secondary_weapon = "NONE", bool enraged = false);

        // setters and getters:
        bool setMainWeapon(const std::string& main_weapon);
        std::string getMainWeapon() const;

        bool setSecondaryWeapon(const std::string& secondary_weapon);
        std::string getSecondaryWeapon() const;

        void setEnrage(const bool& enraged);
        bool getEnrage() const;

        void toggleEnrage();
};

#endif