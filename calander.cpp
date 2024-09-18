#include "calander.hpp"
#include "days.hpp"
#include "events.hpp"
#include <iostream>
#include <vector>
using namespace std;

calander::calander(int day)
{
    this->monthSize=day;
    dayArray= new days*[monthSize]; //Creating pointer array that contain pointers to DAYS objects
    string arr[7]={"Mon","Tue","Wed", "Thur", "Fri", "Sat", "Sun"};
    for(int i=0 ; i<monthSize ; i++){
        string dayName=arr[i%7];
        dayArray[i]=new days(dayName , (i+1));
    }
}

calander::~calander()
{
    for(int i=0 ; i<monthSize ; i++){
        delete dayArray[i];
        dayArray=NULL;
    }
}

void calander::bookByChoice(string eventName, int startHour, int startMinute, int endHour, int endMinute, int date, int month, int year, int choice){
    vector<int> position; //get day position
    if(!(dayArray[date-1]->checkEventforBooking(startHour, startMinute, endHour,endMinute))){
        //Slot Available
        switch(choice){
            case 1:{
                if(dayArray[date-1]->getDayName()=="Sat" || dayArray[date-1]->getDayName()=="Sun" ){
                    int weekEndChoice=0;
                    cout<<"Do you want to schedule a meeting in the weekend ? (YES-1 / NO - 0) : ";
                    cin>>weekEndChoice;
                    if(weekEndChoice==1){
                        //single event for weekend
                        if(eventName == "DAY OFF"){
                            dayArray[date-1]->bookEvent(eventName, startHour, startMinute, endHour, endMinute, date, month, year);
                            cout<<"\n---------DAY OFF on Weekend Added Successfully---------\n"<<endl;
                        }else{
                            dayArray[date-1]->bookEvent(eventName, startHour, startMinute, endHour, endMinute, date, month, year);
                            cout<<"\n---------Weekend Event Booked Successfully---------\n"<<endl;
                        }
                        //return;
                    }
                }else{
                    //Book for a normal date
                    if(eventName == "DAY OFF"){
                        dayArray[date-1]->bookEvent(eventName, startHour, startMinute, endHour, endMinute, date, month, year);
                        cout<<"\n---------DAY OFF  Added Successfully---------\n"<<endl;
                    }else{
                        dayArray[date-1]->bookEvent(eventName, startHour, startMinute, endHour, endMinute, date, month, year);
                        cout<<"\n---------Event Booked Successfully---------\n"<<endl;
                    }
                    //return;
                }
                break;
            }
            case 2:{
                //Book daily events
                for(int i=(date-1) ; i<monthSize ; i++){
                    bool bookStatus = dayArray[i]->checkEventforBooking(startHour, startMinute, endHour, endMinute);
                    if(!bookStatus){
                        position.push_back(i); //methanin event eka thiyena dawasa vector ekata add kara
                    }
                }
                int numofDays=monthSize - (date-1);
                if(numofDays == position.size()){
                    for(int i=(date-1) ; i<monthSize ; i++){
                        dayArray[i]->bookEvent(eventName, startHour, startMinute, endHour, endMinute, date, month, year);
                    }
                    cout<<"\n---------Daily Events Booked Successfully---------\n"<<endl;
                }else{
                    cout<<"\n---------Cannot Book!! All or One of The Slots Already Reserved---------\n"<<endl;
                }
                break;
            }
            case 3:{
                //Weekly events
                for(int i=(date-1) ; i<monthSize ; i+=7){
                    bool bookStatus = dayArray[i]->checkEventforBooking(startHour, startMinute, endHour, endMinute);
                    if(!bookStatus){
                        position.push_back(i); //methanin event eka thiyena dawasa vector ekata add kara
                    }
                }
                int freeDays=0;
                cout<<"positionsize "<<position.size()<<endl;
                for(int i=date; i<=monthSize ; i+=7){
                    freeDays++;
                }
                cout<<"freedays "<<freeDays<<endl;
                if(freeDays == position.size()){
                    for(int i=(date-1) ; i<monthSize ; i+=7){
                        dayArray[i]->bookEvent(eventName, startHour, startMinute, endHour, endMinute, date, month, year);
                    }
                    cout<<"\n---------Weekly Events Booked Successfully---------\n"<<endl;
                }else{
                    cout<<"\n---------Cannot Book!! Slot is Already Reserved---------\n"<<endl;
                }
                break;
            }
        }
        return;
    }else{
        if(dayArray[date-1]->getEventName(date) == "DAY OFF"){
            cout<<"\n---------Cannot Book Meetings on DAY OFFS---------\n"<<endl;
        }else{
            cout<<"\n---------Cannot Book!! Slot is Already Reserved---------\n"<<endl;
        }
        return;
    }
}

