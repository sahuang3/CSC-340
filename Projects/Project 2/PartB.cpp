// Copyright 2022, Samson Huang, All rights reserved.
// This file is part of CSC 340 - Assignment 2

/* Summary:
    This program will take the user's input of any string. Then the program will check if the word given by the 
    user is a palindrome or not. If the word is a palindrome, it will output "True". Otherwise, it will output
    "False".
*/

#include <iostream>
#include <string>

using namespace std;

/* Program Design: 
    We want to take a string from the user. Then we will convert the string into only lowercase characters in the 
    alphabet and remove whitespaces/special characters. After we have the converted string, we then call a function
    to check if the user's input is empty or not, it will return true if it's empty. If string isn't empty, we call
    another function to check if the string is a palindrome using recursion. If the string is a palindrome, 
    the output will be true, otherwise it will be false.
*/

bool palindrome(string input, int first, int last){

    // Base Cases: 1 char, 1st and last char is not the same
    if (first == last){
        return true;
    }
    if (input[first] != input[last]){
        return false;
    }
    if(first < last){
        return palindrome(input, first + 1, last -1);
    }
    return true;
}

/* TODO: I'm not sure if this program could be coded using only 1 function because the only solution I came up with
    was to use 2 functions where we have to solve for the palindrome and check if it's a palindrome. But if there
    was a way to implement this into a singular function, this would definitely be something I should improve on. 
*/

bool palindromeCheck(string input){

    int size = input.length();
    if (size == 0){
        return true;
    }
    return palindrome(input, 0, size-1);
}

int main(){
    
    string userInput;
    cout << "Input: ";
    getline(cin, userInput);
    for(int i=0; i<userInput.size(); i++){
        userInput[i] = tolower(userInput[i]);
    }

    // Removing whitespaces and special characters
    int temp=0;
    for (int i=0; i < userInput.size(); i++){
        if((userInput[i] >= 'A' && userInput[i] <= 'Z') || (userInput[i] >= 'a' && userInput[i] <= 'z')){
            userInput[temp] = userInput[i];
            temp++;
        }
    }
    string convertedString;
    convertedString = userInput.substr(0,temp);

    if(palindromeCheck(convertedString)){
        cout << "Output: true \n";
        cout << "Explanation: \"" << convertedString << "\" is a palindrome.";
    } else{
        cout << "Output: false \n";
        cout << "Explanation: \"" << convertedString << "\" is not a palindrome.";
    }

    return 0;
}
