This program is an object-oriented C++ application designed to analyze daily produce purchase records for a corner grocer. It processes a text file to calculate the frequency of each item purchased and provides an interactive menu for the user to access this information in several formats. 

Design and functionality
Object-Oriented Design (OOP)
The code is structured with a clear separation of concerns, primarily using two classes: Produce and MenuHandler. This makes the code modular, readable, and easier to maintain.
•	Produce class: This class is responsible for all data-related logic.
o	Encapsulation: It encapsulates the data and the methods that operate on that data. The itemFrequency map, which stores the purchase counts, is a private member, preventing direct modification from outside the class.
o	Data processing: The processFile() method reads the specified input file, counts the occurrences of each produce item, and stores the results in the itemFrequency map. It handles potential file not found errors gracefully.
o	Data backup: The new backupData() method writes the accumulated frequency data to a file named frequency.dat. This provides a persistent record of the daily purchase analysis, which can be useful for long-term tracking or for reloading data if needed.
o	Data normalization: The private normalizeItem() method is used to ensure consistent counting by converting all item names to lowercase. This means "Apples" and "apples" are treated as the same item.
o	Data presentation: It includes methods to print the item frequencies in a list (printFrequencyList()) and as a text-based histogram (printHistogram()).
o	Data retrieval: The findItemFrequency() method allows a specific item's frequency to be retrieved.

•	MenuHandler class: This class manages all user interactions.
o	User interface: It displays the main menu, prompts the user for input, and validates that input.
o	Delegation: Rather than handling the data analysis itself, the MenuHandler holds a reference to a Produce object and delegates tasks like finding an item's frequency or printing a list to the Produce object. This maintains a clean separation between the user interface and the core data logic.
o	Execution loop: The run() method contains the main program loop that keeps the menu active until the user chooses to exit. 

Functionality
The program's core function is to provide the grocer with actionable insights from their sales data.
1.	File processing: Upon startup, the program reads the CS210_Project_Three_Input_File.txt file.
2.	Item analysis: It performs a frequency analysis to count how many times each type of produce was purchased.
3.	Interactive menu: The user is presented with a menu of options:
1.	Option 1: Look up the purchase frequency of a specific produce item.
2.	Option 2: Display a complete list of all produce items and their purchase counts.
3.	Option 3: Visualize the data in a text-based histogram, where each asterisk represents one purchase.
4.	Option 4: Exit the program.
4.	Error handling: The program includes a try-catch block in its main function to handle a file not found error during initialization, ensuring that the application exits gracefully if the input file is missing.
