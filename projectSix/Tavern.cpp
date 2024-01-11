// Mohammed's Project 5 - Algorithmic Adventures: Into the Recursive Realms

#include "Tavern.hpp"

/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}



/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows:
      Name: An uppercase string
      Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      Vitality/Armor/Level: A positive integer
      Enemy: 0 (False) or 1 (True)
    
    @post: Each line of the input file corresponds to a Character that enters the Tavern.
  */
    Tavern::Tavern(const std::string& filename)
    {
      std::ifstream fin(filename);
      std::string line;
      std::getline(fin, line);
      std::string name, race, string_vitality, string_armor, string_level, string_enemy;
      int vitality, armor, level;
      bool enemy;
      
      while(std::getline(fin, line))
      {
        std::istringstream iss(line);
        std::getline(iss, name, ',');
        std::getline(iss, race, ',');

        std::getline(iss, string_vitality, ',');
        std::istringstream(string_vitality) >> vitality;

        std::getline(iss, string_armor, ',');
        std::istringstream(string_armor) >> armor;

        std::getline(iss, string_level, ',');
        std::istringstream(string_level) >> level;

        std::getline(iss, string_enemy, ',');
        std::istringstream(string_enemy) >> enemy;
        Character* character = new Character(name, race, vitality, armor, level, enemy);
        enterTavern(character);
      }
    }


/** 
    @param:   A reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/** @param:   A reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}


/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {
      return level_sum_;
    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/** 
    @return:  The integer enemy count of the Tavern
    **/
    int Tavern::getEnemyCount()
    {
      return num_enemies_;
    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage()
{
  double enemy_percent = (num_enemies_>0) ?  (double(num_enemies_) / item_count_) * 100: 0.0;
  return std::ceil(enemy_percent*100.0) / 100.0; //round up to to decimal places
 
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index]->getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }

  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << humans << std::endl;
  std::cout << "Elves: " << elves << std::endl;
  std::cout << "Dwarves: " << dwarves << std::endl;
  std::cout << "Lizards: " << lizards << std::endl;
  std::cout << "Undead: " << undead << std::endl;
  std::cout << "\nThe average level is: " << calculateAvgLevel() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "% are enemies.\n\n";
}


/**
    @post: For every character in the tavern, displays each character's information
*/
void Tavern::displayCharacters()
{
  for(int i = 0; i < item_count_; i++)
  {
    items_[i]->display();
  }
}


/**
    @param: a string reference to a race
    @post: For every character in the tavern of the given race, displays each character's information
*/
void Tavern::displayRace(const std::string &race)
{
  for(int i = 0; i < item_count_; i++)
  {
    if(items_[i]->getRace() == race)
    {
      items_[i]->display();
    }
  }
}






/**
    @post: all characters leave the tavern
*/
void Tavern::emptyTavern()
{
  for(int i = 0; i < item_count_; i++)
  {
    delete items_[i];
    items_[i] = nullptr;
  }
  item_count_ = 0;
}








// -------------------------< IMPLEMENTATIONS >-------------------------

/**
  @param: a Character pointer 
  @post: sets the Tavern's main character to the pointer that is given
*/
void Tavern::setMainCharacter(Character* main_character) {
  main_character_ = main_character;
}

