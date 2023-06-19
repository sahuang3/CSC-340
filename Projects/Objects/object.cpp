#include<iostream>

using namespace std;

class Time{
    // Every class must have at least 1 constructor and EXACTLY 1 destructor
    // All methods/functions should be public
    /* Constructors have the same name as the class and are functions that
       have no return types, even void.
    */

    public:
    // Constructor w/o arguments
    Time(){
        cout << "calling constructor... \n";
    }
    // Constructor w/ arguments
    Time(int h, int m, int s){
        hour_ = h;
        min_ = m;
        sec_ = s;
    }
    // Or in C++ 11: Time(int h, int m, int s) : hour_{h}, min_{m}, sec_{s} {}
    // passes in h into hour_, m into min_, s into sec_

    // Destructor
    ~Time(){
        cout << "calling destructor... \n";
    }
    void setHour(int h) { hour_ = h; }
    void setMin(int m) { min_ = m; }
    void setSec(int s) { sec_ = s; }

    void printUniversalFormat() const { // 23:01:00
        //hour_ = 1;  Const keyword to prevent accidents such as changing the private data
        cout << hour_ << ":" << min_ << ":" << sec_ << endl;
    }
    //void printStandardFormat() const; // 12:00:02 AM

    // All data should be private
    private:
    // Setting 0's for default parameters
    int hour_ = 0;
    int min_ = 0;
    int sec_ = 0;
};

int main(){
    
    cout << "my main\n";
    // Calling destructor with the {} before and after the code block
    // Note: destructor gets called for each object is ran (mytime and mytime2)
    { 
        // Using the constructor w/ no arguments
        Time mytime;
        mytime.setHour(3);
        mytime.setMin(30);
        mytime.setSec(2);
        mytime.printUniversalFormat();
    } 

    // Using the constructor w/ arguments
    Time mytime2(12, 32, 9);
    mytime2.printUniversalFormat();
    //mytime.printStandardFormat();

    return 0;
}