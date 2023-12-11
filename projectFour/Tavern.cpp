// Mohammed's Project 1 - Algorithmic Adventures: Into the Recursive Realms

#include "Tavern.hpp"

// Tavern::Tavern(const std::string& character_file)
// // :ArrayBag<Character*>()
// {
//     std::ifstream fin(character_file);

//     if(fin.fail())
//     {
//         std::cerr<<"The file failed to open!\n";
//         exit(1);
//     }

//     std::string domestic_refuse;
//     getline(fin, domestic_refuse);

//     std::string name, race, sub_class, main, secondary, school_or_faction, temp_string;
//     int level, vitality, armor;
//     bool enemy, summoning, disguise, enraged;
//     std::vector<std::string> affinities;
//     std::vector<Arrows> arrows;

//     while (getline(fin, temp_string))
//     {   std::istringstream x(temp_string);
//         getline(fin, temp_string, ',');
//         name = temp_string;

//         getline(fin, temp_string, ',');
//         race = temp_string;

//         getline(fin, temp_string, ',');
//         sub_class = temp_string;

//         getline(fin, temp_string, ',');
//         std::istringstream(temp_string)>>level;
//         // level=std::stoi(temp_string);

//         getline(fin, temp_string, ',');
//         std::istringstream(temp_string)>>vitality;
//         // vitality=std::stoi(temp_string);

//         getline(fin, temp_string, ',');
//         std::istringstream(temp_string)>>armor;
//         // armor=std::stoi(temp_string);

//         getline(fin, temp_string, ',');
//         if (temp_string == "0") 
//         {
//             enemy = false;
//         }
//         else 
//         {
//             enemy = true;
//         }

//         if (sub_class != "RANGER")
//         {
//             getline(fin, main, ',');
//         } 
//         else 
//         {

//             // int counter = 0;

//             getline(fin, temp_string, ','); // WOOD 30; WATER 5; BLOOD 10
//             std::stringstream ss(temp_string);
//             std::string random;

//             while(getline(ss, random,';')) { //WOOD 30
//                 std::stringstream breaking(random);
//                 std::string random_b;
//                 while(getline(breaking, random_b,' ')){ //WOOD and 30
//                     Arrows arrowss;
//                     arrowss.type_ = random_b;
//                     getline(breaking, random_b);
//                     arrowss.quantity_ = std::stoi(random_b);
//                     arrows.push_back(arrowss);
//                 }
//             }


//             while(getline(ss, random,';')) { //WOOD 30
//                 // std::stringstream breaking(random);
//                 std::string random_b;
//                 // while(getline(breaking, random_b,' ')){ //WOOD and 30
//                 //     Arrows arrowss;
//                 //     arrowss.type_ = random_b;
//                 //     getline(breaking, random_b);
//                 //     arrowss.quantity_ = std::stoi(random_b);
//                 //     affinities.push_back(affinities);
//                 // }
//             }

//             // while (counter < temp_string.length())
//             // {
//             //     std::string type;
//             //     std::string quantity;

//             //     while (temp_string[counter] != ' ')
//             //     {
//             //         type = type + temp_string[counter];
//             //         counter = counter + 1;
//             //     }
//             //     counter = counter + 1;

//             //     while (counter < temp_string.length() && temp_string[counter] != ';')
//             //     {
//             //         quantity = quantity + temp_string[counter];
//             //         counter = counter + 1;
//             //     }

//             //     int quantity_of_arrows = std::stoi(quantity);
//             //     arrows.push_back({type, quantity_of_arrows});
//             //     counter = counter + 1;
//             // }
//         }

//         getline(fin, temp_string, ',');
//         secondary = temp_string;

//         getline(fin, temp_string, ',');
//         school_or_faction = temp_string;

//         getline(fin, temp_string, ',');
//         if (temp_string == "0") 
//         {
//             summoning = false;
//         }
//         else 
//         {
//             summoning = true;
//         }

//         getline(fin, temp_string, ',');
//         int counter = 0;

//         while (counter < temp_string.length()) 
//         {
//             std::string affinity;

//             while (temp_string[counter] != ';' && counter < temp_string.length())
//             {
//                 affinity = affinity + temp_string[counter];
//                 counter = counter + 1;
//             }
//            // std::cout << affinity << std::endl;
//             affinities.push_back(affinity);
//             counter = counter + 1;
//         }

//         getline(fin, temp_string, ',');
//         if (temp_string == "0") 
//         {
//             disguise = false;
//         }
//         else 
//         {
//             disguise = true;
//         }

//         getline(fin, temp_string, ',');
//         std::istringstream(temp_string)>>enraged;

