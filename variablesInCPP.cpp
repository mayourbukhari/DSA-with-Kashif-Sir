// This is a basic C++ program that demonstrates the use of variables and cout statements for output. 
// The program defines two variables—characterName (a string) and characterAge (an integer)—and 
// prints a short story using these variables.

// Key concepts covered:

// Variables – Used to store character details.
// Data Types – string for text, int for numbers.
// cout for Output – Used to print text to the console.
// Concatenation – Combining variables with text for meaningful output.



#include <iostream>  // Include the standard input-output library
using namespace std; // Use the standard namespace to avoid using std:: before functions

int main()  // Main function where execution begins
{
    string characterName = "Mayour"; // Declare and initialize a string variable
    int characterAge = 23;           // Declare and initialize an integer variable

    // Print the first sentence with the character's name
    cout << "There once was a man named " << characterName << endl;

    // Print the second sentence with the character's age
    cout << "He is " << characterAge << " years old" << endl;

    return 0; // Indicate that the program executed successfully
}
