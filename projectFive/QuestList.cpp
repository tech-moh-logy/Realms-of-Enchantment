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

#include "QuestList.hpp"

/*
    Default Constructor
*/
QuestList::QuestList() : DoublyLinkedList<Quest*>() { }



 /*
        Destructor
*/
    QuestList::~QuestList()
    {
        //delete every dynamically allocated Quest object
        Node<Quest*>* current = first_;
        while (current != nullptr) {
            delete current->getItem();
            current->setItem(nullptr);
            current = current->getNext();
        }
        //DoublyLinkedList destructor will be called next
    }

/**
    @param: A string reference to a quest title
    @return: The integer position of the given quest if it is in the QuestList, -1 if not found.
*/
int QuestList::getPosOf(const std::string& title) const
{
    Node<Quest*>* current = first_;
    int pos = 0;
    while (current != nullptr) {
        if (current->getItem()->title_ == title) {
            return pos;
        }
        current = current->getNext();
        pos++;
    }
    return -1;
}

/**
    @param: A string reference to a quest title
    @return: True if the quest is already in the QuestList
*/
bool QuestList::contains(const std::string& title) const
{
    return getPosOf(title) != -1;
}

/**
    @pre: The given quest is not already in the QuestList
    @param:  A pointer to a Quest object
    @post:  Inserts the given quest pointer into the QuestList. 
            If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
            Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
    @return: True if the quest was added successfully
*/
bool QuestList::addQuest(Quest* quest)
{
    // If the quest is already in the list, return false
    if (contains(quest->title_) && getPointerTo(getPosOf(quest->title_))->getItem()->description_ != "NOT DISCOVERED") {
        return false;
    }
    // if the quest is already in the list but marked as "NOT DISCOVERED", update its details
    else if (contains(quest->title_) && getPointerTo(getPosOf(quest->title_))->getItem()->description_ == "NOT DISCOVERED")
    {
        getPointerTo(getPosOf(quest->title_))->getItem()->description_ = quest->description_;
        getPointerTo(getPosOf(quest->title_))->getItem()->completed_ = quest->completed_;
        getPointerTo(getPosOf(quest->title_))->getItem()->experience_points_ = quest->experience_points_;
        getPointerTo(getPosOf(quest->title_))->getItem()->dependencies_ = quest->dependencies_;
        getPointerTo(getPosOf(quest->title_))->getItem()->subquests_ = quest->subquests_;
        return true;
    }
    // if the quest is not in the list, add it
    else
    {
        if(insert(item_count_, quest))
        {
            // add each of its dependencies and subquests to the list
            for(auto dependency : quest->dependencies_)
            {
                if(!contains(dependency->title_))
                {
                    addQuest(dependency);
                }
            }
            for(auto subquest : quest->subquests_)
            {
                if(!contains(subquest->title_))
                {
                    addQuest(subquest);
                }
            }
            return true;
        }
        // if the quest was not added successfully, return false
        else
        {
            return false;
        }
    }
    
}

/**
    @param:  A string representing the quest title
    @param:  A string representing the quest description
    @param:  A boolean representing if the quest is completed
    @param:  An int representing experience points the quest rewards upon completion 
    @param:  A vector of Quest pointers representing the quest's dependencies
    @param:  A vector of Quest pointers representing the quest's subquests
    @post:   Creates a new Quest object and inserts a pointer to it into the QuestList. 
             If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
             Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
             
    @return: True if the quest was added successfully
*/
bool QuestList::addQuest(const std::string& title, const std::string& description, const bool& completed, const int& experiencePoints, const std::vector<Quest*> &dependencies, const std::vector<Quest*> &subquests)
{
    //std::cout<<"Description given: "<< description.substr(0,10)<<std::endl;
    // The quest is already discovered and in the list, there is nothing that needs to be done
    if (contains(title) && getPointerTo(getPosOf(title))->getItem()->description_ != "NOT DISCOVERED") 
    {
        return false;
    }
    // The quest is in the list but has not been discovered yet, update its details
    else if (contains(title) && getPointerTo(getPosOf(title))->getItem()->description_ == "NOT DISCOVERED") 
    {
        getPointerTo(getPosOf(title))->getItem()->description_ = description;
        getPointerTo(getPosOf(title))->getItem()->completed_ = completed;
        getPointerTo(getPosOf(title))->getItem()->experience_points_ = experiencePoints;
        getPointerTo(getPosOf(title))->getItem()->dependencies_ = dependencies;
        getPointerTo(getPosOf(title))->getItem()->subquests_ = subquests;
        return true;
    }
    // The quest is not in the list, create a new quest and add it to the list
    else
    {
        Quest* newQuest = new Quest;
        newQuest->title_ = title;
        newQuest->description_ = description;
        newQuest->completed_ = completed;
        newQuest->experience_points_ = experiencePoints;
        newQuest->dependencies_ = dependencies;
        newQuest->subquests_ = subquests;
        if (insert(item_count_, newQuest))
        {
            // Add any dependencies or subquests that are not already in the list
            for(auto dependency : dependencies)
            {
                if(!contains(dependency->title_))
                {
                    addQuest(dependency);
                }
            }
            for(auto subquest : subquests)
            {
                if(!contains(subquest->title_))
                {
                    addQuest(subquest);
                }
            }
            return true;
        }
        // This should never happen as DoublyLinkedList will always successfully insert
        else
        {
            return false;
        }
    }
}