//         if (sub_class == "RANGER")
//         {
//             Character* character_ptr = new Ranger(name,race,vitality,armor,level,enemy,arrows,affinities,summoning);
//             enterTavern(character_ptr);
//             // character_ptr = nullptr;
//         }
//         else if (sub_class == "MAGE")
//         {
//             Character* character_ptr = new Mage(name,race,vitality,armor,level,enemy,school_or_faction,main,summoning);
//             enterTavern(character_ptr);
//             // character_ptr = nullptr;
//         }
//         else if (sub_class == "SCOUNDREL")
//         {
//             Character* character_ptr = new Scoundrel(name,race,vitality,armor,level,enemy,main,school_or_faction,disguise);
//             enterTavern(character_ptr);
//             // character_ptr = nullptr;
//         }
//         else if (sub_class == "BARBARIAN")
//         {
//             // Character* character_ptr = new Barbarian(name,race,vitality,armor,level,enemy,main,secondary,enraged);
//             Character* character_ptr = new Barbarian(name,race,vitality,armor,level,enemy,main,secondary,enraged);
//             enterTavern(character_ptr);
//             // character_ptr = nullptr;
//         }

//         // arrows.clear();
//         // affinities.clear();
//     }
// }
/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows (each numbered item appears separated by comma, only one value for each numbered item):
      1. Name: An uppercase string
      2. Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      3. Subclass: An uppercase string [BARBARIAN, MAGE, SCOUNDREL, RANGER]
      4. Level/Vitality/Armor: A positive integer
      5. Enemy: 0 (False) or 1 (True)
      6. Main: Uppercase string or strings representing the main weapon (Barbarian and Mage), Dagger type (Scoundrel), or arrows (Ranger). A ranger's arrows are of the form [TYPE] [QUANTITY];[TYPE] [QUANTITY], where each arrow type is separated by a semicolon, and the type and its quantity are separated with a space.
      7. Offhand: An uppercase string that is only applicable to Barbarians, and may be NONE if the Barbarian does not have an offhand weapon, or if the character is of a different subclass.
      8. School/Faction: Uppercase strings that represent a Mage's school of magic: [ELEMENTAL, NECROMANCY, ILLUSION] or a Scoundrel's faction: [CUTPURSE, SHADOWBLADE, SILVERTONGUE], and NONE where not applicable
      9. Summoning: 0 (False) or 1 (True), only applicable to Mages (summoning an Incarnate) and Rangers (Having an Animal Companion)
      10. Affinity: Only applicable to Rangers. Affinities are of the form [AFFINITY1];[AFFINITY2] where multiple affinities are separated by a semicolon. Th value may be NONE for a Ranger with no affinities, or characters of other subclasses.
      11. Disguise: 0 (False) or 1 (True), only applicable to Scoundrels, representing if they have a disguise.
      12. Enraged: 0 (False) or 1 (True), only applicable to Barbarians, representing if they are enraged.
    @post: Each line of the input file corresponds to a Character subclass and dynamically allocates Character derived objects, adding them to the Tavern.
*/

