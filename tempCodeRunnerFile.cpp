e)){
        for(int i=0 ; i<monthSize ; i++){
            bool bookStatus = dayArray[i]->checkEvent(eventName,startHour, startMinute, endHour, endMinute);
            if(bookStatus){
                position.push_back(i); //methanin event eka thiyena dawasa vector ekata add kara
            }
        }
        //Delete Single event
        if(position.size()==1){

            dayArray[position[0]]->deleteEvent(eventName,startHour,startMinute,endHour,endMinute,date,month,year);
            cout<<"\n---------Event Deleted Successfully---------"<<endl;

             return;
        }else if(position.size() > 1){
            int deleteChoice=0;
            cout<<"\n--------Repeated Occurances FOUND--------"<<endl;
            cout<<"\nDo you want to delete the repeated occurances of the same meeting ? (YES - 1 / NO - 0) : ";
            cin>>deleteChoice;
            if(deleteChoice == 1 ){
                for(int i=0 ; i<position.size() ; i++){
                    dayArray[position[i]]->deleteEvent(eventName,startHour,startMinute,endHour,endMinute,date,month,year);
                }

                cout<<"\n---------Event Deleted Successfully---------"<<endl;
