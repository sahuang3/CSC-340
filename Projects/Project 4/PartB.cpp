// Copyright 2022, Samson Huang, All rights reserved.

#include <iostream>

using namespace std;

int main(){

    int userMoney = 0;
    int sum = 0;
    int count = 0;
    int size;

    cout << "Enter the dollar amount Mark can spend: ";
    cin >> userMoney;

    cout << "Enter the number of items: ";
    cin >> size;

    int toyPrice[size];
    cout << "Enter the toy prices: ";
    for(int i=0; i<size; i++){
        cin >> toyPrice[i];
    }

    // Sorting the array from lowest to highest price
    int left = 0;
    int temp = 0;
    for(int i=1; i < size; i++){
        temp = toyPrice[i];
        left = i-1;
        while(left >= 0 && toyPrice[left] > temp){
            toyPrice[left+1] = toyPrice[left];
            left = left - 1;
        }
        toyPrice[left + 1] = temp;
    }

    // Finding the sum and the max number of items
    while(toyPrice[count] < userMoney){
        sum = sum + toyPrice[count];
        count++;
        if(sum > userMoney){
            break;
        }
    }
    cout << "Maximum number of items Mark can buy: " << count;
    
    
    return 0;
}
