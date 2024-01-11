// Mohammed's Project 5 - Algorithmic Adventures: Into the Recursive Realms

#ifndef TAVERN_
#define TAVERN_

#include "ArrayBag.hpp"
#include "Character.hpp"

 
 
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>

class Tavern : public ArrayBag<Character*>{
  public:
    /** Default Constructor **/
    Tavern(); 


    /**
    @param: a reference to the string name of an input file
    @pre: Formatting of the csv file is as follows:
      Name: An uppercase string
      Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      Vitality/Armor/Level: A positive integer
      Enemy: 0 (False) or 1 (True)
    
    @post: Each line of the input file corresponds to a Character that enters the Tavern.
    */
    Tavern(const std::string& filename);



    /** 
        @param:   A reference to a Character entering the Tavern
        @return:  returns true if a Character was successfully added to items_, false otherwise
        @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
    **/
    bool enterTavern(Character* a_character);

    /** @param:   A reference to a Character leaving the Tavern  
        @return:  returns true if a character was successfully removed from items_, false otherwise
        @post:    removes the character from the Tavern and updates the level sum  and the enemy if the character is an enemy.
    **/
    bool exitTavern(Character* a_character);

   

    /** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int getLevelSum();


    /** 
        @return:  The average level of all the characters in the Tavern
        @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, 
                  and returns the integer value.
    **/
    int calculateAvgLevel();



    /** 
    @return:  The integer enemy count of the Tavern
    **/
    int getEnemyCount();

    /** 
        @return:  The percentage (double) of all the enemy characters in the Tavern
        @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, 
                 and returns the double value.
    **/
    double calculateEnemyPercentage();



    /** @param:   A string reference to a race 
        @return:  An integer tally of the number of characters in the Tavern of the given race
    **/
    int tallyRace(const std::string &race);




    /**
      @post:    Outputs a report of the characters currently in the tavern in the form:
      "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n"
      Note that the average level should be rounded to the NEAREST integer, and the enemy percentage should be rounded to 2 decimal

      Example output: 
      Humans: 3
      Elves: 5
      Dwarves: 8
      Lizards: 6
      Undead: 0

      The average level is: 7
      46.67% are enemies.
    */
    void tavernReport();


    /**
        @post: For every character in the tavern, displays each character's information
    */
    void displayCharacters();

    /**
        @param: a string reference to a race
        @post: For every character in the tavern of the given race, displays each character's information

    */
    void displayRace(const std::string &race);

   

// Created for Project 6:
void setMainCharacter(Character* main_character);
Character* getMainCharacter();

bool levelIsLess(Character* lhs, Character* rhs);
bool levelIsGreater(Character* lhs, Character* rhs);
bool vitalityIsLess(Character* lhs, Character* rhs);
bool vitalityIsGreater(Character* lhs, Character* rhs);

// void createCombatQueue(std::string filter = "NONE");
void createCombatQueue(const std::string& filter = "NONE");
Character* getTarget();
void printCombatQueue();
void actionSelection();
void enemyTurn(Character* enemy);
void combat();
void turnResolution();


// helper functions
// void printEnemyActionResults(Character* character, Buff buff);
// void printResolutionActionResults(Character* enemy, Character* main_character_);
void printResolutionActionResults();
// void printEnemyActionResults(Character* enemy);
// void Tavern::printEnemyActionResults(); 

void printEnemyResults(Character* enemy);

int getTurns();
void decrementTurns();
// ------------------------

  private:
    int level_sum_; // An integer sum of the levels of all the characters currently in the tavern
    int num_enemies_; //number of enemies currently in the Tavern

        /**
    @post: all characters leave the tavern
    */
    void emptyTavern();

    // - A pointer to a main character.
    // - A combat queue of Character pointers, enemies that the main character must fight.   

    Character* main_character_;
    std::queue<Character*> combat_queue_;
    


};
#endif
