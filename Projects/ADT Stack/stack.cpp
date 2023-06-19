#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Balanced or Unbalanced braces check
bool check_braces(string str){
    stack<char> myStack;
    for(auto c : str){
        if(c == '{'){
            myStack.push(c);
        } else if(c == '}'){
            // To prevent popping an empty stack
            if(myStack.empty()){
                return false;
            }
            myStack.pop();
        }
    }
    return myStack.empty();
}

int main(){
    cout << check_braces("a{b{c}}") << endl;
    cout << check_braces("a{b{c}") << endl;
    cout << check_braces("ab{c}}") << endl; // Note can't pop bc only 1 open brace
    return 0;
}