/**
  @return: a pointer to the main character in the Tavern, nullptr if there is no main character
*/
Character* Tavern::getMainCharacter() {
  return main_character_;
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's level is less than the rhs Character's level
*/
bool Tavern::levelIsLess(Character* lhs, Character* rhs) { return lhs->getLevel() < rhs->getLevel(); }

/**
  @param: two Character pointers
  @return: true if the lhs Character's level is greater than the rhs Character's level
*/
bool Tavern::levelIsGreater(Character* lhs, Character* rhs) { return lhs->getLevel() > rhs->getLevel(); }

/**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is less than the rhs Character's vitality
*/
bool Tavern::vitalityIsLess(Character* lhs, Character* rhs) { return lhs->getVitality() < rhs->getVitality(); }

/**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is more than the rhs Character's vitality
*/
bool Tavern::vitalityIsGreater(Character* lhs, Character* rhs) { return lhs->getVitality() > rhs->getVitality(); }

/**
  @pre  : The combat queue should be emptied before the characters are added to the queue
  @param  : A string reference to a sorting filter with a default value of "NONE"
  @post   : With default filter "NONE": add every character marked as an enemy to the combat queue
    : With the filter "LVLASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their level.
    : With the filter "LVLDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their level.
    : With the filter "HPASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their vitality.
    : With the filter "HPDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their vitality.
*/
// void Tavern::createCombatQueue(std::string filter) {

//   std::vector<Character*> enemies;

//   while (!combat_queue_.empty()) {
//       combat_queue_.pop();
//   }

//   if (filter == "NONE") {
//     // With default filter "NONE": add every character marked as an enemy to the combat queue
//       for (int i = 0; i < item_count_; i++) {
//         if (items_[i]->isEnemy()) {
//           combat_queue_.push(items_[i]);
//         }
//       }
//     }
//   else if (filter == "LVLASC") {
//     std::sort(enemies.begin(), enemies.end(), [](Character* a, Character* b) {
//       return a->getLevel(), b->getLevel();
//     });
//   } else if (filter == "LVLDES") {
//     std::sort(enemies.begin(), enemies.end(), [](Character* a, Character* b) {
//       return a->getLevel(), b->getLevel();
//     });
//   } else if (filter == "HPASC") {
//     std::sort(enemies.begin(), enemies.end(), [](Character* a, Character* b) {
//       return a->getVitality(), b->getVitality();
//     });
//   } else if (filter == "HPDES") {
//     std::sort(enemies.begin(), enemies.end(), [](Character* a, Character* b) {
//       return a->getVitality(), b->getVitality();
//     });
//   }
//   // } else {
//   //   // No filter, just add enemies in order they were added to the tavern
//   // }

//   for (Character* enemy : enemies) {
//     combat_queue_.push(enemy);
//   }
// }

// /**
//   @post   : returns a pointer to the Character at the front of the Combat Queue. 
//           : If there are no characters in the queue, return nullptr
// */
// Character* Tavern::getTarget() {
//   // if (!combat_queue_.empty()) {
//   //   return combat_queue_.front();
//   // } else {
//   //   return nullptr;
//   // }
//   return (combat_queue_.empty()) ? nullptr:combat_queue_.front(); // learned from someone
// }

void Tavern::createCombatQueue(const std::string& filter)
{
  while(!combat_queue_.empty())
  {
    combat_queue_.pop();
  }
  std::vector<Character*> characters = toVector();
  if(filter == "NONE")
  {
      for(Character* c:characters)
      {
        if(c->isEnemy())
          combat_queue_.push(c);
      }
  }
  else if(filter=="LVLASC")
  {
      //The & in the capture clause of the lambda function is used to indicate that outside variables that will be
      //used by the lambda function will be captured by reference. In our case, the lambda function is using
      //the this pointer variable to call the levelIsLess() function.
      std::sort(characters.begin(), characters.end(), [&](Character* lhs, Character* rhs){return levelIsLess(lhs, rhs);});
      for(Character* c:characters)
      {
        if(c->isEnemy())
          combat_queue_.push(c);
      }
  }
  else if(filter == "LVLDES")
  {
      //The & in the capture clause of the lambda function is used to indicate that outside variables that will be
      //used by the lambda function will be captured by reference. In our case, the lambda function is using
      //the this pointer variable to call the levelIsGreater() function.
      std::sort(characters.begin(), characters.end(), [&](Character* lhs, Character* rhs){return levelIsGreater(lhs, rhs);});
      for(Character* c:characters)
      {
        if(c->isEnemy())
          combat_queue_.push(c);
      }
  }
  else if(filter == "HPASC")
  {
      //The & in the capture clause of the lambda function is used to indicate that outside variables that will be
      //used by the lambda function will be captured by reference. In our case, the lambda function is using
      //the this pointer variable to call the vitalityIsLess() function.
      std::sort(characters.begin(), characters.end(), [&](Character* lhs, Character* rhs){return vitalityIsLess(lhs, rhs);});
      for(Character* c:characters)
      {
        if(c->isEnemy())
          combat_queue_.push(c);
      }
  }
  else if(filter == "HPDES")
  {
      //The & in the capture clause of the lambda function is used to indicate that outside variables that will be
      //used by the lambda function will be captured by reference. In our case, the lambda function is using
      //the this pointer variable to call the vitalityIsGreater() function.
      std::sort(characters.begin(), characters.end(), [&](Character* lhs, Character* rhs){return vitalityIsGreater(lhs, rhs);});
      for(Character* c:characters)
      {
        if(c->isEnemy())
          combat_queue_.push(c);
      }
  }
}
/**
  @post : Prints the details of each character in the combat queue in the following form:
         (ENEMY)[ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
*/
// void Tavern::printCombatQueue() {
//   // std::cout << "Combat Queue:" << std::endl;
//   // for (Character* character : combat_queue_) 
//     std::queue<Character*> copy_queue = combat_queue_;
//     // traversing on copyqueue
//     // until it becomes empty
//     while (!copy_queue.empty()) {
 
//         // front element of queue
//         copy_queue.front();
//           std::cout << "\t- (ENEMY) [" << copy_queue.front()->getName() << "]: LEVEL " << copy_queue.front()->getLevel() << " " << copy_queue.front()->getRace() << "." << std::endl;
//           std::cout << "\t\tVITALITY: " << copy_queue.front()->getVitality() << std::endl;
//           std::cout << "\t\tARMOR: " << copy_queue.front()->getArmor() << std::endl;
//         // deleting element from
//         // queue using std :: pop()
//         // function
//         copy_queue.pop();
//     }
// }

// void Tavern::printCombatQueue() {
//   while(!combat_queue_.empty())
//   {
//     Character* c = combat_queue_.front();
//     std::cout << "(ENEMY)" << c->getName() << ": LEVEL " << c->getLevel() << " " << c->getRace() << ". \nVITALITY: " << c->getVitality()<<" \nARMOR: "<<c->getArmor()<<"\n";
//     combat_queue_.pop();
//   }
// }

/**
  @post : Prints the details of each character in the combat queue in the following form:
        (ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
*/
void Tavern::printCombatQueue()
{
  while (!combat_queue_.empty())
  {
    Character *character = combat_queue_.front();
    std::cout << "(ENEMY) " << character->getName() << ": LEVEL" << character->getLevel() << " "
              << character->getRace() << ". \nVITALITY: " << character->getVitality() << "\nARMOR: " << character->getArmor() << "\n";
    combat_queue_.pop();
  }
}

/** THE FOLLOWING FUNCTIONS WILL MANAGE THE COMBAT - YOU SHOULD CONSIDER HOW THESE WILL AFFECT THE CHARACTERS AND WHAT ADDITIONAL MEMBER FUNCTION YOU NEED TO IMPLEMENT IN THE CHARACTER CLASS TO SUPPORT THESE ACTIONS */

/** 
        @post : If there are no enemies in the combat queue, do nothing.
              : Otherwise do all of the following
              :     - The action queue must be emptied before the new actions are added.
              :     - Print out the start of turn and details of the target enemy in the form:
                      : YOUR TURN\n
                      : (ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n\n 
    
              :     - Repeat the following process thrice (i.e. read three actions from input): 
              :           - Print the actions that are available to the main character, and read 
                            a non-negative number from input, corresponding to an action. 
                            Printing the available options should be of the following form. 
                            You may consider writing a helper function for this.
                            :Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n
              :           - If the input is invalid (valid inputs will be 1,2,3, or 4 only.), 
                          keep prompting for a non-negative number that is within range, by
                          printing "Invalid input. Please enter a number between 1 and 4 inclusive.\n" and prompt for input again.
              :           - When a valid action is read, 
                          it is added to the main character's action queue.    
*/
// void Tavern::actionSelection() {
//   if (combat_queue_.empty()) {
//     std::cout << "No enemies to fight." << std::endl;
//     return;
//   }

//   // main_character_->getAction().empty(); // returns a bool
//   for (int i = 0; i < item_count_; i++) {
//         if (items_[i]->isEnemy()) {
//           combat_queue_.push(items_[i]);
//         }
//       } 

//   Character* target = getTarget();
//   std::cout << "YOUR TURN" << std::endl;
//   std::cout << "(ENEMY) [" << target->getName() << "]: LEVEL " << target->getLevel() << " " << target->getRace() << "." << std::endl;
//   std::cout << "\tVITALITY: " << target->getVitality() << std::endl;
//   std::cout << "\tARMOR: " << target->getArmor() << std::endl << std::endl;


//   // for (int i = 0; i < 3; i++) {
//   //   std::string store;
//   //   std::cin >> store;
//   //   std::stringstream ss(store);




//     int actionChoice = -1;
//     std::cout << "Choose an action(1-4):" << std::endl;
//     std::cout << "1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato" << std::endl;
//     std::cin >> actionChoice;

//     while (actionChoice < 1 || actionChoice > 4) {
//       std::cout << "Invalid input. Please enter a number between 1 and 4 inclusive." << std::endl;
//       std::cin >> actionChoice;
//       // combat_queue_.push(items_[actionChoice]); <--- will take in each increment
//     } main_character_->getAction().push((Action)(actionChoice - 1)); // casting here
// }

/** THE FOLLOWING FUNCTIONS WILL MANAGE THE COMBAT - YOU SHOULD CONSIDER HOW THESE WILL AFFECT THE CHARACTERS AND WHAT ADDITIONAL MEMBER FUNCTION YOU NEED TO IMPLEMENT IN THE CHARACTER CLASS TO SUPPORT THESE ACTIONS */



/** 
        @post : If there are no enemies in the combat queue, do nothing.
              : Otherwise do all of the following
              :     - The action queue must be emptied before the new actions are added.
              :     - Print out the start of turn and details of the target enemy in the form:
                      : YOUR TURN\n
                      : (ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n\n 
    
              :     - Repeat the following process thrice (i.e. read three actions from input): 
              :           - Print the actions that are available to the main character, and read 
                            a non-negative number from input, corresponding to an action. 
                            Printing the available options should be of the following form. 
                            You may consider writing a helper function for this.
                            :Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n
              :           - If the input is invalid (valid inputs will be 1,2,3, or 4 only.), 
                          keep prompting for a non-negative number that is within range, by
                          printing "Invalid input. Please enter a number between 1 and 4 inclusive.\n" and prompt for input again.
              :           - When a valid action is read, 
                          it is added to the main character's action queue.    
*/

void Tavern::actionSelection()
{
  if(!combat_queue_.empty())
  {
      while(!main_character_->getAction().empty());
      {
        main_character_->getAction().pop();
      }
      
      std::cout<<"YOUR TURN\n";
      Character* c = combat_queue_.front();
      std::cout<<"(ENEMY) "<<c->getName()<<": LEVEL "<<c->getLevel()<<" "<<c->getRace()<<". \nVITALITY: "<<c->getVitality()<<" \nARMOR: "<<c->getArmor()<<"\n\n";
  
      int tries = 0;
      
      while(tries<3)
      { 
        std::cout<<"Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n";
        int input_action=0;
        while(!(input_action>=1&&input_action<=4))
        {
         std::cin>>input_action;

          if(!(input_action>=1&&input_action<=4))
          {
            std::cout<<"Invalid input. Please enter a number between 1 and 4 inclusive.\n";
          }
          else
          {
            main_character_->getAction().push(input_action-1);
          }
        }
        tries++;

      }
    
  }
}
// implementation ----------------------------
    // void decrementTurns() {
    //   turns_--;
    // }

    // int getTurns() {
    //   return turns_;
    // }

    // buff.decrementTurns();

    // void printEnemyActionResults(Character* character, Buff buff) {
    //   std::cout << character->getName() << " used " << actionToString(buff.getAction()) << "!\n\n";
    //   printCharacterStatus(character);
    //}
    // implementation ----------------------------


/**
        @post : If there are no actions in the main character's action queue, 
                or there are no enemies in the combat queue, do nothing.
                
                Otherwise do all of the following:            
                
                1. If the Buff stack is not empty, apply the buff once and decrement the turns.
                   Any time a Buff's turns_ goes to zero, it is removed
                   from the stack. Print out the results of the action as described below.
                2. While there are actions on the action queue:
                - take the next action off the queue
                - if the next action is  a buff, apply once and push it onto the buff stack after 
                  decrementing the turns. 
                  BUFF_Heal lasts for 3 turns in total, while BUFF_MendMetal lasts
                  for 2 turns in total. Print out the results of the action as described below.
                - if the next action is an attack, execute it against the enemy at the front of
                  the combat queue. Print out the results of the action as described below. 
                 - if after this action there are no more enemies to fight, clear the action
                   queue and return.
                3. Print "END OF TURN\n" 
          
            : More details:
        
            : After applying each action, print out the results of the action as follows:
            : [MAINCHARACTER NAME] used [ACTION NAME]!
            : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
            : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 

             Where [ACTION NAME] is one of [Heal, MendMetal, Strike, ThrowTomato]
            
            :   Whenever an enemy's vitality becomes <=0 after an attack, also print out 
                "[CHARACTER NAME] DEFEATED\n" 
                and remove the enemy from the combat queue AND let them exit the tavern. 
                Then carry out the remaining actions, if any, against the next enemy on the
                combat queue.
          
*/

// <<"(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<main_character_->getRace()<<". \n"
// <<"VITALITY: "<<main_character_->getVitality()<<"\nARMOR: "<<main_character_->getArmor()<<"\n"
// <<"\n(ENEMY) "<<combat_queue_.front()->getName()<<": LEVEL "<<combat_queue_.front()->getLevel()<<" "<<combat_queue_.front()->getRace()<<". \n"
// <<"VITALITY: "<<combat_queue_.front()->getVitality()<<" \nARMOR: "<<combat_queue_.front()->getArmor()<<"\n"; 

// helper function for "turnResolution": to make it look cleaner :)
// void Tavern::printResolutionActionResults() {
//   std::cout << "(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"
//   "VITALITY: " << main_character_->getVitality() << "\n" <<
//   "ARMOR: " << main_character_->getArmor() << "\n" <<
//   "\n(ENEMY) " << combat_queue_.front()->getName() << ": LEVEL " << combat_queue_.front()->getLevel() << " " << combat_queue_.front()->getRace() << ". \n"
//    "VITALITY: " << combat_queue_.front()->getVitality() << "\n" <<
//   "ARMOR: " << combat_queue_.front()->getArmor() << std::endl;
// }

// potential HELPER FUNCTION:
// void Tavern::printEnemyResults(Character* enemy) {
//   std::cout << "(ENEMY) " << enemy->getName()<<": LEVEL " << enemy->getLevel() << " " << enemy->getRace()
//       <<". \nVITALITY: " << enemy->getVitality() << " \nARMOR: " << enemy->getArmor() << "\n" 
//       <<"\n(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"
//       << "VITALITY: " << main_character_->getVitality() << " \nARMOR: " << main_character_->getArmor() << "\n";
// }

// helper function for "enemyTurn": to make it look cleaner :)
// void Tavern::printEnemyActionResults(Character* enemy) 
// void Tavern::printEnemyActionResults(){
//   std::cout << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". \nVITALITY: " << enemy->getVitality() << "\n" <<
//   "ARMOR: " << enemy->getArmor() << std::endl;
//   std::cout << "(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"
//   "VITALITY: " << main_character_->getVitality() << "\n" <<
//   "ARMOR: " << main_character_->getArmor() << std::endl;
// }

/**
        @post : If there are no actions in the main character's action queue, 
                or there are no enemies in the combat queue, do nothing.
                
                Otherwise do all of the following:            
                
                1. If the Buff stack is not empty, apply the buff once and decrement the turns.
                   Any time a Buff's turns_ goes to zero, it is removed
                   from the stack. Print out the results of the action as described below.
                2. While there are actions on the action queue:
                - take the next action off the queue
                - if the next action is  a buff, apply once and push it onto the buff stack after 
                  decrementing the turns. 
                  BUFF_Heal lasts for 3 turns in total, while BUFF_MendMetal lasts
                  for 2 turns in total. Print out the results of the action as described below.
                - if the next action is an attack, execute it against the enemy at the front of
                  the combat queue. Print out the results of the action as described below. 
                 - if after this action there are no more enemies to fight, clear the action
                   queue and return.
                3. Print "END OF YOUR TURN\n" 
          
            : More details:
        
            : After applying each action, print out the results of the action as follows:
            : [MAINCHARACTER NAME] used [ACTION NAME]!
            : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
            : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 

             Where [ACTION NAME] is one of [Heal, MendMetal, Strike, ThrowTomato]
            
            :   Whenever an enemy's vitality becomes <=0 after an attack, also print out 
                "[CHARACTER NAME] DEFEATED\n" 
                and remove the enemy from the combat queue AND let them exit the tavern. 
                Then carry out the remaining actions, if any, against the next enemy on the
                combat queue.
          
*/

// main_character_

void Tavern::turnResolution() 
{
  if (main_character_ != nullptr) 
  {
    if (!main_character_->getAction().empty() && !combat_queue_.empty()) 
    {
        if(!main_character_->getBuff().empty()) 
        {
          // std::cout<<"main character buff is not empty\n";
          Buff buff = main_character_->getBuff().top();
          main_character_ -> getBuff().pop();
          if(buff.name_ == "BUFF_Heal") 
          {
            main_character_->heal();
            buff.turns_--;
            std::cout << main_character_->getName() << " used Heal!\n" << "(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"<< "VITALITY: " << main_character_->getVitality() << "\n" <<
            "ARMOR: " << main_character_->getArmor() << "\n" <<
            "\n(ENEMY) " << combat_queue_.front()->getName() << ": LEVEL " << combat_queue_.front()->getLevel() << " " << combat_queue_.front()->getRace() << ". \n"
            <<"VITALITY: " << combat_queue_.front()->getVitality() << " \nARMOR: " << combat_queue_.front()->getArmor() << std::endl;
            // printResolutionActionResults(); 
          } else if (buff.name_ == "BUFF_MendMetal") 
          {
            main_character_->mendMetal();
            buff.turns_--;
            std::cout << main_character_->getName() << " used MendMetal!\n" << "(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"<< "VITALITY: " << main_character_->getVitality() << "\n" <<
            "ARMOR: " << main_character_->getArmor() << "\n" <<
            "\n(ENEMY) " << combat_queue_.front()->getName() << ": LEVEL " << combat_queue_.front()->getLevel() << " " << combat_queue_.front()->getRace() << ". \n"
            <<"VITALITY: " << combat_queue_.front()->getVitality() << " \nARMOR: " << combat_queue_.front()->getArmor() << std::endl;
          } if(buff.turns_>0) 
          {
            main_character_->getBuff().push(buff);
          }
        }
        while(!main_character_->getAction().empty()) 
        {
            int action = main_character_->getAction().front();
            main_character_->getAction().pop();

            if(action == Action::BUFF_Heal) 
            {
              Buff b;
              b.name_ = "BUFF_Heal";
              b.turns_ = 2;
              main_character_->heal();
              main_character_->getBuff().push(b);

              std::cout << main_character_->getName() << " used Heal!\n" << "(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"<< "VITALITY: " << main_character_->getVitality() << "\n" <<
            "ARMOR: " << main_character_->getArmor() << "\n" <<
            "\n(ENEMY) " << combat_queue_.front()->getName() << ": LEVEL " << combat_queue_.front()->getLevel() << " " << combat_queue_.front()->getRace() << ". \n"
            <<"VITALITY: " << combat_queue_.front()->getVitality() << " \nARMOR: " << combat_queue_.front()->getArmor() << std::endl;
              // printResolutionActionResults();

            } else if(action == Action::BUFF_MendMetal) 
            {
              Buff b;
              b.name_ = "BUFF_MendMetal";
              b.turns_ = 1;
              main_character_->mendMetal();
              main_character_->getBuff().push(b);
              std::cout << main_character_->getName() << " used MendMetal!\n" << "(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"<< "VITALITY: " << main_character_->getVitality() << "\n" <<
            "ARMOR: " << main_character_->getArmor() << "\n" <<
            "\n(ENEMY) " << combat_queue_.front()->getName() << ": LEVEL " << combat_queue_.front()->getLevel() << " " << combat_queue_.front()->getRace() << ". \n"
            <<"VITALITY: " << combat_queue_.front()->getVitality() << " \nARMOR: " << combat_queue_.front()->getArmor() << std::endl;
              // printResolutionActionResults();
              // print
            } else if(action == Action::ATT_Strike) 
            {
              main_character_->strike(combat_queue_.front());
              std::cout << main_character_->getName() << " used Strike!\n" << "(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"<< "VITALITY: " << main_character_->getVitality() << "\n" <<
            "ARMOR: " << main_character_->getArmor() << "\n" <<
            "\n(ENEMY) " << combat_queue_.front()->getName() << ": LEVEL " << combat_queue_.front()->getLevel() << " " << combat_queue_.front()->getRace() << ". \n"
            <<"VITALITY: " << combat_queue_.front()->getVitality() << " \nARMOR: " << combat_queue_.front()->getArmor() << std::endl;
              // printResolutionActionResults();

              if(combat_queue_.front()->getVitality()<=0) {
                std::cout << combat_queue_.front()->getName() << " DEFEATED" << std::endl;
                exitTavern(combat_queue_.front());
                combat_queue_.pop();
              }

              if(combat_queue_.empty()) {
                while(!main_character_->getAction().empty()) {
                  main_character_->getAction().pop();
                }
              }

            }

            else if(action == Action::ATT_ThrowTomato) 
            {
              main_character_->throwTomato(combat_queue_.front());
              std::cout << main_character_->getName() << " used ThrowTomato!\n" << "(YOU) " << main_character_->getName() << ": LEVEL " << main_character_->getLevel() << " " << main_character_->getRace() << ". \n"<< "VITALITY: " << main_character_->getVitality() << "\n" <<
            "ARMOR: " << main_character_->getArmor() << "\n" <<
            "\n(ENEMY) " << combat_queue_.front()->getName() << ": LEVEL " << combat_queue_.front()->getLevel() << " " << combat_queue_.front()->getRace() << ". \n"
            <<"VITALITY: " << combat_queue_.front()->getVitality() << " \nARMOR: " << combat_queue_.front()->getArmor() << std::endl;
              // printResolutionActionResults();
              // print
              if(combat_queue_.front()->getVitality()<=0) 
              {
                std::cout << combat_queue_.front()->getName() << " DEFEATED\n";
                exitTavern(combat_queue_.front());
                combat_queue_.pop();
              }

              if(combat_queue_.empty()) 
              {
                while(!main_character_->getAction().empty()) 
                {
                  main_character_->getAction().pop();
                }
              }

            }
         }
         std::cout << "END OF YOUR TURN\n" << std::endl;
       }
        
    }
  }



/**
        @param  : A pointer to the enemy
        @post   : Do all of the following:
                : 1. If the enemy's buff stack is not empty, apply buff once and decrement the
                  turns. Any time a Buff's turns_ goes to zero, it is removed
                  from the stack. Print out the results of the action as described below.
                : 2. Pick a random Action 
                    (one of BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato). 
                : If the selected action is a buff, apply once immediately and add it to the 
                  enemy's buff stack, performing the necessary turns update. 
                  Print out the results of the action as described below.
                : If the selected action is an attack, execute it against the main character.
                  Print out the results of the action as described below. 
                : More details:
                
                : After applying each action, print out the results of the action as follows:
                : [ENEMY NAME] used [ACTION NAME]!
                : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
                : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
*/

void Tavern::enemyTurn(Character* enemy) {
  
  std::cout << "ENEMY TURN" << std::endl;
  if(!enemy->getBuff().empty()) {

  Buff buff = main_character_->getBuff().top();
        main_character_ -> getBuff().pop();
        if(buff.name_ == "BUFF_Heal") 
       {
          enemy->heal();
          buff.turns_--;
          
          std::cout << enemy->getName() << " used Heal!"
            <<"\n(ENEMY) " << enemy->getName()<< ": LEVEL " << enemy->getLevel() << " " << enemy->getRace()
            <<". \nVITALITY: " << enemy->getVitality() << " \nARMOR: " << enemy->getArmor()<<"\n" 
            <<"\n(YOU) " << main_character_->getName() << ": LEVEL "<<main_character_->getLevel() << " " <<main_character_->getRace() << ". \n"
            <<"VITALITY: " << main_character_->getVitality() << " \nARMOR: " << main_character_->getArmor() << "\n";
       }
        else if(buff.name_ == "BUFF_MendMetal")
        {
            enemy->mendMetal();
            buff.turns_--;
            
            std::cout << enemy->getName() << " used MendMetal!"
            <<"\n(ENEMY) "<<enemy->getName()<<": LEVEL "<<enemy->getLevel()<<" "<<enemy->getRace()
            <<". \nVITALITY: "<<enemy->getVitality()<<" \nARMOR: "<<enemy->getArmor()<<"\n" 
            <<"\n(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<main_character_->getRace()<<". \n"
            <<"VITALITY: "<<main_character_->getVitality()<<" \nARMOR: "<<main_character_->getArmor()<<"\n";

        }

    if(buff.turns_>0)
      enemy->getBuff().push(buff);
  }

  srand(time(NULL));
  int random_action = rand()%4+1;

  if(random_action == Action::BUFF_Heal)
  {
    Buff buff;
    buff.name_ = "BUFF_Heal";
    buff.turns_ = 2;

    enemy->heal();
    enemy->getBuff().push(buff);

    // std::cout << enemy->getName() << " used Heal!" << std::endl;
    std::cout<<enemy->getName()<<" used Heal!"
    <<"\n(ENEMY) "<<enemy->getName()<<": LEVEL "<<enemy->getLevel()<<" "<<enemy->getRace()
    <<". \nVITALITY: "<<enemy->getVitality()<<" \nARMOR: "<<enemy->getArmor()<<"\n" 
    <<"\n(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<main_character_->getRace()<<". \n"
    <<"VITALITY: "<<main_character_->getVitality()<<" \nARMOR: "<<main_character_->getArmor()<<"\n";


  }
  else if(random_action == Action::BUFF_MendMetal)
  {
    Buff buff;
    buff.name_ = "BUFF_MendMetal";
    buff.turns_ = 1;

    enemy->mendMetal();
    enemy->getBuff().push(buff);

    // std::cout << enemy->getName() << " used MendMetal!" << std::endl;
    std::cout<<enemy->getName()<<" used MendMetal!"
    <<"\n(ENEMY) "<<enemy->getName()<<": LEVEL "<<enemy->getLevel()<<" "<<enemy->getRace()
    <<". \nVITALITY: "<<enemy->getVitality()<<" \nARMOR: "<<enemy->getArmor()<<"\n" 
    <<"\n(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<main_character_->getRace()<<". \n"
    <<"VITALITY: "<<main_character_->getVitality()<<" \nARMOR: "<<main_character_->getArmor()<<"\n";

  } 

    if (random_action == Action::BUFF_Heal) {
      enemy->heal();
      Buff buff;
      buff.name_ = "BUFF_Heal";
      buff.turns_ = 3;
      enemy->getBuff().push(buff);

      std::cout<<enemy->getName()<<" used Heal!"
      <<"\n(ENEMY) "<<enemy->getName()<<": LEVEL "<<enemy->getLevel()<<" "<<enemy->getRace()
      <<". \nVITALITY: "<<enemy->getVitality()<<" \nARMOR: "<<enemy->getArmor()<<"\n" 
      <<"\n(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<main_character_->getRace()<<". \n"
      <<"VITALITY: "<<main_character_->getVitality()<<" \nARMOR: "<<main_character_->getArmor()<<"\n";

    } else if (random_action == Action::BUFF_MendMetal) {
      enemy->mendMetal();
      Buff buff;
      buff.name_ = "BUFF_MendMetal";
      buff.turns_ = 2;
      enemy->getBuff().push(buff);

      std::cout<<enemy->getName()<<" used MendMetal!"
      <<"\n(ENEMY) "<<enemy->getName()<<": LEVEL "<<enemy->getLevel()<<" "<<enemy->getRace()
      <<". \nVITALITY: "<<enemy->getVitality()<<" \nARMOR: "<<enemy->getArmor()<<"\n" 
      <<"\n(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<main_character_->getRace()<<". \n"
      <<"VITALITY: "<<main_character_->getVitality()<<" \nARMOR: "<<main_character_->getArmor()<<"\n";

      // printEnemyActionResults(enemy);
    } else if (random_action == Action::ATT_Strike) {
      enemy->strike(main_character_);

      std::cout<<enemy->getName()<<" used Strike!"
      <<"\n(ENEMY) "<<enemy->getName()<<": LEVEL "<<enemy->getLevel()<<" "<<enemy->getRace()
      <<". \nVITALITY: "<<enemy->getVitality()<<" \nARMOR: "<<enemy->getArmor()<<"\n" 
      <<"\n(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<main_character_->getRace()<<". \n"
      <<"VITALITY: "<<main_character_->getVitality()<<" \nARMOR: "<<main_character_->getArmor()<<"\n";
      // printEnemyActionResults(enemy);
    } else if (random_action == Action::ATT_ThrowTomato) {
      enemy->throwTomato(main_character_);

      // printEnemyActionResults(enemy);
      std::cout<<enemy->getName()<<" used ThrowTomato!"
      <<"\n(ENEMY) "<<enemy->getName()<<": LEVEL "<<enemy->getLevel()<<" "<<enemy->getRace()
      <<". \nVITALITY: "<<enemy->getVitality()<<" \nARMOR: "<<enemy->getArmor()<<"\n" 
      <<"\n(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<main_character_->getRace()<<". \n"
      <<"VITALITY: "<<main_character_->getVitality()<<" \nARMOR: "<<main_character_->getArmor()<<"\n";
    }
    std::cout << "END OF ENEMY TURN\n";
  } 
  
  // else {
  //   Buff buff = enemy->getBuff().top();
  //   // buff.apply();
  //   buff.turns_--;

  //   if (buff.turns_ <= 0) {
  //     enemy->getBuff().pop();
  //   }

  //   printEnemyActionResults(enemy);
  // }



/**
        @post : While the main character's vitality is > 0, and there are still enemies 
                  in the combat queue, do the following:
              :     - Call actionSelection()
                    - Call turnResolution()
                    - Call enemyTurn() with a pointer to the first enemy on combat queue.

              : If the main character's vitality has fallen to 0, print "YOU HAVE PERISHED."
              : If there are no more enemies in the combat queue, print "NO MORE ENEMIES."
*/
void Tavern::combat() {

  if (main_character_ != nullptr) {
    while (main_character_->getVitality() > 0 && !combat_queue_.empty()) {
      actionSelection();
      turnResolution();
      if(!combat_queue_.empty())
      enemyTurn(combat_queue_.front());
    }

    if (main_character_->getVitality() <= 0) {
      std::cout << "YOU HAVE PERISHED.\n";
    } else {
      std::cout << "NO MORE ENEMIES.\n";
    }
  }
}