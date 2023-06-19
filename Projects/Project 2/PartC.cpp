// Copyright 2022 - Samson Huang
// Email: shuang18@mail.sfsu.edu
// This file is part of CSC 340 - Assignment 2


/* Summary:
    This program is a memory game where a few words will flash onto the screen and you have 1 second to 
    memorize it and type the words you've seen. In the beginning, the game will only flash 2 words onto your
    screen. For each word you got correct will give you 1 point, otherwise you lose 1 point for each word.
    Every 4 points you get will increase the difficulty by 1 word. The program will stop when you enter 'q' or
    if you have more than 10 points.
*/


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include<chrono>
#include<thread>
#include <iostream>
#include <cstdlib>
#define cls() std::cout <<"\033[2J\033[1;1H";

using namespace std;


/* Program Design: 
    First, we need to initialize a string array with all the words. Then, we ask if the user wants to play the 
    game by having them type 'y' or 'n'. We will then generate random words using a random number generator 
    ranging to 49 (there are 49 words) and assigning a string array with the index numbers from the words list.
    After it has been assigned, it will then flash the words onto the screen for 1 second and the user will try 
    to type the words. Next, we will compare the user's input with the string array. The points increases by 1 
    for each correct word that is correct and decreases by 1 for each incorrect word. If the user enters 'q', 
    the program will print out the results and stop. For every 4 points the user gets, the number of words 
    flashes onto the screen increase by 1. This will repeat until the user has reached 10 points or chooses 
    to stop.
*/


int main(){


    cls();
    const int totalWords = 49;
    string words[totalWords] = {"apple", "avocado", "apricot", "banana", "blackberry", "blueberry", 
        "cherry", "cranberry", "coconut", "cucumber", "currant", "date", "durian", 
        "dragonfruit", "elderberry", "fig", "grapefruit", "guava", "grape", "honeydew",
        "jackfruit", "kiwi", "kumquat", "lemon", "lime", "lychee", "longan", "mango", 
        "mangosteen", "mandarin", "nectarine", "orange", "olive", "pineapple", "papaya", 
        "plum", "peach", "pear", "persimmon", "prune", "pummelo", "pluot", "plantain",
        "raspberry", "strawberry", "tangerine", "tomato", "tamarind", "watermelon"};
    int size = 2;
    string wordDisplay[size];
    int points = 0;
    string userInput[size];


    // Game Introduction
    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "Hello welcome to my adaptive memory game. \n\n";
    cout << "You will have 1 second to memorize the words that flashes onto your screen.\n";
    cout << "Then you be prompted to enter the words... \n\n";
    cout << "For each word you've entered correctly, you'll gain 1 point. Otherwise you'll lose 1 point.\n";
    cout << "For every 4 points you have, the amount of words flashing onto your screen increases by 1. \n";
    cout << "The game will automatically closes when you've reached 10 points.\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "Start the game (Y/N)? ";


    // Start Game, 'y' or 'n'
    char userPlay;
    cin >> userPlay;
    if(userPlay == 'y' || userPlay == 'Y'){
        cls();
        for (int i=0; i<1; i++){
            this_thread::sleep_for(chrono::seconds(1));
        }
        do {
            // Display words using random number generator
            string wordDisplay[size];
            srand(time(0));
            cout << "***************************************************************************\n";
            cout << "\t\t Memorize the following\n";
            cout << "***************************************************************************\n";
            cout << "\n\n";
            for(int i=0; i<size; i++){
                wordDisplay[i] = words[rand() % 49];
                cout << wordDisplay[i] << " ";
            }
            cout << "\n\n\n";
            cout << "***************************************************************************\n";
            this_thread::sleep_for(chrono::seconds(1));
            cls();

            // User types in the words or 'q' to quit
            cout << "Please input words (type q to quit): ";
            for(int i=0; i<size; i++){
                cin >> userInput[i];
                if(userInput[0] == "q"){
                    cout << "--------------------------------------\n\n";
                    cout << "Thanks for playing.....\n";
                    cout << "Your final score is.... " << points << endl;
                    cout << "Bye...\n\n\n";
                    cout << "--------------------------------------\n\n";
                    exit(0);
                }
            }

            // Checking user's input with the randomly generated words
            cout << "Checking your input... \n";
            this_thread::sleep_for(chrono::seconds(1));
            for(int i=0; i<size; i++){
                if(userInput[i] == wordDisplay[i]){
                    points++;
                } else{
                    points--;
                }
            }

            // Quit game if points >= 10, continues if points < 10
            if(points >= 10){
                cout << "----------------------------------------\n\n";
                cout << "Excellent! You Win!\n\n";
                cout << "Thanks for playing...\n";
                cout << "Your final score is: " << points << endl;
                cout << "Bye...\n\n\n";
                cout << "----------------------------------------";
                exit(0);
            } else {
                cout << "Your current score: " << points << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Here comes the next... \n";
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Ready... \n";
                this_thread::sleep_for(chrono::seconds(1));
                cls();
            }

            /* TODO: Something that can be improved is decreasing the size when you lose points or fall under 
            4 points or 8 points. For example, if I got 5 points and lost 3 points, I would have 2 points but 
            it would still display 3 words. For future improvements, I want to want to manually set the
            conditions of when the point is between 0-4, size = 2 or if point is between 4-8, size = 3.
            */
            if(points == 0){
                size = 2;
            }
            if(points % 4 == 0){
                size++;
            }

        } while(points != 10);

    } else{
        exit(0);
    }
    
    return 0;
}
