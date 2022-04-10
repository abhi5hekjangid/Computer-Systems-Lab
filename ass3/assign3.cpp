//Abhishek Jangid
//2111CS01

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
using namespace std;

//convert function to convert string into number
int convert(string str){
    int num=0;
    //cout<<"string is "<<str<<endl;
    int l=str.length();
    for(int i=0;i<l;i++){
        num=pow(10,l-i-1)*(str[i]-'0')+num;
        
    }
    return num;
}

bool vis[20]={0};


//function to find process with min arrival time
int minProcess(int* arrTime,int timer,int n){
    
    int index=INT_MAX;
    for(int i=0;i<n;i++){
        if(!vis[i] && arrTime[i]<=timer){
            if(index==INT_MAX) index = i;
            else if(index!=INT_MAX && arrTime[index]>arrTime[i]){
                index=i;
            }
        }
    }
    return index;
}
//function to check if all processes(customer) are processed
bool isCompleted(int n){
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0) return false;
    }
    return true;
}
//function to assign customers to counters
void fcfs(int *times,int *custId,int *arrTime,int *req_type,int n){
    int wt[n];
    int ft[n];
    bool counter1=0,counter2=0;
    int ncounter1=0,ncounter2=0;
    int timer=0;
    
    
    //checking if any person is remaining(waiting)
    while(!isCompleted(n)){
        
        if(timer==ncounter1) counter1=0;
        if(timer==ncounter2) counter2=0;

        //if counter no 1 is free
        if(counter1==0){
             int index=minProcess(arrTime,timer,n);
             if(index!=INT_MAX){
                //cout<<"chosen customer is "<<custId[index]<<endl;
                //cout<<"req time is "<<times[req_type[index]]<<endl;
                //cout<<"timer is  "<<timer<<endl;
                vis[index]=1;
        
                counter1=1;
                ft[index]=timer+times[req_type[index]];
                wt[index]=ft[index]-arrTime[index];
                ncounter1=ft[index];

          //      cout<<"values of counters is "<<counter1<<" "<<counter2<<endl;
        //cout<<"next free "<<ncounter1<<" "<<ncounter2<<endl;
        
            }
            
        }
        //if counter no 2 is free
        if(counter2==0){
            //find min process to preceed
            int index=minProcess(arrTime,timer,n);
            if(index!=INT_MAX){
            //    cout<<"chosen customer is "<<custId[index]<<endl;
              //  cout<<"req time is "<<times[req_type[index]]<<endl;
                //cout<<"timer is  "<<timer<<endl;
                vis[index]=1;
            
                counter2=1;
                
                
                ft[index]=timer+times[req_type[index]];
                wt[index]=ft[index]-arrTime[index];
                ncounter2=ft[index];

              //  cout<<"values of counters is "<<counter1<<" "<<counter2<<endl;
            //cout<<"next free "<<ncounter1<<" "<<ncounter2<<endl;
        
            }
        }

        
        timer++;
    }
    float awt=0;
    //writing output in op.txt
    for(int i=0;i<n;i++){
        cout<<custId[i]<<","<<arrTime[i]<<","<<ft[i]<<","<<wt[i]<<endl;
        //outdata<<custId[i]<<","<<arrTime[i]<<","<<ft[i]<<","<<wt[i]<<endl;
        awt+=wt[i];
    }

    cout<<"Average waiting time is "<<float(awt/n);
    //outdata<<"Average waiting time is "<<float(awt/n);
}
//function to read data from ip.txt file
void readData(){
    ifstream indata;
    indata.open("ip.txt");

    if(!indata){
        //outdata<<"No file available"<<endl;
        cout<<"No file available"<<endl;
        exit(1);
    }
    int count_line=0;
    string tp;
    int custId[20];
    int arrTime[20];
    int req_type[20];
    int times[3]={0};
    int per=0;

    while(getline(indata,tp)){
        int k=0;
        
        //if(tp[0]=='\0') continue;

        while(tp[k]==' ' || tp[k]=='\t' || tp[k]=='\0')
        {   
            if(tp[k]=='\0') break;
            k++;
        }
        if(tp[k]=='\0') continue;

        if(count_line<3){
            
            string str="";
            
            while(tp[k]!=' ' && tp[k]!='\t' && tp[k]!='\0'){
                if(tp[k]-'0'>=0 && tp[k]-'0'<=9)
                    str+=tp[k++];
                else {
                    cout<<"Invalid Time for service.";
                    //outdata<<"Invalid Time for service.";
                    exit(1);
                }
            }
            
            int num=convert(str);
            times[count_line]=num;
        }
        else{
            int count=0;
            string str="";
            
            while(tp[k]!=' ' && tp[k]!='\t'){
                if(tp[k]-'0'>=0 && tp[k]-'0'<=9)
                    str+=tp[k++];
                else{
                    cout<<"Invalid Customer ID";
                    exit(1);
                }
            }
            
            int num=convert(str);
            custId[per]=num;
                  
            
            while(tp[k]==' ' || tp[k]=='\t') k++;

            str="";
            while(tp[k]!=' ' && tp[k]!='\t'){
                if(tp[k]-'0'>=0 && tp[k]-'0'<=9)
                    str+=tp[k++];
                else{
                    cout<<"Invalid Arrival Timer";
                    exit(1);
                }
            }
            
            num=convert(str);
            arrTime[per]=num;
            
            while(tp[k]==' ' || tp[k]=='\t') k++;

            str="";
            while(tp[k]!=' ' && tp[k]!='\t' && tp[k]!='\0'){
                if(tp[k]-'A'>=0 && tp[k]-'A'<=25)
                    str+=tp[k++];
            }
            
            if(str=="MW") req_type[per]=0;
            else if(str=="MD") req_type[per]=1;
            else if(str=="DD") req_type[per]=2;
            else{
                cout<<"Invalid request type.";
                //outdata<<"Invalid request type.";
                exit(1);
            }
            per++;
        }
        count_line++;
        
    } 
    //cout<<times[0]<<" "<<times[1]<<" "<<times[2]<<endl;
    //for(int i=0;i<per;i++){
      //  cout<<custId[i]<<" "<<arrTime[i]<<" "<<req_type[i]<<endl;
   // }

    fcfs(times,custId,arrTime,req_type,per);
}

int main(){
    int times[3]={0};
    freopen("op.txt","w",stdout);
    readData();   
    return 0;
}