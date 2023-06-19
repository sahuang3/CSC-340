#include<iostream>

using namespace std;

template <typename T>
T max(T, T, T);


int main(){
    cout << "Max: " << max(3, 2, 9) << endl;
    cout << "Max: " << max(3.8, 2.1, 1.9) << endl;
    cout << "Max: " << max('t', 'a', 'x') << endl;
    
    return 0;
}

template <typename T>
T max(T num1, T num2, T num3){
    T cur_max = num1;
    if(cur_max < num2)
        cur_max = num2;
    if (cur_max < num3)
        cur_max = num3;
    return cur_max;
}