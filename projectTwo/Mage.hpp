// Mohammed's Project 2 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

#ifndef MAGE_HPP
#define MAGE_HPP
#include "Character.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <locale>
#include <cctype>

class Mage : public Character {
    private:
      std::string school_of_magic_; 
      std::string weapon_;
      bool can_summon_incarnate_;
    
    public:
    
/**
  Default constructor.
  Default-initializes all private members. 
  Default character name: "NAMELESS". Booleans are default-initialized to False. 
  Default school of magic and weapon: "NONE". 
*/

/**
  Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character sssis an enemy. Default to false.

  // inherited the other 6
  @param      : The character's school of magic (a const string reference). Valid schools: 
                [ELEMENTAL, NECROMANCY, ILLUSION]. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE".
  @param      : The character's choice of weapon (a const string reference). 
                Valid weapons: [WAND, STAFF]
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE".
  @param      : A flag indicating whether the character is able to summon an 
                incarnate. Default to false.
  @post       : The private members are set to the values of the corresponding 
                parameters.
                REMEMBER: If the school of magic or weapon is not provided or invalid, the 
                variables should be set to "NONE". 
*/

      Mage(); // default constructor
      Mage(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, 
      const std::string& school_of_magic = "NONE", const std::string& weapon = "NONE", bool can_summon_incarnate = false);

      // setters and getters: 
      bool setSchool(const std::string& school_of_name);
      std::string getSchool() const;

      bool setCastingWeapon(const std::string& weapon);
      std::string getCastingWeapon() const;

      void setIncarnateSummon(const bool& can_summon_incarnate);
      bool hasIncarnateSummon() const;
};

#endif