// Mohammed's Project 2 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

#ifndef RANGER_HPP
#define RANGER_HPP

#include "Character.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <locale>

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
*/

/**
   Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false

    // the other of the first six variables: 
  @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Invalid arrows are those with non-positive quantities or invalid types.
                If the vector contains invalid arrows, those arrows are discarded. 
                Default to empty vector
  @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
                String inputs can be in lowercase, but must be converted to uppercase.
                If the vector contains invalid affinities, those affinities are discarded.
                Default to empty vector
  @param      : A flag indicating whether the character is able to recruit an animal companion. 
                Default to false
  @post       : The private members are set to the values of the corresponding parameters
*/

struct Arrows {
  std::string type_;
  int quantity_;
};

class Ranger : public Character {

  // ------------------------- PRIVATE --------------------------
private:
  std::vector<Arrows> arrows_;
  std::vector<std::string> affinities_;
  bool can_recruit_animal_companion_;

public:
  // Constructors
  Ranger();
  Ranger(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false , 
  const std::vector<Arrows>& arrows = {}, const std::vector<std::string>& affinities = {}, bool can_recruit_animal_companion = false);

  // Unique Methods
  std::vector<Arrows> getArrows() const;

  // bool Ranger::addArrows(const std::string& arrow_type, const int& quantity)
  bool addArrows(const std::string& arrow_type, const int& quantity);
  bool fireArrow(const std::string& arrow_type);

  bool addAffinity(const std::string& affinity);
  std::vector<std::string> getAffinities() const;

  // created my "OWN FUNCTIONS":
  void setCompanion(const bool&  can_recruit_animal_companion);
  bool getCompanion() const;

  bool isValidArrowType(const std::string& arrow_type) const;
  bool isValidAffinity(const std::string& affinity) const;
};

#endif