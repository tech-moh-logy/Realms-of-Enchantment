// Mohammed's Project 1 - Algorithmic Adventures: Into the Recursive Realms

#include "Barbarian.hpp"
// #include "Character.hpp"
/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default weapons: "NONE". 
*/
Barbarian::Barbarian() : Character(), main_weapon_{"NONE"},offhand_weapon{"NONE"},enraged_{false}
{
}

/**
    Parameterized constructor.
    @param      : The name of the character (a string)
    @param      : The race of the character (an enum)
    @param      : The character's vitality (an integer)
    @param      : The character's max armor level (an integer)
    @param      : The character's level (an integer)
    @param      : A flag indicating whether the character is an enemy
    @param      : The character's main weapon (a string). String inputs can be in lowercase, 
                  but must be converted to uppercase when setting the variable.
                  Only alphabetical characters are allowed.
    @param      : The character's offhand weapon (a string). String inputs can be in lowercase, 
                  but must be converted to uppercase when setting the variable.
                  Only alphabetical characters are allowed.
    @param      : A flag indicating whether the character is enraged, false by default
    @post       : The private members are set to the values of the corresponding parameters. 
                  If the main and secondary weapons are not provided or invalid, the variables are set to "NONE".
*/
Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& main_weapon, const std::string& secondary_weapon, bool enraged)
: Character(name, race, vitality, armor, level, enemy), enraged_(enraged)
{
    if(!setMainWeapon(main_weapon))
    {
        main_weapon_ = "NONE";
    }
    if(!setSecondaryWeapon(secondary_weapon))
    {
        offhand_weapon = "NONE";
    }
}

/**
    @param  : a reference to a string representing the Character's main weapon
    @post   : sets the private member variable to the value of the parameter. Only alphabetical characters are allowed.
            : String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setMainWeapon(const std::string& main_weapon)
{
    std::string temp = main_weapon;
    for (int i = 0; i < temp.length(); i++)
    {
        if (!isalpha(temp[i]))
        {
            return false;
        }
        else
        {
            temp[i] = toupper(temp[i]);
        }
    }
    main_weapon_ = temp;
    return true;
}

/**
    @return  : a string of the Character's main weapon
**/
std::string Barbarian::getMainWeapon() const
{
    return main_weapon_;
}

/**
    @param  : a reference to a string representing the Character's secondary weapon
    @post   : sets the private member variable to the value of the parameter. Only alphabetical characters are allowed.
            : String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setSecondaryWeapon(const std::string& secondary_weapon)
{
    std::string temp = secondary_weapon;
    for (int i = 0; i < temp.length(); i++)
    {
        if (!isalpha(temp[i]))
        {
            return false;
        }
        else
        {
            temp[i] = toupper(temp[i]);
        }
    }
    offhand_weapon = temp;
    return true;
}

/**
    @return  : a string of the Character's secondary weapon
**/
std::string Barbarian::getSecondaryWeapon() const
{
    return offhand_weapon;
}

/**
    @param  : a reference to a bool
    @post   : sets the private member variable to the value of the parameter.
**/
void Barbarian::setEnrage(const bool& enraged)
{
    enraged_ = enraged;
}

/**
    @return  : a boolean of whether the Character is enraged
**/
bool Barbarian::getEnrage() const
{
    return enraged_;
}

/**
    @post   : sets the enraged variable to the opposite of what it was
**/
void Barbarian::toggleEnrage()
{
    enraged_ = !enraged_;
}

// --------------------------------------------------
// ------------- MODIFIED FOR PROJECT 4 -------------
// --------------------------------------------------

