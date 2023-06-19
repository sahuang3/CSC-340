#include <iostream>

using namespace std;

void fillUp(int arr[], int size);

int main(){
    int score[5]; // Initialize Score array with size '5'
    fillUp(score, 5); // Running fillUp function using Score array and size 5

    // After fillUp function, this displays array index 0-4
    for(int i=0; i<5; i++)
    cout << score[i] << " "; 
    cout << endl;
    return 0;
}

// Takes the user input of 5 numbers and filling them up in Array index 0-4
void fillUp(int arr[5], int size){
    for (int i=0; i<size; i++)
    cin >> arr[i];
}