/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows:
        Title: A string
        Description: A string
        Completion Status: 0 (False) or 1 (True)
        Experience Points: A non negative integer
        Dependencies: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
        Subquests: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
    Notes:
        - The first line of the input file is a header and should be ignored.
        - The dependencies and subquests are separated by a semicolon and may be NONE.
        - The dependencies and subquests may be in any order.
        - The subquests will end with the carriage return symbol '\r' and should be removed.
        - If any of the dependencies or subquests are not in the list, they should be created as new quests with the following information:
            - Title: The title of the quest
            - Description: "NOT DISCOVERED"
            - Completion Status: False
            - Experience Points: 0
            - Dependencies: An empty vector
            - Subquests: An empty vector
        - However, if you eventually encounter a quest that matches one of the "NOT DISCOVERED" quests while parsing the file, you should update all the quest details.
        Hint: update as needed using addQuest()
        
    @post: Each line of the input file corresponds to a quest to be added to the list. No duplicates are allowed.
    Hint: use std::ifstream and getline()
*/
QuestList::QuestList(const std::string& filename)
{
    // Creating variables to store file inputs
    std::ifstream fin(filename);
    std::string line;

    std::getline(fin, line); // ignore first line
    // Variables to create quest objects
    std::string title;
    std::string description;
    std::string string_completed;
    bool completed;
    std::string string_experiencePoints;
    int experiencePoints;
    std::string string_dependencies;
    std::vector<Quest*> dependencies;
    std::string string_subquests;
    std::vector<Quest*> subquests;

    // Read input file one line at time
    // and construct Quest to add to QuestList
    while (std::getline(fin, line)) 
    {
        //std::cout<<line<<std::endl;
        std::stringstream ss(line);
        std::getline(ss, title, ',');
        std::getline(ss, description, ',');
        std::getline(ss, string_completed, ',');
        std::istringstream(string_completed) >> completed;
        std::getline(ss, string_experiencePoints, ',');
        std::istringstream(string_experiencePoints) >> experiencePoints;
        std::getline(ss, string_dependencies, ',');
        std::getline(ss, string_subquests, '\n');
        string_subquests.erase(std::remove(string_subquests.begin(), string_subquests.end(), '\r'), string_subquests.end());

        // std::cout << "Subquests: " << string_subquests << std::endl;
        // for (char c : string_subquests) {
        //     std::cout << "ASCII value: " << static_cast<int>(c) << ", Character: " << c << std::endl;
        // }

        // If the quest object has dependencies
        if(string_dependencies != "NONE")
        {
            std::istringstream ssDependencies(string_dependencies);
            std::string quest;

            // Get each quest title
            while(std::getline(ssDependencies, quest, ';'))
            {
                // If the quest is already in the list, retrieve its pointer and add it to the dependencies vector
                if (getPosOf(quest) != -1)
                {
                    Node<Quest*>* current = getPointerTo(getPosOf(quest));
                    dependencies.push_back(current->getItem());
                }
                // If not, create a new quest object and add it to the dependencies vector AND the quest list.
                else
                {
                    Quest* newQuest = new Quest;
                    newQuest->title_ = quest;
                    newQuest->description_ = "NOT DISCOVERED";
                    newQuest->completed_ = false;
                    newQuest->experience_points_ = 0;
                    newQuest->dependencies_ = {};
                    newQuest->subquests_ = {};
                    dependencies.push_back(newQuest);
                    //std::cout<<"trying to add a new dependency: "<<newQuest->title_<<"\n" << newQuest->description_<<std::endl<<std::endl;
                    addQuest(newQuest);
                }
            }
        }
        
        // If the quest has subquests
        if (string_subquests != "NONE")
        {
            std::istringstream ssSubquests(string_subquests);
            //std::cout<<string_subquests<<std::endl;
            std::string quest;
            // Get each quest title
            while(std::getline(ssSubquests, quest, ';'))
            {
                // If the quest is already in the list, retrieve its pointre and add it to the subquests vector
                if(getPosOf(quest)!= -1)
                {
                    Node<Quest*>* current = getPointerTo(getPosOf(quest));
                    subquests.push_back(current->getItem());
                }
                // If not, create a new quest object and add it to the subquests vector AND the quest list.
                else
                {
                    Quest* newQuest = new Quest;
                    newQuest->title_ = quest;
                    newQuest->description_ = "NOT DISCOVERED";
                    newQuest->completed_ = false;
                    newQuest->experience_points_ = 0;
                    newQuest->dependencies_ = {};
                    newQuest->subquests_ = {};
                    subquests.push_back(newQuest);
                    //std::cout<<"Trying to add a new subquest: "<<newQuest->title_<<"\n" << newQuest->description_<<std::endl<<std::endl;
                    addQuest(newQuest);
                }
            }
        }
        // std::cout<<"Title: "<<title<<" has: ";
        // for(auto x : dependencies)
        // {
        //     std::cout<<x->title_<<", ";
        // }
        // std::cout<<std::endl;
        // Add the quest to the list
        addQuest(title, description, completed, experiencePoints, dependencies, subquests);

        // Clear and reset the variables for the next quest
        title = "";
        description = "";
        string_completed = "";
        completed = false;
        string_experiencePoints = "";
        experiencePoints = 0;
        string_dependencies = "";
        dependencies = {};
        string_subquests = "";
        subquests = {};
    }
}

