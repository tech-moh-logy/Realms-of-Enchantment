// Mohammed's Project 2 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

#include "Barbarian.hpp"

Barbarian::Barbarian() : Character() {
    main_weapon_ = "NONE";
    secondary_weapon_ = "NONE";
    enraged_ = false;
}

Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, 
    const std::string& main_weapon, const std::string& secondary_weapon, bool enraged) : 
    Character (name, race, vitality, armor, level, enemy) {
        // setMainWeapon(main_weapon);
        // setSecondaryWeapon(secondary_weapon);
        enraged_ = enraged;

        if (!(setMainWeapon(main_weapon))) {
            main_weapon_ = "NONE";
        }

        if (!(setSecondaryWeapon(secondary_weapon))) {
            secondary_weapon_ = "NONE";
        }
    }

// ------------------------------------------------------------------------------------------------------------------------------------

    // OTHER FUNCTIONS TO WORK WITH: 

    // bool setMainWeapon(const std::string& main_weapon);
    // std::string getMainWeapon() const;

    // bool setSecondaryWeapon(const std::string& secondary_weapon);
    // std::string getSecondaryWeapon() const;

    // void setEnrage(bool enraged);
    // bool getEnrage() const;

    // void toggleEnrage();   

// ------------------------------------------------------------------------------------------------------------------------------------


// -------------------------------------------- Simply, "setMainWeapon" and "getMainWeapon" -------------------------------------------

/**
    @param    : a reference to a string representing the Character's main weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
                If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setMainWeapon(const std::string& main_weapon) {
    // converting every character to uppercase
    std::string capitalizedMainWeapon = "";
    for (int i = 0; i < main_weapon.length(); i++) {
    // for (char i : main_weapon) {            ----|
        // check if it is a letter = isalpha       | FLAWED LOGIC
        // check if it is a number = isalnum   ----|
        if (isalpha(main_weapon[i])) {
            capitalizedMainWeapon += std::toupper(main_weapon[i]);  // saves the capitalized version of the string
        } else {
            return false;
        }
    }

    main_weapon_ = capitalizedMainWeapon;
    return true;
}

/**
    @return   : a string of the Character's main weapon
**/
std::string Barbarian::getMainWeapon() const {
    return main_weapon_; // returning the capitalized version of the string
}

// ------------------------------------------------------------------------------------------------------------------------------------


// --------------------------------------- Simply, "setSecondaryWeapon" and "getSecondaryWeapon" --------------------------------------

/**
    @param    : a reference to a string representing the Character's secondary weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
              : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setSecondaryWeapon(const std::string& secondary_weapon) {
    std::string capitalizedSecondaryWeapon;
    // for (int i = 0; i < secondary_weapon.length(); i++) 
    for (int i = 0; i < secondary_weapon.length(); i++)  {
        if (std::isalpha(secondary_weapon[i])) {
            capitalizedSecondaryWeapon += std::toupper(secondary_weapon[i]);
        } else {
            return false;
        }
    }
    secondary_weapon_ = capitalizedSecondaryWeapon; // same logic as the previous setters and getters
    return true;
}

/**
   @return    : a string of the Character's secondary weapon
**/
std::string Barbarian::getSecondaryWeapon() const {   
    return secondary_weapon_;
}

// ------------------------------------------------------------------------------------------------------------------------------------


// ------------------------------------------------ Simply, "setEnrage" and "getEnrage" -----------------------------------------------

/**
  @param      : a reference to a bool
  @post       : sets the private member variable to the value of the parameter.
**/
void Barbarian::setEnrage(const bool& enraged) {
    enraged_ = enraged;
}

/**
  @return  : a boolean of whether the Character is enraged
**/
bool Barbarian::getEnrage() const {
    return enraged_;
}

// ------------------------------------------------------------------------------------------------------------------------------------

/**
  @post   : sets the enraged variable to the opposite of what it was
**/
void Barbarian::toggleEnrage() {
    enraged_  = !(enraged_);
}