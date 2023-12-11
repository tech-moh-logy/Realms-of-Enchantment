# Algorithmic Adventures: Into the Recursive Realms
## Project 4 - The Tainted Stew

### Task 1: Modify the Character Class and Its Subclasses

#### Character Class Modifications

- Making the `display()` function pure virtual
- Adding a new pure virtual function: `eatTaintedStew`

#### Barbarian Class Modifications

- Adding `display` function to display Barbarian information
- Implementing `eatTaintedStew` function for Barbarians

#### Mage Class Modifications

- Adding `display` function to display Mage information
- Implementing `eatTaintedStew` function for Mages

#### Ranger Class Modifications

- Adding `display` function to display Ranger information
- Implementing `eatTaintedStew` function for Rangers

#### Scoundrel Class Modifications

- Adding `display` function to display Scoundrel information
- Implementing `eatTaintedStew` function for Scoundrels

### Task 2: Modify the Tavern Class

#### Changes in Tavern Class

- Change storage to pointers of Characters rather than Character objects
- Implement a parameterized constructor that reads from a formatted input file

#### Additional Member Functions

- `displayCharacters`: Display all characters' information in the tavern
- `displayRace`: Display characters' information based on a specified race
- `taintedStew`: All characters in the tavern eat a tainted stew
