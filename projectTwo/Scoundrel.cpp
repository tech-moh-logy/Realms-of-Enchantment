// Mohammed's Project 2 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

#include "Scoundrel.hpp"

// Scoundrel::Scoundrel(): 
// Character(), dagger_{WOOD}, faction_{"NONE"}, disguise_{false} {};

// NOTE:
// modifiers = setters
// accessors = getters
Scoundrel::Scoundrel() : Character() {
    dagger_ = WOOD;
    faction_ = "NONE";
    disguise_ = false;
}

Scoundrel::Scoundrel(std::string name, std::string race, int vitality, int armor, int level, bool enemy, 
    const std::string& dagger, const std::string& faction, bool disguise) :
    Character (name, race, vitality, armor, level, enemy) {
        // some types you could change; int x = 5; float y = 7; x = y;
        setDagger(dagger);
        // setFaction(faction);
        setDisguise(disguise);

        if (!(setFaction(faction))) {
            faction_ = "NONE";
        } 
        
        // else {
        //     faction_ = faction;
        // } -> reduntant

    
    } 

// ------------------------------------------------------------------------------------------------------------------------------------


// ----------------------------------------------- Simply, "setDagger" and "getDagger" ------------------------------------------------

/**
   @param     : a reference to a string representing the dagger type
   @post      : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the dagger type is not valid (i.e, is one of the following: 
                [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                the variable should be set to WOOD. 
**/
void Scoundrel::setDagger(const std::string& dagger) {

    std::string capitalizedDagger = "";
    // Iterate over the string and convert each character to uppercase.
    for (int i = 0; i < dagger.length(); i++) {
        if (isalpha(dagger[i])) {
            capitalizedDagger += toupper(dagger[i]);
        }
    }

    if (capitalizedDagger == "BRONZE") {
        dagger_ = BRONZE;
    }
    else if (capitalizedDagger == "IRON") {
        dagger_ = IRON;
    }
    else if (capitalizedDagger == "STEEL") {
        dagger_ = STEEL;
    }
    else if (capitalizedDagger == "MITHRIL") {
        dagger_ = MITHRIL;
    }
    else if (capitalizedDagger == "ADAMANT") {
        dagger_ = ADAMANT;
    }
    else if (capitalizedDagger == "RUNE") {
        dagger_ = RUNE;
    }
    else {
        dagger_ = WOOD;
    }
}

/**
  @return  : the string indicating the character's Faction
**/
std::string Scoundrel::getDagger() const {
    if (dagger_ == BRONZE) {
        return "BRONZE";
    }
    else if (dagger_ == IRON) {
        return "IRON";
    }
    else if (dagger_ == STEEL) {
        return "STEEL";
    }
    else if (dagger_ == MITHRIL) {
        return "MITHRIL";
    }
    else if (dagger_ == ADAMANT) {
        return "ADAMANT";
    }
    else if (dagger_ == RUNE) {
        return "RUNE";
    }
    else {
        return "WOOD";
    }
}
// ------------------------------------------------------------------------------------------------------------------------------------


// -------------------------------------------- Simply, "setFaction" and "getFaction" -------------------------------------------------

/**
    @param    : a reference to a string representing the character's Faction
    @post     : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the provided faction is not one of the following: 
               [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
               do nothing and return false.
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Scoundrel::setFaction(const std::string& faction) {
    std::string capitalizedFaction = "";
    // "isalpha(c)" is a function in C which can be used to check if the passed character is an alphabet or not. 
    for (int i = 0; i < faction.length(); i++) {
        if (isalpha(faction[i])) {
            capitalizedFaction += std::toupper(faction[i]);
        }
    }

    // std::cout << "test" << capitalizedFaction << std::endl;

    if (capitalizedFaction == "NONE" || capitalizedFaction == "CUTPURSE" || capitalizedFaction == "SHADOWBLADE" || capitalizedFaction == "SILVERTONGUE") {
        faction_ = capitalizedFaction; // parameter goes to the private
        return true;
    } else {  
        return false;
    }
}

/**
  @return  : the string indicating the character's Faction
**/
std::string Scoundrel::getFaction() const {
    return faction_;
}

// ------------------------------------------------------------------------------------------------------------------------------------


// -------------------------------------------- Simply, "setDisguise" and "hasDisguise" -----------------------------------------------

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise(const bool& disguise) {
    disguise_ = disguise;
};

/**
  @return  : the disguise flag
**/
bool Scoundrel::hasDisguise() const {
    return disguise_;
}

// ------------------------------------------------------------------------------------------------------------------------------------
