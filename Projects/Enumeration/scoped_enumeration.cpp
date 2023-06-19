#include <iostream>

using namespace std;

int main(){
    // Scoped Enumeration, first index always starts at 0 unless assigned a value
    enum class Color {red, green = 20, blue}; // Red=0, Green=20, Blue=21
    cout << static_cast<int>(Color::red) << endl;
    cout << static_cast<int>(Color::green) << endl;
    cout << static_cast<int>(Color::blue) << endl;

    Color r = Color::blue;
    //int r = 21
    
    switch(r){
        case Color::red : cout << "red\n";     break;
        case Color::green : cout << "green\n"; break;
        case Color::blue : cout << "blue\n";   break;
    }

    return 0;
}