void calander::deleteByChoice(string eventName, int startHour, int startMinute, int endHour, int endMinute, int date, int month, int year){
    //check the number of event occurances 
    int start= startHour*2 + startMinute/30;
    int end= endHour*2 + endMinute/30;
    int slots=end-start; 
    vector<int> position; 

    if(dayArray[date-1]->checkEvent(eventName,startHour, startMinute, endHour, endMinute)){
        for(int i=0 ; i<monthSize ; i++){
            bool bookStatus = dayArray[i]->checkEvent(eventName,startHour, startMinute, endHour, endMinute);
            if(bookStatus){
                position.push_back(i);
            }
        }
        //Delete Single event
        if(position.size()==1){

            dayArray[position[0]]->deleteEvent(eventName,startHour,startMinute,endHour,endMinute,date,month,year);
            cout<<"\n---------Event Deleted Successfully---------\n"<<endl;

             return;
        }else if(position.size() > 1){
            int deleteChoice=0;
            cout<<"\n--------Repeated Occurances FOUND--------\n"<<endl;
            cout<<"\nDo you want to delete the repeated occurances of the same meeting ? (YES - 1 / NO - 0) : ";
            cin>>deleteChoice;
            if(deleteChoice == 1 ){
                for(int i=0 ; i<position.size() ; i++){
                    dayArray[position[i]]->deleteEvent(eventName,startHour,startMinute,endHour,endMinute,date,month,year);
                }

                cout<<"\n---------Repeated Events Deleted Successfully---------\n"<<endl;

                return;

            }else if(deleteChoice == 0){
                int index=0;
                for(int i=0 ; i<position.size() ; i++){
                    if(position[i]==(date-1)){
                        index=i;
                    }
                }
                dayArray[position[index]]->deleteEvent(eventName,startHour,startMinute,endHour,endMinute,date,month,year);

                cout<<"\n---------Selected Event of Repeated Events Deleted Successfully---------\n"<<endl;

                return;
            }else{
                cout<<"\n-----Wrong input for choice-----\n"<<endl;
                return;
            }
        }
    }else{
        cout<<"-----Cannot Delete ! No Such Event Has Been Added!-----\n"<<endl;
        return;
    }
}

void calander::displayByDay(int day){
    dayArray[day]->viewAllEvents(day+1);
}

void calander::displayByWeek(int weekNumber){
    switch(weekNumber){
        case 1:{
            for(int i=0 ; i<7 ; i++){
                dayArray[i]->viewWeek();
            }
            break;
        }
        case 2:{
            for(int i=7 ; i<14 ; i++){
                dayArray[i]->viewWeek();
            }
            break;
        }
        case 3:{
            for(int i=14 ; i<21 ; i++){
                dayArray[i]->viewWeek();
            }
            break;
        }
        case 4:{
            for(int i=21 ; i<28 ; i++){
                dayArray[i]->viewWeek();
            }
            break;
        }
        case 5:{
            for(int i=28 ; i<31 ; i++){
                dayArray[i]->viewWeek();
            }
            break;
        }
    }
}

void calander::displayByMonth(){
    vector<bool> checker;
    int ctrue=0 , cfalse=0;
    for(int i=0 ; i<31 ; i++){
        bool b = dayArray[i]->viewMonth();
        checker.push_back(b);
    }
    for(bool b : checker){
        if(b==true){
            ctrue++;
        }     
        if(b==false){
            cfalse++;
        }
            
    }
    if((ctrue > 0 && cfalse == 0) || (ctrue > 0 && cfalse > 0)){
        cout<<"----------Returning To Main Menu----------\n"<<endl;
    }else if(cfalse>0 && ctrue==0){
       cout<<"\n-------No events Scheduled !-------\n"<<endl;
    }
}

