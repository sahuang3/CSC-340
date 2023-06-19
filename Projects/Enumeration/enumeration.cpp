#include <iostream>

using namespace std;

int main(){
    // Enumeration, first index always starts at 0 unless assigned a value
    enum Color {red, green = 10, blue}; // Red=0, Green=10, Blue=11
    cout << red << endl;
    cout << green << endl;
    cout << blue << endl;

    Color r = red;
    
    switch(r){
        case red : cout << "red\n";     break;
        case green : cout << "green\n"; break;
        case blue : cout << "blue\n";   break;
    }

    return 0;
}