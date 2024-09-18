#include <iostream>
#include <sstream>
#include <vector>
#include "events.hpp"
#include "days.hpp"
#include "calander.hpp"
#include <iomanip>
#include <string>
using namespace std;
//Display
void displayCalander(){
    string arr[7]={"Mon","Tue","Wed", "Thur", "Fri", "Sat", "Sun"};
    cout<<"\n                 July 2024                  "<<endl;
    cout<<"+-----------------------------------------+"<<endl;
    //cout << '+' << endl;
    cout << "| "  << arr[0]
         << " | " << arr[1]
         << " | " << arr[2]
         << " |"  << arr[3]
         << " | " << arr[4]
         << " | " << arr[5]
         << " | " << arr[6]
         << " |"  << endl;
    cout<<"+-----------------------------------------+"<<endl;
    int count=0;
    while(count<=31){
        for(int j=1 ; j<=7 ; j++){
            count++;
            if(count==4){
                cout<<"|  "<<count<<"  |\b";
            }else if(count>=10){
                cout<<"| "<<count<<"  |\b";
            }else{
                cout<<"|  "<<count<<"  |\b";
            }
            if(count==31){
                cout<<"\n+-----+-----+-----+"<<endl;
                return;
            }
        }
        cout<<"\n+-----------------------------------------+"<<endl; 
    }
}
void displayFirstMenu(){
    cout<<"1. Add Event "<<endl;
    cout<<"2. Delete Event "<<endl;
    cout<<"3. View Day Schedule"<<endl;
    cout<<"4. View Weekly Schedule"<<endl;
    cout<<"5. View Monthly Schedule"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"\nEnter Your Choice : ";
}
void displayAddEventMenu(){
    cout<<"1. Add a Singular Event"<<endl;
    cout<<"2. Add a Daily Repeating Event"<<endl;
    cout<<"3. Add a Weekly Repeating Event"<<endl;
    cout<<"4. Add a Day Off"<<endl<<endl;
    cout<<"Enter Your Choice : ";
}

// Validations for time
bool timeValidation(int* startTime , int* endTime){
    bool b1=false , b2=false , b3=false;
    // Checking start Hour < end Hour
    if((startTime[0] < endTime[0]) && (0<=startTime[0] && startTime[0]<=24) && (0<=endTime[0] && endTime[0]<=24) ){
        b1=true;
    }
    //Checking for overnight
    if(!(endTime[0] == 24 && endTime[1]==30)){
        b2=true;
    }
    if((startTime[1]==0 || startTime[1]==30) && (endTime[1]==0 || endTime[1]==30)){
        b3=true;
    }
    if(b1 && b2 && b3){
        return true;
    }else{
        cout<<"\n------> Wrong Input -> Check the format and times are in order !!!!\n"<<endl;
        return false ;
    }     
}

//Validations for dates
bool dateValidation(int* date){
    bool b1=false , b2=false , b3=false;
    if(1<=date[0] && date[0]<=31){ b1=true; } 
    if(date[1] == 7){ b2=true; }
    if(date[2] == 2024){ b3=true ; }

    if(b1 && b2 && b3){
        return true;
    }else{
        cout<<"\n------> Wrong Input -> Check the format and date are in order !!!!\n"<<endl;
        return false ;
    } 
    

}

//display Validations for error
void displayValidations(){
    cout<<"------> Event dates should be in July Month of 2024 & There are only 31 days in July Month"<<endl;
    cout<<"------> Event starting hour should be before than event ending hour"<<endl;
    cout<<"------> Times are either XX00  or XX30"<<endl;
    cout<<"------> Times should in formate of XX:XX & date should be in format of XX/XX/XXXX"<<endl;
    cout<<"------> No overnight functions allowed"<<endl;
}

