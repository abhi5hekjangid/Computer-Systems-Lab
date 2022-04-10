#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
using namespace std;

//to find count in O(1)
int wickets[1000]={-1};
int totalruns[30000]={-1};
int totalcatches[1000]={-1};

//player is the class containing serveral properties
class Player{
   public: 
    string Name;
    int playerId;
    int birthYear;
    int runs;
    int wick;
    int catches;
    int matchesPlayed;
   public:
    Player(){
        Name="";
        matchesPlayed=playerId=birthYear=runs=wick=catches=0;
    }
};

Player* players[10000];

//find if player already exists
bool exists (string name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

//function for inserting data
void insertData(){
    ofstream file;
    cout<<"Enter Player ID of Player ";
    int id;
    cin>>id;

    string strID=to_string(id);
    while(strID.length()>4 || id<1001){
        if(id<1001){
            cout<<"ID should be between 1001 and 9999."<<endl;
        }
        else
            cout<<"Invalid ID please enter again\n";
        cout<<"Enter Player ID of Player ";
        cin>>id;
        strID=to_string(id);
    }

    while(exists(strID)){
        cout<<"Player already registered\n";
        cout<<"Enter ID again"<<endl;
        cin>>id;
        strID=to_string(id);
    }

    players[id]=new Player();
    players[id]->playerId=id;

    
    file.open(strID, ios::app | ios::out);

    file<<id<<endl;

    string first="",last;
    cout<<"Enter Name of Player ";
    
    while (true)
    {
      cin>>last;
      first+=last;
      if(cin.peek()==' ')
      first+=' ';
      if(cin.peek()=='\n')
      break;
    }
    players[id]->Name=first;
    file<<players[id]->Name<<endl;

    cout<<"Enter Birth Year of Player ";
    cin>>players[id]->birthYear;

    while(players[id]->birthYear<1950 || players[id]->birthYear>2022){
        cout<<"Invalid Birth Year\n";
        cout<<"Enter Birth Year of Player ";
        cin>>players[id]->birthYear;
    }
    file<<players[id]->birthYear<<endl;

    cout<<"Enter matches played by Player ";
    cin>>players[id]->matchesPlayed;
    file<<players[id]->matchesPlayed<<endl;

    cout<<"Enter Runs scored by Player ";
    cin>>players[id]->runs;
    file<<players[id]->runs<<endl;
    if(totalruns[players[id]->runs]==-1)
        totalruns[players[id]->runs]=0;
    totalruns[players[id]->runs]++;

    cout<<"Enter wickets taken by player ";
    cin>>players[id]->wick;
    file<<players[id]->wick<<endl;
    if(wickets[players[id]->wick]==-1)
        wickets[players[id]->wick]=0;
    wickets[players[id]->wick]++;
    
    cout<<"Enter catches taken by player ";
    cin>>players[id]->catches;
    file<<players[id]->catches<<endl;
    if(totalcatches[players[id]->catches]==-1)
        totalcatches[players[id]->catches]=0;
    totalcatches[players[id]->catches]++;
    
    cout<<"Player added successfully\n";
}

//function for deleting players data
void deletePlayer(){
    int id;
    cout<<"Enter PlayerId ";
    cin>>id;
    string strID=to_string(id);
    if(exists(strID)){
        players[id]->playerId=0;
        players[id]->Name="";
        players[id]->birthYear=0;
        players[id]->matchesPlayed=0;
        totalruns[players[id]->runs]--;
        players[id]->runs=0;

        wickets[players[id]->wick]--;
        players[id]->wick=0;

        totalcatches[players[id]->catches]--;
        players[id]->catches=0;
        delete players[id];
        remove(strID.c_str());
    }
    else{
        cout<<"File doesn't exists";
    }
    cout<<"Data deleted successfully\n";
}
//updating files of respective player
void updateFile(int id){
    
    ofstream file;
    string strID=to_string(id);
    if(exists(strID)){
        remove(strID.c_str());
    }
    else{
        cout<<"File doesn't exists";
    }
    
    file.open(strID, ios::app | ios::out);

    file<<id<<endl;
    file<<players[id]->Name<<endl;
    file<<players[id]->birthYear<<endl;
    file<<players[id]->matchesPlayed<<endl;
    file<<players[id]->runs<<endl;
    file<<players[id]->wick<<endl;
    file<<players[id]->catches<<endl;
    cout<<"Chnages updated successfully.\n";
}
//function for printing players data
void printPlayerData(int id){

    cout<<"ID of player is "<<players[id]->playerId<<endl
    <<"Name of player is "<<players[id]->Name<<endl
    <<"Birth year of player is "<<players[id]->birthYear<<endl
    <<"Matches played by player are "<<players[id]->matchesPlayed<<endl
    <<"runs score by player are "<<players[id]->runs<<endl
    <<"wickets taken by player are "<<players[id]->wick<<endl
    <<"catches taken score by player are "<<players[id]->catches<<endl;

}

void updatePlayer(int id){
    
    int choice;
    if(!players[id]){
        cout<<"Player doesn't exists."<<endl;
        return;
    }
    do 
    { 
    cout<<"\nSelect a choice \n"
        <<"1. Change Name\n"
        <<"2. Change Birth Year\n"
        <<"3. Change matches played\n"
        <<"4. Change runs\n"
        <<"5. Change wickets taken\n"
        <<"6. Change catches taken\n"
        <<"7. Exit ";
    cin >> choice; //select menu by number 1,2,0r 3 
    
    switch(choice) 
    { 
        case 1: 
        //Do something
        cout<<"Enter new Name ";        
        cin>>players[id]->Name;
        break; 
        
        case 2: 
        cout<<"Enter new birth year ";
        cin>>players[id]->birthYear;
        
        while(players[id]->birthYear<1950 || players[id]->birthYear>2022){
            cout<<"Invalid Birth Year\n";
            cout<<"Enter Birth Year of Player ";
            cin>>players[id]->birthYear;
        }
        
        //Do something
        break; 
        
        
        case 3: 
        //Do something 
        cout<<"Change matches played ";
        cin>>players[id]->matchesPlayed;
        
        break; 
        
        case 4: 
        //Do something 
        cout<<"Change runs ";
        totalruns[players[id]->runs]--;
        cin>>players[id]->runs;
        

        
        break; 
        
        case 5: 
        //Do something 
        cout<<"Change wickets taken ";
        wickets[players[id]->wick]--;
        cin>>players[id]->wick;
        
        break; 
        
        case 6: 
        
        cout<<"Change catches taken ";
        totalcatches[players[id]->catches]--;
        cin>>players[id]->catches;
        //Do something 
        break;

        case 7: 
        updateFile(id); 
        printPlayerData(id);
        return;
      }
    }while(choice != 7); 

    
}    

int convert(string str){
    int num=0;
    //cout<<"string is "<<str<<endl;
    int l=str.length();
    for(int i=0;i<l;i++){
        num=pow(10,l-i-1)*(str[i]-'0')+num;
        
    }
    return num;

}
//function for loading already existing data files of players
void loadData(){
    for(int i=0;i<10000;i++){
        if(exists(to_string(i))){
            ifstream indata;
            indata.open(to_string(i));
            string tp;
            int count=1;
            
            players[i]=new Player();

            while(getline(indata,tp)){
                
                if(count==8) break;
                
                if(count==1)
                    players[i]->playerId=convert(tp);
                if(count==2)
                    players[i]->Name=tp;
                
                if(count==3)
                    players[i]->birthYear=convert(tp);                
                if(count==4)
                    players[i]->matchesPlayed=convert(tp);
                if(count==5){
                    players[i]->runs=convert(tp);
                    if(totalruns[players[i]->runs]==-1)
                        totalruns[players[i]->runs]=0;
                    totalruns[players[i]->runs]++;
                }
                if(count==6){
                    players[i]->wick=convert(tp);
                    if(wickets[players[i]->wick]==-1)
                        wickets[players[i]->wick]=0;
                    wickets[players[i]->wick]++;    
                }
                
                if(count==7){
                    players[i]->catches=convert(tp);
                    if(totalcatches[players[i]->catches]==-1)
                        totalcatches[players[i]->catches]=0;
                    totalcatches[players[i]->catches]++;
                }
                count++;
            }
        }
    }
}

void findCount(){
    int choice;
    X:
    cout<<"Enter a choice \n"
        <<"1. Runs Scored\n"
        <<"2. Wickets Taken\n"
        <<"3. Catches Taken\n";
    cin>>choice;
    int value;
    cout<<"Enter value ";
    cin>>value;

    if(choice==1){
         
        int total=0;
        int real=value;
        while (value<30000)
        {   if(totalruns[value]!=-1)
                total+=totalruns[value];
            value++;
        }
        
        cout<<"No of players with runs more than "<<real<<" are "<<total<<endl;
    }
    else if(choice==2){
        
        int total=0;
        int real=value;
        while (value<1000)
        {   
            if(wickets[value]!=-1)
                total+=wickets[value];
            value++;
        }
        cout<<"No of players with wickets more than "<<real<<" are "<<total<<endl;
     
    }
    else if(choice==3){
        
        int total=0;
        int real=value;
        while (value<1000)
        {   if(totalcatches[value]!=-1)
                total+=totalcatches[value];
            value++;
        }
        cout<<"No of players with catches more than "<<real<<" are "<<total<<endl;
    }
    else{
        cout<<"Please enter correct choice ";
        goto X;
    }
}

//function for searching players using their name
void searchName(){
    cout<<"Enter name of a player to search"<<endl;
    string name;
    cin>>name;

    for(int i=0;i<10000;i++){
        if(players[i]){
            if(players[i]->Name==name){
                
                printPlayerData(i);
                return;
            }
        }
    }
    cout<<"Player not found.\nPlease enter correct player name."<<endl;
}

//main function
int main(){
    loadData();
    int choice; 
    
    do 
    { 
    cout<<endl 
    <<"1. Add a player record\n" 
    <<"2. Delete a player record\n" 
    <<"3. Update a player record\n"
    <<"4. Search for information of player using playerID\n"
    <<"5. Search for information of player using name\n"
    <<"6. List of players having RunsScored/WicketsTaken/CatchesTaken more than equal a given value\n" 
    <<"7. Exit\n"; 
    cin >> choice; //select menu by number 1,2,0r 3 
    
    switch(choice) 
    { 
        case 1: 
        //Do something 
        insertData();
        break; 
       
        case 2: 
        //Do something
        deletePlayer();
        break; 
        
        case 3: 
        //Do something
        cout<<"Enter id of the player ";
        int id;
        cin>>id;
        updatePlayer(id); 
        break; 
        
        case 4: 
        //Do something     
        cout<<"Enter player id to search ";
        cin>>id;
        
        if(!players[id]){
            cout<<"Player doesn't exists."<<endl;
        
        }
        else
            printPlayerData(id);
        break; 
        
        case 5: 
        //Do something 
        searchName();
        break; 
        
        case 6: 
        //Do something 
        findCount();
        break;

        case 7:  
        exit(1); 
      }
    }while(choice != 7); 

    return 0;
}