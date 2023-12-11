// Mohammed's Project 2 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

#include "Mage.hpp"

/**
  Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false.
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

Mage::Mage() : Character() {
    school_of_magic_ = "NONE";
    weapon_ = "NONE";
    can_summon_incarnate_ = false;
}

Mage::Mage(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, 
    const std::string& school_of_magic, const std::string& weapon, bool can_summon_incarnate) :
    Character (name, race, vitality, armor, level, enemy) {
        // setSchool(school_of_magic);
        // setCastingWeapon(weapon);
        setIncarnateSummon(can_summon_incarnate);

        if (!(setSchool(school_of_magic))) {
            school_of_magic_ = "NONE";
        }

         if (!(setCastingWeapon(weapon))) {
            weapon_ = "NONE";
        }
    } 

// ALTERNATIVE? Not sure; have to ask the Professor.
//Character(), school_of_magic_{"NONE"}, weapon_{"NONE"}, can_summon_incarnate_{false} {};

// -------------------------------------------- Simply, "setSchool" and "getSchool" --------------------------------------------

/**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. If 
              the provided school of magic is not one of the following: [ELEMENTAL, 
              NECROMANCY, ILLUSION], do nothing and return false.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/

bool Mage::setSchool(const std::string& school_of_magic) {
    // school_of_magic_ = school_of_magic; // parameter goes to the private -> will be settting upper to lower useless
    
    // converting every character to uppercase
    std::string capitalizedSchoolOfMagic = "";
    for (int i = 0; i < school_of_magic.length(); i++) {
        if (isalpha(school_of_magic[i])) {
            capitalizedSchoolOfMagic += std::toupper(school_of_magic[i]);
        }

        // capitalizedSchoolOfMagic += std::toupper(school_of_magic[i]);

    }

    if (!(capitalizedSchoolOfMagic == "ELEMENTAL" || capitalizedSchoolOfMagic == "NECROMANCY" || capitalizedSchoolOfMagic == "ILLUSION")) {
        return false;
    } else {
        school_of_magic_ = capitalizedSchoolOfMagic; // parameter goes to the private
        return true;
    }
}

/**
  @return  : the string indicating the character's school of magic
**/
std::string Mage::getSchool() const {
    return school_of_magic_;
}
// ------------------------------------------------------------------------------------------------------------------------------------

// ---------------------------------- Simply, "setCastingWeapon" and "getCastingWeapon" ----------------------------------

/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
              If the provided weapon is not one of the following: 
              [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setCastingWeapon(const std::string& weapon) {
    std::string capitalizedWeapon = "";
    for (int i = 0; i < weapon.length(); i++) {
        if (isalpha(weapon[i])) {
            capitalizedWeapon += std::toupper(weapon[i]);
        }

        // capitalizedWeapon += std::toupper(weapon[i]);
    }

    if (capitalizedWeapon == "WAND" || capitalizedWeapon == "STAFF") {
        weapon_ = capitalizedWeapon; // parameter goes to the private
        return true; 
    } else {
        return false;
    }

}

/**
  @return  : the string indicating the character's weapon
**/
std::string Mage::getCastingWeapon() const {
    return weapon_;
}
// ------------------------------------------------------------------------------------------------------------------------------------

// --------------------------- Simply, "setIncarnateSummon" and "hasIncarnateSummon" -----------------------

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character can 
            summon an incarnate
**/
// void setIncarnateSummon(const std::string can_summon_incarnate)
void Mage::setIncarnateSummon(const bool& can_summon_incarnate) {
    can_summon_incarnate_ = can_summon_incarnate;
}

/**
  @return  : the summon-incarnate flag
**/
bool Mage::hasIncarnateSummon() const {
    return can_summon_incarnate_;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// OLD METHOD; basic idea behind converting the strings to uppercase.
// std::string Character::stringUpper(std::string input) {
//     // converting every character to uppercase
//     std::string name_toUpper = "";
//     for (char a : input) {
//         if (isalpha(a)) {
//             name_toUpper += std::toupper(a);
//         }
//     }
//     return name_toUpper;
// }