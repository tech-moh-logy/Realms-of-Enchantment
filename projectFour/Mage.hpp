// Mohammed's Project 1 - Algorithmic Adventures: Into the Recursive Realms

#ifndef MAGE_HPP
#define MAGE_HPP

#include "Character.hpp"

class Mage : public Character
{
    private:
    // protected:
        // - A string that represents their school of magic
        std::string school_of_magic_;
        // - A string that represents their weapon
        std::string weapon_;
        // - A boolean indicating if they are able to summon an incarnate
        bool can_summon_incarnate_;

    public:
        /**
            Default constructor.
            Default-initializes all private members. 
            Default character name: "NAMELESS". Booleans are default-initialized to False. 
            Default school of magic and weapon: "NONE".  
        */
        Mage();

        /**
            Parameterized constructor.
            @param      : The name of the character (a string)
            @param      : The race of the character (a const string reference)
            @param      : The character's vitality (an integer)
            @param      : The character's max armor level (an integer)
            @param      : The character's level (an integer)
            @param      : A flag indicating whether the character is an enemy
            @param      : The character's school of magic (a string). Valid schools: [ELEMENTAL, NECROMANCY, ILLUSION]. 
                         String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
                         If the school name is invalid, set it to "NONE"
            @param      : The character's choice of weapon (a string). Valid weapons: [WAND, STAFF]
                          String inputs can be in lowercase, but must be converted to 
						  uppercase when setting the variable.
						  If the weapon is invalid, set it to "NONE"
            @param      : A flag indicating whether the character is able to summon an incarnate
            @post       : The private members are set to the values of the corresponding parameters.
                        : If the school of magic or weapon is not provided or valid, the variables should be set to "NONE". 
        */
        // Mage(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& school_of_magic = "NONE", const std::string& weapon = "NONE", bool can_summon_incarnate = false);
          Mage(const std::string& name, const std::string& race, int level, int vitality, int armor, bool enemy, const std::string& main_weapon, const std::string& school, bool can_summon_incarnate);

        /**
            @param  : a reference to a string representing the school of magic
            @post   : sets the private member variable to the value of the parameter. 
                      If the provided school of magic is not one of the following: [ELEMENTAL, NECROMANCY, ILLUSION], 
                      do nothing and return false.
                      String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            @return  : true if setting the variable was successful, false otherwise.
        **/
        bool setSchool(const std::string& school_of_magic);

        /**
            @return  : the string indicating the character's school of magic
        **/
        std::string getSchool() const;


        /**
            @param  : a reference to a string representing the character's weapon
            @post   : sets the private member variable to the value of the parameter. 
                      String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
                      If the provided weapon is not one of the following: [WAND, STAFF], do nothing and return false.
            @return  : true if setting the variable was successful, false otherwise.
        **/
        bool setCastingWeapon(const std::string& weapon);


        /**
            @return  : the string indicating the character's weapon
        **/
        std::string getCastingWeapon() const;

        /**
            @param  : a reference to boolean
            @post   : sets the private member variable indicating whether the character can summon an incarnate
        **/
        void setIncarnateSummon(const bool& can_summon_incarnate);

        /**
            @return  : the summon-incarnate flag
        **/
        bool hasIncarnateSummon() const;

        // ------------- MODIFIED FOR PROJECT 4 -------------        
        // void display() override;
        // void eatTaintedStew() override;
        // ------------- MODIFIED FOR PROJECT 4 -------------
        // New display and eatTaintedStew functions
        void display() const override;    
        void eatTaintedStew() override;


};

#endif