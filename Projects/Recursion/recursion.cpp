#include<iostream>

using namespace std;

// Without Recursion
int mult(int a, int b){
    // a*b = a + a + .... + a (b times)
    int result = 0;
    for(int i=0; i<b; i++){
        result += a;
    }
    return result;
}

// OR a*b = a + a*(b-1)
// With Recursion
int mult_recursive(int a, int b){
    // base case - if 1 is multiplied to "anything", return "anything"
    if(b == 1){
        return a;
    }
    // recursive
    return mult_recursive(a, b-1) + a;
}

// With Recursion
int fact(int n){
    // base case if factorial is 0 = 1
    if (n == 0){
        return 1;
    }
    // recursive
    return n * fact(n-1);
}

// Writing a String Backwards using Recursion
void write_backward(char str[], int last_index){
    // Base Case, last index
    if (last_index < 0){
        return;
    }
    // Recursive Step
    cout << str[last_index];
    write_backward(str, last_index - 1);
}

int main(){
    cout << "Without recursion: " << mult(3, 8) << endl;
    cout << "With recursion: " << mult_recursive(3, 8) << endl;
    cout << "Factorial with recursion: " << fact(3) << endl;
    
    char backwards[] = "hello";
    write_backward(backwards, 4);
    cout << endl;
    return 0;

}