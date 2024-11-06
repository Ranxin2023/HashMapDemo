# C HashMap Implementation
This project is a custom implementation of a HashMap data structure in C, designed to store words and their frequencies. It includes basic operations like insertion, lookup, and existence checks. The program also measures the time taken to perform existence checks for a large number of randomly generated words.

## Project Structure
- main.c: Contains the main function to initialize the HashMap, insert entries, and check if entries exist in the map.
- StringCountHashMap.h: Header file that defines the HashMap structure and function prototypes.
- StringCountHashMap.c: Source file that implements the HashMap operations, including:
createHashMap: Creates a new HashMap with a specified initial capacity.
insertEntry: Inserts a key-value pair (word and frequency) into the HashMap.
getOrDefault: Gets the frequency of a word if it exists, or returns 0 if it doesn’t.
existInTable: Checks if a word exists in the HashMap.
printHashMap: Prints all words and their frequencies in the HashMap.
## Installation and Compilation
Install MinGW (for Windows users):

Download and install MinGW from here.
Add C:\MinGW\bin to your system's PATH environment variable.
Compile the Project:

Open a terminal in the project directory.
Run the following commands to compile the project:
```sh
mingw32-make

Run the Program:

Execute the compiled program:
bash
Copy code
./smdemo
Usage
The program will:

Create a HashMap with twice the capacity of the number of words to be checked.
Generate random words, insert them into the HashMap, and set their frequency.
Check if the words exist in the map and print the time taken for the existence checks.
You can modify the number of words to be generated and checked by adjusting the WORDSLEN constant in main.c.

Example Output
bash
Copy code
Time spent for checking 50000 words: 0.004000 seconds
Time spent for checking 100000 words: 0.011000 seconds
Implementation Details
Hash Function
The HashMap uses a custom hash function to calculate the index for each word. This can be adjusted or optimized further if needed.

Memory Management
The HashMap dynamically allocates memory for each entry’s key. Make sure to free the allocated memory after use to avoid memory leaks.