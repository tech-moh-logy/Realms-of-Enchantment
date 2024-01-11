# Mohammed's Project 6 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

## Project Overview

This project involves implementing the necessary functionality for characters to engage in combat within the Tavern. There are two main tasks:

1. **Modify the `Character` class**
   - Define necessary data types (enum `Action` and struct `Buff`).
   - Add an action queue and a buff stack to the `Character` class.
   - Implement additional methods for buff and attack actions.

2. **Modify the `Tavern` class**
   - Maintain a main character and a combat queue of enemies.
   - Manage combat by alternating turns between the main character and enemies.
   - Implement various methods to handle combat, character comparisons, and more.

## Task 1: Modify the Character class

### Data Types
- Enum `Action` with values `{BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato}`
- Struct `Buff` with members `{string name_, int turns_}`

### Additional Data Members
- Action queue (queue of integers)
- Buff stack (stack of Buff objects)

### Additional Methods
- `heal`: Execute the `BUFF_Heal` action.
- `mendMetal`: Execute the `BUFF_MendMetal` action.
- `strike(target)`: Execute the `ATT_Strike` action against the target character.
- `throwTomato(target)`: Execute the `ATT_ThrowTomato` action against the target character.

*(Continue with the rest of the Character class modifications)*

## Task 2: Modify the Tavern class

### Data Types
- Pointer to the main character.
- Combat queue of Character pointers for enemies.

### Additional Methods
- `setMainCharacter(character)`: Set the main character of the Tavern.
- `getMainCharacter()`: Get a pointer to the main character.
- `levelIsLess(lhs, rhs)`: Check if the level of lhs character is less than rhs character.
- `levelIsGreater(lhs, rhs)`: Check if the level of lhs character is greater than rhs character.
- `vitalityIsLess(lhs, rhs)`: Check if the vitality of lhs character is less than rhs character.
- `vitalityIsGreater(lhs, rhs)`: Check if the vitality of lhs character is greater than rhs character.
- `createCombatQueue(filter)`: Create a combat queue based on the specified filter.
- `getTarget()`: Get a pointer to the character at the front of the combat queue.
- `printCombatQueue()`: Print details of characters in the combat queue.
- *(Continue with the rest of the Tavern class modifications)*

## Authors

- Mohammed
