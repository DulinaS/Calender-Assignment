#ifndef DAYS_H
#define DAYS_H
#include <iostream>
#include <string>
#include "events.hpp"
using namespace std;

class days{
private:
    string dayName;
    int dayDate;
    events** eventArray;
    int slotSize;
//protected:
    
public:
    //Constructor
    days(string name, int d);

    //Deconstructor
    ~days();

    //get the letters of day
    string getDayName();

    //get the day in number
    int getDate();

    //get the event name
    string getEventName(int date);

    //Book event
    void bookEvent(string eventName, int startHour, int startMinute, int endHour, int endMinute, int date, int month, int year);

    //Check event for deleting
    bool checkEvent(string eventName, int startHour, int startMinute, int endHour, int endMinute);

    //check event for booking
    bool checkEventforBooking(int startHour, int startMinute, int endHour, int endMinute);

    //Delete event
    void deleteEvent(string eventName, int startHour, int startMinute, int endHour, int endMinute, int date, int month, int year);

    // View by day , month , year
    void viewAllEvents(int date);
    void viewWeek();
    bool viewMonth();
    
};
#endif