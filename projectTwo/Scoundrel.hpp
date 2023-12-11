// Mohammed's Project 2 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

#ifndef SCOUNDREL_HPP
#define SCOUNDREL_HPP
#include "Character.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <locale>

enum Dagger { WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE };

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/
class Scoundrel : public Character{
    private:
        Dagger dagger_; // enum cannot be a type-string
        std::string faction_;
        bool disguise_; // true or false b/c it's a boolean (bool)

    public:
        Scoundrel(); // default constructor
        Scoundrel(std::string name, std::string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, 
        const std::string& dagger = "WOOD", const std::string& faction = "NONE", bool disguise = false);


/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.

    // the last few of the first six
    @param      : The character's dagger type (a const string reference).
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the dagger enum. Default to WOOD
    @param      : The character's Faction (a const string reference). 
                  Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the variable. Default to "NONE"
    @param      : A flag indicating whether the character has a disguise. Default to false
    @post       : The private members are set to the values of the corresponding 
                  parameters.
                 If the dagger type is not provided or invalid, the variable should 
                  be set to WOOD. 
                 If the Faction is not provided or invalid, the variable should be 
                  set to "NONE". 
*/

// setters and getters: 
        void setDagger(const std::string&  dagger);
        std::string getDagger() const ;

        bool setFaction(const std::string& faction);
        std::string getFaction() const ;

        void setDisguise(const bool& disguise);
        bool hasDisguise() const;
};

#endif