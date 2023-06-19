#include<iostream>

using std::cout;

int x = 42; // Global variable, out of main loop

int main(){
    int x = 2; // Local variable, inside main loop
    cout << "Global x = " << ::x << "\n"; // :: means Global variable of 'x'
    cout << "Local x = " << x << "\n"; // regular x means Local variable

    // Increment/Decrement using ++/--
    int y = 22;
    cout << "++y value = " << ++y << "\n";
    return 0;
}
