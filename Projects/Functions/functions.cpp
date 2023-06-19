#include<iostream>

using namespace std;

// Functions are outside of main functions

int square(int); // Always need to initialize global scope variable before using functions

// Square by Value. Does not change the local variable num
int squareByValue(int num){
    int ret = num * num;
    num += 1;
    return ret;
}
// Square by Ref. Does change the reference variable num
int squareByRef(int& num){
    int ret = num * num;
    num += 1;
    return ret;
}

// MAIN FUNCTION
int main(){
    for(int i=0; i<4; i++){
        cout << "square of " << i << " is " << square(i) << "\n";
    }
    cout << endl;

    // For Square by value/ref
    int a = 3;
    int b = 4;

    cout << "my a = " << a << endl;
    cout << squareByValue(a) << endl;
    cout << "my a = " << a << endl; // Notice how num doesn't change after(bc num = local var in function)

    cout << "my b = " << b << endl;
    cout << squareByRef(b) << endl;
    cout << "my b = " << b << endl; // Notice how num changes after(bc num = ref variable in function)
    return 0;
}

// Basic Square function
int square(int num){
    return num * num;
}
