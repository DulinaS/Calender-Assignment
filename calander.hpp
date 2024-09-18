#ifndef CALANDER_H
#define CALANDER_H
#include "events.hpp"
#include "days.hpp"
#include <string>
using namespace std;

class calander{
private:
   int monthSize; // 31 days for july;
    days** dayArray;
public:
    //Constructor and Deconstructor
    calander(int days);
    ~calander();

    //void validateDate(int date, int month, int year);

    //Bookby choice
    void bookByChoice(string eventName, int startHour, int startMinute, int endHour, int endMinute, int date, int month, int year, int choice);

    //Delete by choice
    void deleteByChoice(string eventName, int startHour, int startMinute, int endHour, int endMinute, int date, int month, int year);

    //View Day
    void displayByDay(int day);
    
    //View Week
    void displayByWeek(int weekNumber);

    //View Month
    void displayByMonth();
   
};
#endif