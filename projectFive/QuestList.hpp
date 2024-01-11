///////////////////////////////////////////////////////////////////////////////
// Project: Project 5 - Quest Management with Doubly Linked Lists
// Author:  Mohammed 
//
// Notes:
// Data Structures & Algorithm
//
// Copyright:
// © 2024 Mohammed. All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef QUESTLIST_HPP
#define QUESTLIST_HPP

#include "DoublyLinkedList.hpp"
#include "Node.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

struct Quest {
    std::string title_;
    std::string description_;
    bool completed_;
    int experience_points_;
    std::vector<Quest*> dependencies_;
    std::vector<Quest*> subquests_;
};

class QuestList : public DoublyLinkedList<Quest*> {
public:
    QuestList();  // Default constructor
    ~QuestList(); // Destructor

    int getPosOf(const std::string& title) const;
    bool contains(const std::string& title) const;
    bool addQuest(Quest* quest);
    bool addQuest(const std::string& title, const std::string& description, const bool& completed, const int& experiencePoints, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests);
    QuestList(const std::string& filename);

    bool dependenciesComplete(Quest* quest) const;
    bool questAvailable(Quest* quest) const;
    void printQuest(Quest* quest) const;
    void questQuery(const std::string& title) const;
    void questQueryHelper(const std::string& title) const;
    int calculateGainedExperience() const;
    int calculateProjectedExperience(Quest* quest) const;
    int calculatePathwayExperience(Quest* quest) const;
    void questHistory(std::string filter = "NONE") const;
    void printQuestDetails(Quest* quest) const;
    void printQuestDetailsHelper(Quest* quest, int level) const;
};

#endif  // QUESTLIST_HPP
