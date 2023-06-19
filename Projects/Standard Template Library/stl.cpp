#include <iostream>
#include <array>
/* Array Library
    Access using subscript operator, arr[3], index starts with 0 with no bounds checking
    Access using "at" member function, arr.at(3), with bounds checking
    Length of array, arr.size()
    Front and Back of array, arr.front() == arr[0]; and arr.back() == arr[arr.size()-1];
*/
#include <typeinfo> // To display which datatype your variable uses
#include <vector>
/* Vector Library - Similar to an Array but fast and flexible
    Initialize, vector<string> vec;
    Remove all elements, vec.clear()
    Push/Back, vec.push_back(item) and vec.emplace_back(item)
    Reserve enough memory to store n items, vec.reserve(n)
*/
#include <string>
/* String Library - Mainly to add or compare strings
    Concatenate with strings (+)
    Comparing strings (==, <, >, or str.compare())
    Check if string is empty, str.empty()
*/
#include <map>
/*  Map Library (Also includes multimap, where same key can have different values)
    Stores key and value pair, (pairs[key] to locate a value in the map)
    Duplicate keys are not allowed (unless using multimap)
    Insert value to key, Ex: pairs.insert(make_pair(15, 2.7))
*/

using namespace std;

int add(int x, int y){
    return x + y;
}

int main(){
    // For Typeinfo Library
    // Auto will leave the compiler to decide which datatype to use
    auto d = 5.0;
    auto sum = add(5,6);

    cout << "sum = " << sum << endl;
    cout << "sum type: " << typeid(sum).name() << endl; // Display datatype for "sum" variable (int)
    cout << "d type: " << typeid(d).name() << endl; // Display datatype for "d" variable (double)
    
    // For Vector Libary
    vector<string> vec;
    //vec.reserve(32); If you want to reserve for 32 items, capacity = 32

    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    cout << "======================\n";

    vec.push_back("string 1");
    vec.push_back("string 2");
    vec.push_back("string 3");
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    cout << "======================\n";

    /* To print out all items in vec
    for(auto item : vec){
        cout << item << endl;
    }
    */
    vec.push_back("string 4");
    vec.push_back("string 5");

    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;

    return 0;
}