/**
    @param:  A Quest pointer
    @return: A boolean indicating if all the given quest's dependencies are completed
*/
bool QuestList::dependenciesComplete(Quest* quest) const
{
    Quest* current = quest;
    for (int i = 0; i < current->dependencies_.size(); i++)
    {
        if (!(current->dependencies_[i]->completed_))
        {
            return false;
        }
    }
    return true;
}

/**
    @param: A Quest pointer
    @return: A boolean if the given quest is available.
    Note: For a quest to be available, it must not be completed, and its dependencies must be complete.
*/
bool QuestList::questAvailable(Quest* quest) const
{
    return(quest->completed_ == false && dependenciesComplete(quest));
}

/**
    @param: A Quest pointer
    @post: Prints the quest title and completion status
    The output should be of the form:
    [Quest Title]: [Complete / Not Complete]
    [Quest Description]\n\n
*/
void QuestList::printQuest(Quest* quest) const
{
    //std::cout<<"printQuest was just called\n";
    std::cout << quest->title_ << ": ";
    std::cout<< (quest->completed_ ? "Complete" : "Not Complete") << std::endl;
    std::cout << quest->description_ << std::endl<<std::endl;
}

/**
    @param: A string reference to a quest title
    @pre:   If the given quest title is not found in the list, print "No such quest."
    @post:  Prints a list of quests that have to be completed before the given quest can be started (incomplete dependencies).
            If any of the quest's incomplete dependencies have an incomplete dependency, recursively print the quests that need to be done in order, indenting incomplete quests. 
            The indentation for incomplete quests is 2 spaces: "  "    
            The format of the list should be of the following forms:

            Query: [Quest Title]
            No such quest.

            Query: [Quest Title]
            Quest Complete

            Query: [Quest Title]
            Ready: [Quest Title]

            Query: [Quest Title]
            Ready: [Dependency0]
              [Given Quest]
            
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Given Quest]

            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Dependency2]
              [Given Quest]
*/
void QuestList::questQuery(const std::string& title) const
{
    std::cout<<"Query: "<<title<<std::endl;
    int pos = getPosOf(title);
    if (pos == -1)
    {
        std::cout << "No such quest." << std::endl;
    }
    else if (getPointerTo(pos)->getItem()->completed_) 
    {
        std::cout<< "Quest Complete" << std::endl;
    }
    else
    {
        questQueryHelper(title);
    }
    
}


