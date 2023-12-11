# Algorithmic Adventures: Into the Recursive Realms
## Project 5 - Quest Management with Doubly Linked Lists

### Task 1: Implement the Quest Struct

#### Quest Struct Definition

- `title_`: A string representing the quest title
- `description_`: A string representing the quest description
- `completed_`: A boolean representing if the quest is completed
- `experience_points_`: An integer representing experience points the quest rewards upon completion
- `dependencies_`: A vector of Quest pointers representing the quest's dependencies
- `subquests_`: A vector of Quest pointers representing the quest's subquests

#### Constructors

- Default Constructor
- Constructor with parameters for title, description, completion status, experience points, dependencies, and subquests

### Task 2: Implement the QuestList Class as a Subclass of DoublyLinkedList

#### QuestList Class

- Stores POINTERS to Quest objects
- Public Member Functions:
    - Constructors: Default Constructor and a constructor with an input file name
    - `getPosOf`: Returns the integer position of a given quest title
    - `contains`: Checks if a quest with a given title is in the QuestList
    - `addQuest`: Inserts a quest pointer into the QuestList along with its dependencies and subquests
    - `dependenciesComplete`: Checks if all dependencies of a given quest are completed
    - `questAvailable`: Checks if a quest is available to start
    - `printQuest`: Prints the quest title and completion status
    - `questQuery`: Provides details on quest dependencies and readiness
    - `calculateGainedExperience`: Calculates total experience gained from completed quests
    - `calculateProjectedExperience`: Calculates total projected experience from a main quest and its subquests
    - `calculatePathwayExperience`: Calculates total experience gained from completed subquests
    - `questHistory`: Prints quests based on a filter (Complete, Incomplete, Available)
    - `printQuestDetails`: Prints subquest pathway and completion percentages

### Task 3: Debugging Help

- Use the provided `debug.csv` file for testing `questQuery` and `printQuestDetails`
- Sample code snippet to test:
    ```cpp
    // ... (Code to instantiate QuestList and load data from debug.csv)

    std::cout << "Testing questQuery:" << std::endl << std::endl;
    questList.questQuery("Quest 1");
    std::cout << std::endl;

    std::cout << "Testing printQuestDetails:" << std::endl << std::endl;
    Quest* current = questList.getPointerTo(questList.getPosOf("Quest 1"))->getItem();
    questList.printQuestDetails(current);
    std::cout << std::endl;
    ```
- Expected output provided for comparison after running the test code

