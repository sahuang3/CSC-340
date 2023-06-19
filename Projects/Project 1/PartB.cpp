// Copyright 2022, Samson Huang, All rights reserved.
// This file is part of CSC 340 - Assignment 1

/* Summary:
    This program will take the user's input of any 5-digit numbers and converts their input from the datatypes "int" into 
    a "string". Then, it will print each index of the string with 3 spaces in between each number.
*/

#include <iostream>

using namespace std;

/* Program Design: 
    We want to take a 5-digit number from the user, convert it into a string, and use for-loop to print each index of the string
    with 3 spaces in between
*/

int main(){
    
    // Initializing Variables
    int user_input; 

    // Taking the user's input
    cout << "Input a 5 digit number: \n";
    cin >> user_input; 

    //TODO: Maybe there's another way to approach this instead of converting "int" to "string" datatype
    // Converting the user's input into String
    string converted_input = to_string(user_input); 

    // Using For-Loop to print out each index of the String
    for (int i=0; i < 5; i++) 
    cout << converted_input[i] << "   ";
    return 0;
}
