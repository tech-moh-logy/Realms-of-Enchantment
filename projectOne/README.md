Algorithmic Adventures: Into the Recursive Realms
Project 1 - The Character class: A Review of OOP

----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 

Task: The Character class
- Every Character has a Name, Race, Health, Armor, Level, and a boolean if the character is an enemy.
- The Character class must define the following types:
- An enum named Race  with values {NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD}
- The Character class must have the following private member variables:

----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 

private:
- The name of the character (a string in UPPERCASE)
- The race of the character (an enum)
- The character's vitality (a non-negative integer)
- The character's max armor level (a non-negative integer)
- The character's level (a non-negative integer)
- A flag indicating whether the character is an enemy
 

The Character class must have the following public member functions:

Constructors


 /**
      Default constructor.
      Default-initializes all private members. 
      Default character name: "NAMELESS". 
      Booleans are default-initialized to False. 
      Default enum value: NONE. 
      Default Vitality, Max Armor, and Level: 0.
   */


  /**
  Parameterized constructor.
  @param      : The name of the character (a string in UPPERCASE)
  @param      : The race of the character (a string)
  @param      : The character's vitality (a non-negative integer) , with default  
                value 0
  @param      : The character's max armor level (a non-negative integer), with 
                default value 0
  @param      : The character's level (non-negative integer), with default value 0
  @param      : A flag indicating whether the character is an enemy, with default 
                value false
  @post       : The private members are set to the values of the corresponding 
                parameters.
  */

Hint: Notice the default argument in the parameterized constructor.

Accessors (get) and Mutators (set)



   /**
            @param  : the name of the Character
            @post   : sets the Character's title to the value of the parameter, 
                      in UPPERCASE. Only alphabetical characters are allowed. 
                      For example, attempting to create a character named 
                      "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
                    : If the given parameter does not have any valid alphabetical
                      characters, the character's name should be set to "NAMELESS".
*/
 setName


  /**
      @return : the name of the Character
  */
 getName


   /**
       @param  : the race of the Character (a string)
       @post   : sets the Character's race to the value of the parameter.
                 If the given race was invalid, set race_ to NONE.
  */
 setRace


  /**
      @return : the race of the Character (a string)
   */
 getRace


  /**
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
              if vitality is negative, do nothing.
  */
 setVitality


  /**
      @return : the value stored in vitality_
   */
 getVitality

  /**
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
              if armor is negative, do nothing.
  */
 setArmor


  /**
      @return : the value stored in armor_
   */
 getArmor

  /**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
              if level is negative, do nothing.
  */
 setLevel


  /**
      @return : the value stored in level_
   */
 getLevel



  /**
   @post   : sets the enemy flag to true
  */
 setEnemy


   /**
    @return true if the character is an enemy, false otherwise

    Note: this is an accessor function and must follow the same convention as all accessor  
          functions even if it is not called getEnemy
   */
   isEnemy
