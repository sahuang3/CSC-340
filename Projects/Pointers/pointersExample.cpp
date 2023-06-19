#include<iostream>

using namespace std;

int cube1(int num){
    return num * num * num;
}

void cube2(int& num){
    num = num * num * num;
}

void cube3(int* num){
    cout << "address of num: " << &num << endl;
    cout << "address of variable that num ptr pointing at: " << num << endl;
    *num = *num * *num * *num;
}

int main(){

    int x = 2;
    cout << "cube1 = " << cube1(x) << endl;

    cube2(x);
    cout << "cube2 = " << x << endl;

    x = 2;
    cout << "address of x: " << &x << endl;
    int* ptr = &x;
    cout << "adddress of ptr: " << &ptr << endl;
    cube3(ptr);
    cout << "cube3 = " << x << endl;

    return 0;
}