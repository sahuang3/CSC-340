#include<iostream>

using namespace std;

// Struct is similar to Class, struct is always public
struct Date {
    int month;
    int day;
    int year;
};

// Print function
void printDate(const Date& date){
    cout << date.year << "/" << date.month << "/" << date.day;
}

int main(){

    Date date;
    date.month = 2;
    date.day = 22;
    date.year = 2022;
    
    printDate(date);
    cout << endl;

    Date date2 = {12, 1, 2021};
    printDate(date2);
    cout << endl;
}
