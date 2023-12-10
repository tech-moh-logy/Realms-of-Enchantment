// Mohammed's Project 1 - Algorithmic Adventures: Into the Recursive Realms

#include "Character.hpp"
using namespace std;

/**
     Default constructor.
     Default-initializes all private members.
     Default character name: "NAMELESS".
     Booleans are default-initialized to False.
     Default enum value: NONE.
     Default Vitality, Max Armor, and Level: 0.
*/
Character::Character() { name_ = "NAMELESS"; race_ = NONE; vitality_ = 0; armor_ = 0; level_ = 0; enemy_ = false; }

/**
Parameterized constructor.
    @param      : The name of the character (a string in UPPERCASE)
    @param      : The race of the character (a string)
    @param      : The character's vitality (a non-negative integer) , with default
                value 0
    @param      : The character's max armor level (a non-negative integer), with
                default value 0
    @param      : The character's level (non-negative integer), with default value 0
    @param      : A flag indicating whether the character is an enemy, with default
                value false
    @post       : The private members are set to the values of the corresponding
                parameters.
*/
Character::Character(std ::string name, std::string race, int vitality, int armorLevel, int characterLevel, bool isEnemy) {
    // setters 'set':
    setName(name);
    setRace(race);
    setVitality(vitality);
    setArmor(armorLevel);
    setLevel(characterLevel);
    enemy_ = isEnemy;
}

/**
    @param  : the name of the Character
    @post   : sets the Character's title to the value of the parameter,
              in UPPERCASE. Only alphabetical characters are allowed.
              For example, attempting to create a character named
              "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
            : If the given parameter does not have any valid alphabetical
              characters, the character's name should be set to "NAMELESS".
*/
void Character::setName(const std::string name) {
    std::string updatedName = "";
    bool theGoal = false;
    for (char i : name) {
        if (isalpha(i)) {
            updatedName += i;
            theGoal = true;
        }
    }
    if (theGoal == true) {
        name_ = stringUpper(updatedName); // stringUpper: converts the string to uppercase; helper function
    }
    else {
        name_ = "NAMELESS";
    }
}

 /**
    @return : the name of the Character
  */
std::string Character::getName() const {
    return name_;
}

/**
    @param  : the race of the Character (a string)
    @post   : sets the Character's race to the value of the parameter.
              If the given race was invalid, set race_ to NONE.
*/
void Character::setRace(const std::string race) {
    if (race == "HUMAN") { race_ = HUMAN; }
    else if (race == "ELF") { race_ = ELF; }
    else if (race == "DWARF") { race_ = DWARF; }
    else if (race == "LIZARD") { race_ = LIZARD; }
    else if (race == "UNDEAD") { race_ = UNDEAD; }
    else { race_ = NONE; }
}

/**
    @return : the race of the Character (a string)
   */
std::string Character::getRace() const {
    if (race_ == HUMAN) { return "HUMAN"; }
    else if (race_ == ELF) { return "ELF"; }
    else if (race_ == DWARF) { return "DWARF"; }
    else if (race_ == LIZARD) { return "LIZARD"; }
    else if (race_ == UNDEAD) { return "UNDEAD"; }
    else { return "NONE"; }
}

/**
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
*/
void Character::setVitality(const int vitality) {
    if (vitality >= 0) {
        vitality_ = vitality;
    }
}

 /**
    @return : the value stored in vitality_
   */
int Character::getVitality() const {
    return vitality_;
}

/**
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
*/
void Character::setArmor(const int armorLevel) {
    if (armorLevel >= 0) {
        armor_ = armorLevel;
    }
}

 /**
    @return : the value stored in armor_
   */
int Character::getArmor() const {
    return armor_;
}

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
              if level is negative, do nothing.
  */
void Character::setLevel(const int characterLevel) {
    if (characterLevel >= 0) {
        level_ = characterLevel;
    }
}

/**
    @return : the value stored in level_
   */
int Character::getLevel() const {
    return level_;
}

/**
@post   : sets the enemy flag to true
*/
void Character::setEnemy() {
    enemy_ = true;
}

/**

    @return true if the character is an enemy, false otherwise
    Note: this is an accessor function and must follow
    the same convention as all accessor
    functions even if it is not called getEnemy
 */
bool Character::isEnemy() const {
    return enemy_;
}

// converts the string to uppercase; helper function
std::string Character::stringUpper(std::string input) {
    // converting every character to uppercase
    std::string upperCasedName = "";
    for (char a : input) {
        if (isalpha(a)) {
            upperCasedName += std::toupper(a);
        }
    }
    return upperCasedName;
}