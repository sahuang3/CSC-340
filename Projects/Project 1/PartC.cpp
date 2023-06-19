// This file is part of CSC 340 - Assignment 1

/* Summary:
    This program will take the user's input of 10 numbers and put it into an array. Then, it compares the length of each
    increasing subsequence and prints out the longest increasing subsequence within the given array.
*/

#include <iostream>

using namespace std;

/* Program Design:
    We want to take the user's input of 10 numbers. Then, we compare the left index with the right index and make sure that the
    left is smaller than the right because it's an increasing subsequence. If left < right, then we add the element to the
    temporary array and +1 count. If left > right, then we add the last element to the temporary array and +1 count. Then,
    we compare: max length of LIS < count, if that's true then copy the temporary array into the LIS array and change the
    max length to the count. Lastly, the count gets reset and there's a for loop to printout the LIS.
*/

void ArrayLIS(int arr[], int size) {

    // Initializing variables
    int lis[size]; // The main LIS array
    int lis2[size]; // The temporary LIS array (placeholder)
    int count = 0;  // Keeps track of the length of increasing sequence
    int max_length = 0; // Maximum length of increasing sequence
    
    //TODO: Maybe this could be improved using another method (instead of replacing a temporary array or not using 2 arrays)
    // Using for loop to check left and right index
    for(int i=0; i < size; i++){
        // If left is less than right
        if(arr[i] < arr[i+1]){ 
            lis2[i] = arr[i]; // We add the element to lis2 array and +1 count
            count++;
        } 
        // If left is bigger than right
        if(arr[i] > arr[i+1]){
            lis2[i] = arr[i]; // We copy down the last number before we reset the array and +1 count
            count++;
            // If lis2 is longer than lis, replaces lis with lis2 and sets max_length to the highest count
            if(max_length < count){
                for(int j=0; j < count; j++){
                lis[j] = lis2[j];
                max_length = count;
                }
            }
            count = 0; // Reset count after lis2 is copied to lis
        }
    }
    // Prints the Longest Increasing Sequence
    for(int i=0; i < max_length; i++){
        cout << lis[i] << " ";
    }
}

int main(){

    // First we need to take the user's input and put it into an array, initialize array with length 10
    const int array_size = 10;
    int userInput[array_size];
    cout << "Input 10 numbers in the array: \n";

    // Storing the user's input in array
    for(int i=0; i<array_size; i++){
        cin >> userInput[i];
    }

    // Printing out the output after LIS function
    cout << "Output: \n";
    ArrayLIS(userInput, array_size);
    return 0;
}