// NOTE: I Got Help For This
Tavern::Tavern(const std::string& document):ArrayBag<Character *>(){
    std::string Name, Race, Subclass, Level, Vitality, Armor, Enemy, Main, Offhand, SchoolorFactio, Summoning, Affinity, Disguise, Enraged;
    std::string arrowTally, arrowKind, arrowQuantity;
    
    // if file does not open, exit out:
    std::ifstream fin(document);
    if(fin.fail()){
        std::cerr << "Error 404" << std::endl;
        exit(1);
    }

    std::string lineReader;
    std::getline(fin, lineReader);
    while(std::getline(fin, lineReader)){
        // "loops" through all the columns:
        // check for ";"
        std::istringstream scanner(lineReader);
        std::getline (scanner, Name, ',');
        std::getline (scanner, Race,',');
        std::getline (scanner, Subclass,',');
        std::getline (scanner, Level,',');
        int level = std::stoi(Level);
        std::getline (scanner, Vitality,',');
        int vitality = std::stoi(Vitality);
        std::getline (scanner, Armor,',');
        int armor = std::stoi(Armor);
        std::getline (scanner, Enemy,',');
        int enemy = std::stoi(Enemy);
        std::getline (scanner, Main,',');
        std::getline (scanner, Offhand,',');
        std::getline (scanner, SchoolorFactio,',');
        std::getline (scanner, Summoning,',');
        int summoning = std::stoi(Summoning);
        std::getline (scanner, Affinity,',');
        std::getline (scanner, Disguise,',');
        int disguise = std::stoi(Disguise);
        std::getline (scanner, Enraged,',');
        int enraged = std::stoi(Enraged);
        

        // 1. The code checks the value of the variable  Subclass  to determine the type of character being created. 
        
        // 2. If  Subclass  is equal to the string "BARBARIAN", it creates a new instance of the  Barbarian  class, passing in various parameters such as  Name ,  Race ,  vitality ,  armor ,  level ,  enemy ,  Main ,  Offhand , and  enraged . It then calls the  enterTavern()  function, passing the newly created  Barbarian  object. 
        
        // 3. If  Subclass  is equal to the string "MAGE", it creates a new instance of the  Mage  class, passing in parameters similar to the previous case, but with  SchoolorFactio  and  summoning  instead of  Offhand  and  enraged . It then calls the  enterTavern()  function, passing the  Mage  object. 
        
        // 4. If  Subclass  is equal to the string "SCOUNDREL", it creates a new instance of the  Scoundrel  class, passing in parameters similar to the previous cases, but with  disguise  instead of  summoning . It then calls the  enterTavern()  function, passing the  Scoundrel  object. 
        if(Subclass == "BARBARIAN"){
            Barbarian *a_character = new Barbarian(Name, Race, vitality, armor, level, enemy, Main, Offhand, enraged);
            enterTavern(a_character);
        } else if(Subclass == "MAGE"){
            Mage *a_character = new Mage(Name, Race, vitality, armor, level, enemy, SchoolorFactio, Main, summoning);
            enterTavern(a_character);
        } else if(Subclass == "SCOUNDREL"){
            Scoundrel *a_character = new Scoundrel(Name, Race, vitality, armor, level, enemy, Main, SchoolorFactio, disguise);
            enterTavern(a_character);
        } 
        // 1. The code checks the value of the variable  Subclass  to determine the type of character being created. 
        
        // 2. If  Subclass  is equal to the string "RANGER", it creates a new instance of the  Ranger  class, passing in various parameters such as  Name ,  Race ,  vitality ,  armor ,  level ,  enemy ,  arrowsbag ,  af , and  summoning .  
        
        // 3. The  arrowsbag  parameter is a vector of  Arrows  objects, which are defined elsewhere in the program. The code creates an empty vector called  arrowsbag , then uses a  while  loop to read in the contents of the  Main  parameter (which is a string of the form "arrowType1:quantity1;arrowType2:quantity2;..."). The loop uses a series of  istringstream  objects to extract the arrow type and quantity from each entry, convert the quantity to an integer using  stoi() , and push a new  Arrows  object onto the  arrowsbag  vector. 
        
        // 4. The  af  parameter is a vector of strings representing the ranger's affinities. The code creates an empty vector called  af , then uses another  while  loop to read in the contents of the  Affinity  parameter (which is a string of the form "affinity1;affinity2;..."). The loop uses  std::getline()  to extract each affinity string and push it onto the  af  vector. 
        
        // 5. Finally, the code creates a new  Ranger  object using the parameters it has collected, and passes it to the  enterTavern()  function.        
        
        else if(Subclass == "RANGER") {
            std::vector<Arrows> arrowsbag = {};
            std::vector<std::string> af = {};

            std::istringstream main_ss(Main);
            while(std::getline(main_ss, arrowTally, ';')) {
                std::istringstream totalarrows_ss(arrowTally);
                totalarrows_ss >> arrowKind >> arrowQuantity;
                int quantity = stoi(arrowQuantity);
                arrowsbag.push_back({arrowKind, quantity});
            }

            std::istringstream affinity(Affinity);
            std::string save_affinity;
            while(std::getline(affinity,save_affinity,';')) {
              af.push_back(save_affinity);
            }
            Ranger *a_character = new Ranger(Name, Race, vitality, armor, level, enemy, arrowsbag, af, summoning);
            enterTavern(a_character);
        }
    }
    fin.close();
}


/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0} {}

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

// void Tavern::tavernReport() {
//     int humans = tallyRace("HUMAN");
//     int elves = tallyRace("ELF");
//     int dwarves = tallyRace("DWARF");
//     int lizards = tallyRace("LIZARD");
//     int undead = tallyRace("UNDEAD");

//     int totalCharacters = item_count_;

//     // Calculate the average level
//     int avgLevel = calculateAvgLevel();

//     // Calculate the enemy percentage
//     double enemyPercentage = calculateEnemyPercentage();

//     // Display the race tally
//     std::cout << "Humans: " << humans << std::endl;
//     std::cout << "Elves: " << elves << std::endl;
//     std::cout << "Dwarves: " << dwarves << std::endl;
//     std::cout << "Lizards: " << lizards << std::endl;
//     std::cout << "Undead: " << undead << std::endl;
//     std::cout << "\n";

//     // Display the average level and enemy percentage
//     std::cout << "The average level is: " << avgLevel << std::endl;
//     std::cout << std::fixed << std::setprecision(2) << enemyPercentage << "% are enemies." << std::endl;
//     std::cout << "\n";

//     // Display the total character count
//     std::cout << "Total characters in the tavern: " << totalCharacters << std::endl;
// }


// ------------- MODIFIED FOR PROJECT 4 -------------
// Tavern::Tavern(Character* character_) {
//   characters_.push_back(character);
// }


void Tavern::displayCharacters() {
//   for (auto character : items_) {
//     character->display();
//   }
  for(int x=0;x<getCurrentSize();x++){
    items_[x]->display();
  }
}

// void Tavern::displayCharacters() {
//     for (int x = 0; x < getCurrentSize(); x++) {
//         items_[x]->display();
//     }
// }


void Tavern::displayRace(const std::string& race) {
  for (auto character : items_) {
    if (character->getRace() == race) {
      character->display();
    }
  }
}

void Tavern::taintedStew() {
  for (auto character : items_) {
    character->eatTaintedStew();
  }
}
