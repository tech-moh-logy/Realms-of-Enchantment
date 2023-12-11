// Mohammed's Project 1 - Algorithmic Adventures: Into the Recursive Realms

#ifndef RANGER_HPP
#define RANGER_HPP

#include "Character.hpp"
#include <vector>
#include <string>


struct Arrows {
    std::string type_;
    int quantity_;
};

class Ranger : public Character {
    private:
    // A vector of arrows
    std::vector<Arrows> arrows_;
    // A vector of affinities (strings)
    std::vector<std::string> affinities_;
    // A boolean indicating if they are able to recruit an animal companion
    bool has_companion_;

     /**
        @param  : a reference to a vector representing the Character's arrows
        @post   : appends arrows to the private data member
        **/
    void setArrows(const std::vector<Arrows>& arrows);

    public:
        /**
            Default constructor.
            Default-initializes all private members. Default character name: "NAMELESS". 
            Booleans are default-initialized to False. 
        */
        Ranger();

        /**
            Parameterized constructor.
	        @param      : The name of the character (a const string reference)
	        @param      : The race of the character (a const string reference)
	        @param      : The character's vitality (an integer)
	        @param      : The character's max armor level (an integer)
	        @param      : The character's level (an integer)
	        @param      : A flag indicating whether the character is an enemy
	        @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
	           			  Lowercase valid arrow types are retained but converted to uppercase.
	        			  Invalid arrows are those with non-positive quantities or invalid types.
	        			  If the vector contains invalid arrows, those arrows are discarded. 
	        @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
		        		  String inputs can be in lowercase, but must be converted to uppercase.
  		        		  If the vector contains invalid affinities, those affinities are discarded.
	        @param      : A flag indicating whether the character is able to recruit an animal companion
	        @post       : The private members are set to the values of the corresponding parameters
        */
        Ranger(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, std::vector<Arrows> arrows = {}, std::vector<std::string> affinities = {}, bool has_companion = false);

       

        /**
         @return  : a vector of the Character's arrows
        **/
        std::vector<Arrows> getArrows() const;

        /**
            @param  	: a reference to string representing the arrow type
            @param  	: a reference to an integer quantity
            @post   	: If the character already has that type of arrow, the quantity in the vector 
				          is updated. If not, the arrow is added to the vector. 
            	          Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
            	          Lowercase valid arrow types are retained but converted to uppercase.
            	          Quantity of arrows must be greater than 0
				          Invalid arrows are those with non-positive quantities or invalid types.
				          If the arrows are invalid, they are not added.
            @return  	: True if the arrows were added successfully, false otherwise
        **/
        bool addArrows(const std::string& type, const int& quantity);

        /**
            @param  : a reference to string representing the arrow type
            @post   : If the character has the listed arrow AND enough arrows to fire one, the quantity of remaining arrows in the vector is updated.
            @return : True if the character had the listed arrow AND enough arrows, False otherwise.
        **/
        bool fireArrow(const std::string& type);

        /**
            @param  : a reference to string representing an affinity 
            @post   : If the affinity does not already exist in the vector, add it to the vector.
                      Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
				      String inputs can be in lowercase, but must be converted to uppercase when 
					  setting the variable.
             	      There should be no duplicate affinities.
             	      If the affinity is invalid, it is NOT added.
            @return : True if the affinity was added successfully, false otherwise
        **/
        bool addAffinity(const std::string& affinity);

        /**
            @return  : a vector of the Character's affinities
        **/
        std::vector<std::string> getAffinities() const;

        /**
            @param  : a reference to a boolean indicating whether the character is able to recruit an animal companion
            @post   : sets the private member variable to the value of the parameter.
        **/
        void setCompanion(const bool& has_companion);

        /**
            @return  : a boolean indicating whether the character is able to recruit an animal companion
        **/
        bool getCompanion() const;

    //     void display();
    //   void eatTaintedStew();
        void display() const override;    
        void eatTaintedStew() override;
};

#endif
