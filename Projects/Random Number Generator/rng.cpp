#include <iostream>
#include <cstdlib> // Need this library for RNG

using namespace std;

// keyword "rand" to pseudorandom numbers
// keyword "srand" to generate actual random numbers
int main(){

    srand(time(0)); // To guarantee a random number, otherwise it will keep using the prev generated values

    // Want to get 10 random numbers
    for(int i=0; i<10; i++){
        cout << rand() % 40 << ", "; // Generate 10 random number from 0-39
    }
    cout << endl;

    return 0;
}