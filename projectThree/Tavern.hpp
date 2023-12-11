// Mohammed's Project 3 - Algorithmic Adventures: Into the Recursive Realms

#ifndef TAVERN_HPP_
#define TAVERN_HPP_
#include <iostream>
#include <string>
#include <cctype>

#include "Character.hpp"
#include "ArrayBag.hpp"

// template <class T>
class Tavern : public ArrayBag<Character> {
    public: 
    /**
    Default constructor.
    Default-initializes all private members. 
    */

    // Constructor
    Tavern();

    // Unique Methods
    bool enterTavern(const Character& character);
    bool exitTavern(const Character& character);

    int getLevelSum() const;
    double calculateAvgLevel() const;

    int getEnemyCount() const;
    double calculateEnemyPercentage() const;

    int tallyRace(const std::string& race) const;

    void tavernReport() const;

    private:
    // An integer sum of the levels of all the characters currently in the tavern
    int level_sum_;
    // An integer count of all the characters currently in the Tavern that are marked as enemies
    int enemy_count_;
};

#endif