void QuestList::questQueryHelper(const std::string& title) const
{
    
    Quest* current = getPointerTo(getPosOf(title))->getItem();
    if (dependenciesComplete(current) && !current->completed_)
    {
        std::cout<<"Ready: "<<current->title_ << std::endl;
    }
    else
    {
        
        for (int i = 0; i < current->dependencies_.size(); i++)
        {
            if (!current->dependencies_[i]->completed_)
            {
                questQueryHelper(current->dependencies_[i]->title_);     
            }
        }
        std::cout<<"  "<<current->title_<<std::endl;
    }
}




/**
    @return: An integer sum of all the experience gained
    Note: This should only include experience from completed quests 
*/
int QuestList::calculateGainedExperience() const
{
    int sum = 0;
    Node<Quest*>* current = first_;
    {
        while (current != nullptr)
        {
            if (current->getItem()->completed_)
            {
                sum += current->getItem()->experience_points_;
            }
            current = current->getNext();
        }
    }
    return sum;
}

/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
    Note: Also consider the potential experience if a subquest itself has subquests.
*/
int QuestList::calculateProjectedExperience(Quest* quest) const
{
    int sum = 0;
    sum += quest->experience_points_;
    for(int i = 0; i < quest->subquests_.size(); i++)
    {
        sum += calculateProjectedExperience(quest->subquests_[i]);
    }
    return sum;
}

/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
    Note: Also consider the experience gained if a subquest itself has subquests.  
*/
int QuestList::calculatePathwayExperience(Quest* quest) const
{
    int sum = 0;
    for(int i = 0; i < quest->subquests_.size(); i++)
    {
        if(quest->subquests_[i]->completed_)
        {
            sum += quest->subquests_[i]->experience_points_;
        }
        sum += calculatePathwayExperience(quest->subquests_[i]);
    }
    return sum;
}

/**
    @param: A string reference to a filter with a default value of "NONE".
    @post: With default filter "NONE": Print out every quest in the list.
        With filter "COMPLETE":   Only print out the completed quests in the list.
        With filter "INCOMPLETE": Only print out the incomplete quests in the list.
        With filter "AVAILABLE":  Only print out the available quests in the list.
        If an invalid filter is passed, print "Invalid Filter\n"
    Printing quests should be of the form:
    [Quest title]: [Complete / Not Complete]
    [Quest description]\n  
*/
void QuestList::questHistory(std::string filter) const
{
    if (filter != "NONE" && filter != "COMPLETE" && filter != "INCOMPLETE" && filter != "AVAILABLE")
    {
        std::cout<<"Invalid Filter"<<std::endl;
    }
    else
    {
        Node<Quest*>* current = first_;
        while (current != nullptr)
        {
            if (filter == "NONE")
            {
                printQuest(current->getItem());
            }
            else if (filter == "COMPLETE")
            {
                if (current->getItem()->completed_)
                {
                    printQuest(current->getItem());
                }
            }
            else if (filter == "INCOMPLETE")
            {
                if (!current->getItem()->completed_)
                {
                    printQuest(current->getItem());
                }
            }
            else if (filter == "AVAILABLE")
            {
                if (questAvailable(current->getItem()))
                {
                    printQuest(current->getItem());
                }
            }
            current = current->getNext();
        }
    }
}

/**
    @param: A quest pointer to a main quest
    @post:  Print quest names with two spaces ("  ") of indentation for each subquest recursively.
            Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
            The format should be of the form:
            [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
                [Subquest0]: [Complete / Not Complete]
                    [Sub-Subquest01]: [Complete / Not Complete]
                        [Sub-Subquest011]: [Complete / Not Complete]
                    [Subquest02]: [Complete / Not Complete]
            Hint: You can write a helper function to print the subquests recursively. If the given quest is already marked as completed, you can assume that all of its subquests are also completed.
*/
void QuestList::printQuestDetails(Quest* quest) const
{
    if(quest->completed_)
    {
        std::cout << quest->title_ << " (100% Complete)" << std::endl;
    }
    else
    {
        std::cout << quest->title_ << " (" << (calculatePathwayExperience(quest)*100/calculateProjectedExperience(quest)*100)/100 << "% Complete)" << std::endl;
        printQuestDetailsHelper(quest, 0);
    }
    
    
}

void QuestList::printQuestDetailsHelper(Quest* quest, int level) const
{
    for(int i = 0; i < quest->subquests_.size(); i++)
    {
        for(int i = 0;i < level+1; i++)
        {
            std::cout << "  ";
        }
        std::cout<< quest->subquests_[i]->title_ << ": " << (quest->subquests_[i]->completed_ ? "Complete" : "Not Complete") << std::endl;
        printQuestDetailsHelper(quest->subquests_[i], level + 1);
    }
}