//Convert String to Integer
int* splitStringToInt(string str, char c){
    int size=str.size();
    stringstream ss(str);
    string token;
    vector<string> strVect;
    while (getline(ss, token, c)) { 
        strVect.push_back(token); 
    }
    //Integer vector to hold the converted strings
    int* arr = new int[strVect.size()];

    for(int i=0 ; i<strVect.size() ; i++){
        arr[i]=stoi(strVect[i]);
    }
    return arr;
}
int main(){
    int selection=0;
    int addEvent=0, editEvent=0, deleteEvent=0, viewDay=0, viewWeek=0, viewMonth=0;
    int addEventChoice=0, deleteEventChoice=0;
    string title = "" , sTime = "", eTime = "", date = "";

    //Creating a calander object with 31 days for month july
    calander july(31);

    displayCalander();
    cout<<"\nWelcome to the July Calander Mangement System!!"<<endl<<"Select Options : \n"<<endl;
    
    do{
        displayFirstMenu();
        cin>>selection;
        switch (selection){
            //book
            case 1:{
                displayAddEventMenu();
                cin>>addEventChoice;
                if(addEventChoice != 4){
                    cin.ignore();
                    cout<<"Enter the Event Title : ";
                    getline(cin,title);
                    cout<<"Enter the Start Time (Format > HH:MM in 24H) : ";
                    getline(cin,sTime);
                    int* ptr1  = splitStringToInt(sTime, ':');
                    cout<<"Enter the End Time (Format > HH:MM in 24H) : ";
                    getline(cin,eTime);
                    int* ptr2  = splitStringToInt(eTime, ':');
                    cout<<"Enter the Date (Format > DD/MM/YYYY) : ";
                    getline(cin,date);
                    int* ptr3  = splitStringToInt(date, '/');
                    //Validating the inputs
                    bool validation1 =timeValidation(ptr1 , ptr2);
                    bool validation2 =dateValidation(ptr3);
                    if( validation1 && validation2){
                        switch(addEventChoice){
                            case 1:{
                                july.bookByChoice(title , ptr1[0] , ptr1[1] , ptr2[0] , ptr2[1] , ptr3[0] , ptr3[1] , ptr3[2] , addEventChoice);
                                break;
                            }
                            case 2:{
                                july.bookByChoice(title , ptr1[0] , ptr1[1] , ptr2[0] , ptr2[1] , ptr3[0] , ptr3[1] , ptr3[2] , addEventChoice);
                                break;
                            }
                            case 3:{
                                july.bookByChoice(title , ptr1[0] , ptr1[1] , ptr2[0] , ptr2[1] , ptr3[0] , ptr3[1] , ptr3[2] , addEventChoice);
                                break;
                            }
                        }
                        delete[] ptr1;
                        delete[] ptr2;
                        delete[] ptr3;
                    }else{
                        delete[] ptr1;
                        delete[] ptr2;
                        delete[] ptr3;
                        displayValidations();
                        cout<<endl<<endl;
                        continue;
                    }
                }else{
                    cin.ignore();
                    cout<<"Enter the Date (Format > DD/MM/YYYY) : ";
                    getline(cin,date);
                    int* ptr=splitStringToInt(date, '/');
                    bool validation=dateValidation(ptr);
                    if(validation){
                        july.bookByChoice("DAY OFF" , 0 , 0 , 24 , 0 , ptr[0] , ptr[1] , ptr[2] , 1);
                        delete[] ptr;
                    }else{
                        delete[] ptr;
                        displayValidations();
                        cout<<endl<<endl;
                        continue;
                    }
                    
                }
                break;
            }
            //delete
            case 2:{
                cin.ignore();
                cout<<"\nEnter the Event Title : ";
                getline(cin,title);
                cout<<"Enter the Start Time (Format > HH:MM in 24H) : ";
                getline(cin,sTime);
                int* ptr1  = splitStringToInt(sTime, ':');
                cout<<"Enter the End Time (Format > HH:MM in 24H) : ";
                getline(cin,eTime);
                int* ptr2  = splitStringToInt(eTime, ':');
                cout<<"Enter the Date (Format > DD/MM/YYYY) : ";
                getline(cin,date);
                int* ptr3  = splitStringToInt(date, '/');

                //Validating the inputs
                bool validation1 =timeValidation(ptr1 , ptr2);
                bool validation2 =dateValidation(ptr3);

                if( validation1 && validation2){
                    july.deleteByChoice(title , ptr1[0] , ptr1[1] , ptr2[0] , ptr2[1] , ptr3[0] , ptr3[1] , ptr3[2] );
                    delete[] ptr1;
                    delete[] ptr2;
                    delete[] ptr3;
                }else{
                    delete[] ptr1;
                    delete[] ptr2;
                    delete[] ptr3;
                    displayValidations();
                    cout<<endl<<endl;
                    continue;
                }
                break;
            }
            case 3:{
                //View Day
                cin.ignore();
                cout<<"\nEnter the date you want to view ? (Format > DD/MM/YYYY) : ";
                getline(cin,date);
                int* ptr  = splitStringToInt(date, '/');
                bool validation=dateValidation(ptr);
                if(validation){
                    july.displayByDay(ptr[0]-1);
                    delete[] ptr;
                }else{
                    delete[] ptr;
                    displayValidations();
                    cout<<endl<<endl;
                    continue;
                }
                break;
            }
            case 4:{
                //View Week
                cin.ignore();
                cout<<"\nWhich week's schedule you want to view ? (1 - 1st Week / 2 -2nd Week / 3-3rd Week / 4 - 4th Week / 5 - 5th Week) : ";
                cin>>viewWeek;
                cout<<"\nSchedule For a Week:"<<endl;
                july.displayByWeek(viewWeek);
                cout<<endl;
                break;
            }
            case 5:{
                //View Month
                cin.ignore();
                cout<<"\nSchedule For Month July:"<<endl;
                july.displayByMonth();
                break;
            }   
        }

    }while((selection != 6));
    cout<<"Exiting the programmee!"<<endl;
    return 0;
}