#include <iostream>

using namespace std;

int main(){
    // char message[] = "Welcome!";
    // When using undefined length of array, need null at the end otherwise you get a random character
    char message[] = {'w', 'e', 'l', 'c', 'o', 'm', 'e', '!', '\0'}; // last index = null

    cout << message << endl;

    // Changing index 0 
    message[0] = 'W';

    cout << message << endl;

    // Output the size of the array
    cout << sizeof(message) / sizeof(char) << endl;

    // Initialize + Assigning int arrays
    int nums[5] = {5, 4, 3, 2, 1};

    double temps[10];
    temps[1] = 83.2;

    // Initializing Multidimensional Arrays
    char page[30][100];
    int matrix[2][3];
    double threeOfPicture[10][20][30];

    return 0;
}