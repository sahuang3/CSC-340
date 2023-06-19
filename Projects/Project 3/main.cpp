// Copyright 2022, Samson Huang, All rights reserved.
// This file is part of CSC 340 - Assignment 3.1

/* Summary:
    This program will take a sentence from the user. Then the program will output the words in the 
    sentence in a reversed order using our stack implementation. Next, the program will check if
    the sentence is a palindrome.
*/

#include <iostream>
#include <stack>
#include <string>
#include "Stack.h"

using namespace std;

// Reversing the string
void reverse(string item){
    stack<string> revStack;
    string temp = ""; // temporary space holder
    for(int i=0; i<item.length(); i++){
        if(item[i] == ' '){
            revStack.push(temp);
            temp = "";
        } else{
            temp = temp + item[i];
        }
    }
    revStack.push(temp);

    while(!revStack.empty()){
        temp = revStack.top();
        cout << temp << " ";
        revStack.pop();
    }
    cout << endl;
}

void palindrome(string item){
    stack<string> palStack;
    string temp = ""; // temporary space holder
    
    // Filling up stack with temporary space holder for item
    for(int i=0; i<=item.length(); i++){
        if(item[i] >= 'a' && item[i] <= 'z'){
            palStack.push(temp);
            temp = "";
        }
    }
    palStack.push(temp);
    item = temp;
}

bool palindromeCheck(string input, int num){
    int middle = input.size()/2;
    if(num > middle){
        return true;
    }
    // checking if index is equal to opposite index of string and changing the bounds
    return input[num] == input[input.size() - num - 1] && palindromeCheck(input, num + 1);
}

int main(){

    string userInput;

    cout << "Enter a sentence: ";
    getline(cin, userInput);
    
    cout << "Reversing your sentence: \n";
    reverse(userInput);


    // Convert whole string to lowercase to make it easier
    for(int i=0; i<userInput.length(); i++){
        userInput[i] = tolower(userInput[i]);
    }

    palindrome(userInput);
    if(palindromeCheck(userInput, 0)){
        cout << "\"" << userInput << "\" is a palindrome";
    } else{
        cout << "\"" << userInput << "\" is not a palindrome";
    }
    
    return 0;
}
