#include<iostream>

using namespace std;

int main(){
    // A pointer is an address to another variable
    // Pointer Declartion: <dataType>*
    int y{5}; // Declare variable y = 5
    int* yPtr{nullptr}; // declare pointer variable yPtr
    yPtr = &y; // assign address of y to yPtr
    cout << *yPtr << endl; // outputs 5

    // Example
    int a = 42;
    int* ptr = nullptr;
    // const int* a_ptr = &a, cannot change value and can reassign pointer
    // int* const a_ptr = &a, can change value and cannot reassign pointer
    // const int* const a_ptr = &a, cannot change value or reassign, read-only

    int* a_ptr = &a;
    cout << a << endl; // output 42
    cout << *a_ptr << endl; // output 42
    cout << a_ptr << endl; // output the Address

    // Dereferencing pointer
    (*a_ptr) = 100;
    cout << a << endl;
    ptr = a_ptr;
    (*ptr) = 200;
    cout << a << endl;
    cout << *a_ptr << endl;

    // Built-in arrays and pointers
    int b[5];
    int* bPtr;
    bPtr = b;
    bPtr = &b[0];
    bPtr[1]; // refers to b[1]
    // Offset notation
    *(bPtr + 3);
    *(b + 3); // refers to b[3]

    // Pointers for classes, call object function from pointer using "->" keyword
    /*
    PlainBox<string> myBox("Favorite Toy");
    PlainBox<string>* myBox_ptr = &myBox;

    myBox_ptr->setItem("Spinning Top");
    */

   // "this" pointer: allows the object to return a reference to themselves, creates copies of themselves
    return *this;

    return 0;
}