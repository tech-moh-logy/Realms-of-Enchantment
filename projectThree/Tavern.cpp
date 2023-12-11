// Mohammed's Project 3 - Algorithmic Adventures: Into the Recursive Realms

#include "Tavern.hpp"
#include <iomanip>
#include <cmath>

Tavern::Tavern() : level_sum_(0), enemy_count_(0) {}

/** @param:   A const reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to the tavern (i.e. items_),
              false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count 
              if the character is an enemy.
 **/
bool Tavern::enterTavern(const Character& character) {
  if (add(character)) {
    level_sum_ += character.getLevel();
    if (character.isEnemy()) {
      enemy_count_++;
    }
    return true;
  }
  return false;
}


/** @param:   A const reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from the tavern (i.e. items_),               
              false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count
              if the character is an enemy.
 **/
bool Tavern::exitTavern(const Character& character) {
  if (remove(character)) {
    level_sum_ -= character.getLevel();
    if (character.isEnemy()) {
      enemy_count_--;
    }
    return true;
  }
  return false;
}

/** 
    @return:  The integer level count of all the characters currently in the Tavern
 **/
int Tavern::getLevelSum() const {
  return level_sum_;
}

/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
 **/
double Tavern::calculateAvgLevel() const {
  return round(level_sum_ / item_count_);
}

/** 
    @return:  The integer enemy count of the Tavern
 **/
int Tavern::getEnemyCount() const {
  return enemy_count_;
}

/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
 **/
double Tavern::calculateEnemyPercentage() const {
  // put double or it will assume that this is a int
  double decimalTwoPlace = (double(enemy_count_) / double(item_count_) * 100.0); 
  double newValue = std::ceil(100.0  * (decimalTwoPlace))/100.0; 
  //double solution = std::ceil(newValue) / 100; // using the built-in function "ceil"
  return newValue;
  // return setprecision((enemy_count_ / level_sum_ * 100.0), 2); <--- wrong syntax
}

/** 
    @param:   A const reference to a string representing a character Race with value in 
              ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return:  An integer tally of the number of characters in the Tavern of the given race. 
              If the argument string does not match one of the expected race values, 
              the tally is zero. NOTE: no pre-processing of the input string necessary, only                  
              uppercase input will match.
 **/

// it's not a vector
int Tavern::tallyRace(const std::string& race) const {
  int tally = 0;
  for (int i = 0; i < item_count_; i++) {
    if (items_[i].getRace() == race) {
      tally++;
    }
  }
  return tally;
}

/**
@post:      Outputs a report of the characters currently in the tavern in the form:
            "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average             
            level is: [x] \n[x]% are enemies.\n"
            Note that the average level should be rounded to the NEAREST integer, and the enemy             
            percentage should be rounded to 2 decimal places.

            Example output: 
            Humans: 3
            Elves: 5
            Dwarves: 8
            Lizards: 6
            Undead: 0

            The average level is: 7
            46.67% are enemies.
*/
void Tavern::tavernReport() const {
  std::cout << "Humans: " << tallyRace("HUMAN") << std::endl;
  std::cout << "Elves: " << tallyRace("ELF") << std::endl;
  std::cout << "Dwarves: " << tallyRace("DWARF") << std::endl;
  std::cout << "Lizards: " << tallyRace("LIZARD") << std::endl;
  std::cout << "Undead: " << tallyRace("UNDEAD") << std::endl;
  std::cout << std::endl;
  std::cout << "The average level is: " << std::round(calculateAvgLevel()) << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "%" << " are enemies." << std::endl;
}