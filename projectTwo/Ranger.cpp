// Mohammed's Project 2 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

// Unique Methods

#include "Ranger.hpp"

Ranger::Ranger() : Character() {
  arrows_.clear();
  affinities_.clear();
}

Ranger::Ranger(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, 
const std::vector<Arrows>& arrows, const std::vector<std::string>& affinities, bool can_recruit_animal_companion) :
Character (name, race, vitality, armor, level, enemy) {

  for (int i = 0; i < arrows.size(); i++) {
      addArrows(arrows[i].type_, arrows[i].quantity_);
  }

  for (int i = 0; i < affinities.size(); i++) {
      addAffinity(affinities[i]);
  }

  can_recruit_animal_companion_ = can_recruit_animal_companion;
  
}
  
std::vector<Arrows> Ranger::getArrows() const {
  return arrows_;
}

// ---------------------------------------------- HELPER FUNCTIONS ---------------------------------------------------

bool Ranger::isValidArrowType(const std::string& arrow_type) const {
  return (arrow_type == "WOOD" || arrow_type == "FIRE" || arrow_type == "WATER" || arrow_type == "POISON" || arrow_type == "BLOOD");
}

bool Ranger::isValidAffinity(const std::string& affinity) const {
  return (affinity == "FIRE" || affinity == "WATER" || affinity == "POISON" || affinity == "BLOOD");
}
// ---------------------------------------------- HELPER FUNCTIONS ----------------------------------------------------


// --------------------------------------- Simply, "addArrows" and "fireArrows" ---------------------------------------- 

/**
    @param    : a reference to string representing the arrow type
    @param    : a reference to an integer quantity
    @post     : If the character already has that type of arrow, the quantity in the vector 
                is updated. If not, the arrow is added to the vector. 
                Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Quantity of arrows must be greater than 0
                Invalid arrows are those with non-positive quantities or invalid types.
                If the arrows are invalid, they are not added.
    @return   : True if the arrows were added successfully, false otherwise
**/
bool Ranger::addArrows(const std::string& arrow_type, const int& quantity) {

  // capitalizedArrowType; converting letters to their uppercase using "isalpha"
  // which is a built in C++ Function
  std::string capitalizedArrowType = "";
    for (int i = 0; i < arrow_type.length(); i++) {
        if (isalpha(arrow_type[i])) {
            capitalizedArrowType += std::toupper(arrow_type[i]);
        }
    }

    if (!isValidArrowType(capitalizedArrowType)) {
      return false;
    }

  // EXTRA MILE:  
  // Validate quantity = quantities of arrows must be greater than 0
  // if (quantity <= 0) {
  //   return false;
  // }
  
    for (int i = 0; i < arrows_.size(); i++) {
      if (arrows_[i].type_ == capitalizedArrowType) {
        arrows_[i].quantity_ += quantity;
        return true;
      }
    }

  // If the character doesn't already have the arrow type, add it
  // if (!arrow_found) {
    arrows_.push_back({capitalizedArrowType, quantity});
  // }

    return true;
}

bool Ranger::fireArrow(const std::string& arrow_type) {

// capitalizedArrowType; converting letters to their uppercase using "isalpha"
// isalpha: is a built in C++ Function
std::string capitalizedArrowType = "";
    for (int i = 0; i < arrow_type.length(); i++) {
        if (isalpha(arrow_type[i])) {
            capitalizedArrowType += std::toupper(arrow_type[i]);
        }
    }
  
  // Validate arrow type using "HELPER FUNCTIONS":
  if (!isValidArrowType(capitalizedArrowType)) {
    return false;
  }

  // Check if the character has the arrow type and enough arrows to fire one
  for (Arrows& arrow : arrows_) {
    if (arrow.type_ == capitalizedArrowType && arrow.quantity_ > 0) {
      arrow.quantity_--;
      return true;
    }
  }

  return false;
}

// -----------------------------------------------------------------------------------------------------------------


// ------------------------------------ Simply, "addAffinity" and "getAffinities" ----------------------------------

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
bool Ranger::addAffinity(const std::string& affinity) {

  std::string capitalizedAffinity = "";
    for (int i = 0; i < affinity.length(); i++) {
        if (isalpha(affinity[i])) {
            capitalizedAffinity += std::toupper(affinity[i]);
        }
    }
    // Validate affinity
    if (!isValidAffinity(capitalizedAffinity)) {
      return false;
    }

    // Check if the character already has the affinity
    for (const std::string& affinity_ : affinities_) {
      if (affinity_ == capitalizedAffinity) {
        return false;
      }
    }

    // Add the affinity to the vector
    affinities_.push_back(capitalizedAffinity);

    return true;
}

/**
  @return     : a vector of the Character's affinities
**/
std::vector<std::string> Ranger::getAffinities() const {
  return affinities_;
}
// -----------------------------------------------------------------------------------------------------------------


// ------------------------------------- "setCompanion" and "getCompanion" -----------------------------------------

/**
    @param    : a reference to a boolean indicating whether the character is able to recruit 
                an animal companion
    @post     : sets the private member variable to the value of the parameter.
**/
void Ranger::setCompanion(const bool& can_recruit_animal_companion) {
  can_recruit_animal_companion_ = can_recruit_animal_companion;
}

/**
    @return   : a boolean indicating whether the character is able to recruit an animal companion
**/
bool Ranger::getCompanion() const {
  return can_recruit_animal_companion_;
}

// -------------------------------------------------------------------------------------------------------------------
