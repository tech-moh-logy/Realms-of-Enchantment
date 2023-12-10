// Mohammed's Project 1 - Algorithmic Adventures: Into the Recursive Realms

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// setting up the enum:
enum Race { NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD };

class Character {
   
private:
    // the name of the character (a string in UPPERCASE)
    std::string name_;
    // the race of the character (an enum)
    Race race_;
    // the character's vitality (a non-negative integer)
    int vitality_;
    // the character's max armor level (a non-negative integer)
    int armor_;
    // the character's level (a non-negative integer)
    int level_;
    // a flag indicating whether the character is an enemy
    bool enemy_;
    // helper function:
    std::string stringUpper(std::string input);

public:
    // Default Constructor:
    Character();

    // Parameterized Constructor:
    Character(std::string name, std::string race, int vitality = 0, int armorLevel = 0, int characterLevel = 0, bool isEnemy = false);

    // setters and getter; Accessors (get) and Mutators (set)
    void setName(const std::string name);
    std::string getName() const;

    void setRace(const std::string race);
    std::string getRace() const;

    void setVitality(const int vitality);
    int getVitality() const;

    void setArmor(const int armorLevel); 
    int getArmor() const;

    void setLevel(const int characterLevel);
    int getLevel() const;

    void setEnemy();
    bool isEnemy() const;
};

#endif