/**
    @post     : displays Barbarian data in the form:
    "[NAME] is a Level [LEVEL] [RACE] BARBARIAN.
    \nVitality: [VITALITY]
    \nArmor: [ARMOR]
    \nThey are [an enemy/not an enemy].
    \nMain Weapon: [MAINWEAPON]
    \nOffhand Weapon: [OFFHANDWEAPON]
    \nEnraged: [TRUE/FALSE]
    \n\n"
    
    Example:
    BONK is a Level 5 HUMAN BARBARIAN.
    Vitality: 11
    Armor: 5
    They are an enemy.
    Main Weapon: MACE
    Offhand Weapon: ANOTHERMACE
    Enraged: TRUE 
*/
void Barbarian::display() const {
  std::cout << getName() << " is a Level " << getLevel() << " " << getRace() << " BARBARIAN." << std::endl;
  std::cout << "Vitality: " << getVitality() << std::endl;
  std::cout << "Armor: " << getArmor() << std::endl;
  std::cout << "They are " << (isEnemy() ? "an enemy." : "not an enemy.") << std::endl;
  std::cout << "Main Weapon: " << main_weapon_ << std::endl;
  std::cout << "Offhand Weapon: " << offhand_weapon << std::endl;
  std::cout << "Enraged: " << (enraged_ ? "TRUE" : "FALSE") << std::endl;
  std::cout << std::endl;
}

/**
    @post: 
    If the character is UNDEAD, gain 3 Vitality points. Nothing else happens.
    
    If the character is NOT UNDEAD, Vitality is set to 1. 
    In addition, as a Barbarian: 
    Become enraged if the character was not enraged, and not enraged if they were already enraged. 
    If they have now become enraged, the offhand weapon is replaced with "TABLE". 
    If they are now not enraged, the main weapon is replaced with "BUCKET".
*/
// you can't add on "getters" and "setters"
void Barbarian::eatTaintedStew() {
    if (getRace() == "UNDEAD") {
        setVitality(getVitality() + 3);
    } else {
        setVitality(1);
        if (getEnrage() == 0) {
            toggleEnrage();
            setSecondaryWeapon("TABLE");
        } else if (getEnrage() == 1) {
            toggleEnrage();
            setMainWeapon("BUCKET");
        } 
    }
}
//   if (getRace() == "UNDEAD") {
//     setVitality(getVitality()+ 3);
//   } else {
//     setVitality(1);
//     if (enraged_) {
//       offhand_weapon = "TABLE";
//       enraged_ = false;
//     } else {
//       main_weapon_ = "BUCKET";
//       enraged_ = true;
//     }
//   }
// }

// MODIFY FOR PROJECT 4
// void Barbarian::display() {
//   std::cout << "[NAME] is a Level [LEVEL] [RACE] BARBARIAN." << std::endl;
//   std::cout << "Vitality: " << vitality_ << std::endl;
//   std::cout << "Armor: " << armor_ << std::endl;
//   std::cout << "They are " << (isEnemy ? "an enemy" : "not an enemy") << std::endl;
//   std::cout << "Main Weapon: " << main_weapon_ << std::endl;
//   std::cout << "Offhand Weapon: " << offhand_weapon << std::endl;
//   std::cout << "Enraged: " << (enraged_ ? "TRUE" : "FALSE") << std::endl;
//   std::cout << std::endl;
// }

// void Barbarian::eatTaintedStew() {
//   if (enemy_) {
//     return;
//   }

//   vitality_ = 10;

//   if (enraged_) {
//     offhand_weapon = "TABLE";
//   } else {
//     main_weapon_ = "BUCKET";
//   }

//   enraged_ = !enraged_;
// }

// member "Character::name_" (declared at line 166 of "/Users/mohcs/Desktop/cs235/project4-tech-moh-logy/Character.hpp") is inaccessible

// void Barbarian::display() const {
//   std::cout << name_ << " is a Level " << level_ << " " << race_ << " BARBARIAN." << std::endl;
//   std::cout << "Vitality: " << vitality_ << std::endl;
//   std::cout << "Armor: " << armor_ << std::endl;
//   std::cout << "They are " << (enemy_ ? "an enemy" : "not an enemy") << std::endl;
//   std::cout << "Main Weapon: " << main_weapon_ << std::endl;
//   std::cout << "Offhand Weapon: " << offhand_weapon << std::endl;
//   std::cout << "Enraged: " << (enraged_ ? "TRUE" : "FALSE") << std::endl;
//   std::cout << std::endl;
// }

// void Barbarian::eatTaintedStew() {
//   if (getRace() == "UNDEAD") {
//     vitality_ += 3;
//   } else {
//     vitality_ = 1;
//     if (enraged_) {
//       offhand_weapon = "TABLE";
//       enraged_ = false;
//     } else {
//       main_weapon_ = "BUCKET";
//       enraged_ = true;
//     }
//   }
// }
