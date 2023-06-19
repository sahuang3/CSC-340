// Copyright 2022 - Samson Huang
// Email: shuang18@mail.sfsu.edu
// This file is part of CSC 340 - Assignment 2


/* Summary:
    This program will take the user's input of any numbers ranging from n < 10. Then it will display the rows 
    starting from 0 to the given number by user in the pascal triangle.
*/


#include <iostream>


using namespace std;


/* Program Design: 
    We want to take a number from the user with the condition n < 10. Then we create the Pascal triangle using a 
    2D-array and display the triangle from 0 to n rows. To calculate the elements in Pascal's tringle, I used a 
    factorial function using recursion for the combination formula (nCr) since there are no factorial operators 
    in C++.
*/


int fact(int n){
    if(n == 0){
        return 1;
    }
    return n * fact(n-1);
}


int main(){


    // Take the user's input of row # in pascal's triangle (must be less than 10)
    int userRows;
    cout << "Enter a number less than 10 to display rows of Pascal's Triangle: ";
    cin >> userRows;
    if(userRows >= 10){
        cout << "Invalid, number must be less than 10. Stopping program....";
        exit(0);
    }


    /* TODO: Maybe there is another equation to find the elements in each row because it could be much more 
    optimized since it won't involve using recursion and function. But I have only been taught to use the 
    nCr equation for Pascal's Triangle in my Discrete Math class and it has been something that I'm comfortable 
    using.
    */

    // 2-D array for Pascal's Triangle
    int value;
    for(int i=0; i<userRows; i++){
        for (int j=0; j<=i; j++){
            // The first index of each row always = 1
            if(i==0){
                value = 1;
            }
            value = fact(i)/(fact(i-j)*fact(j)); // nCr equation: n!/(n-r)!*r!
            cout << " " << value;
        }
        cout << endl;
    }
    
    return 0;
}