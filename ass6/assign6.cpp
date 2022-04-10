#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
using namespace std;

//for storing hash values of elements present in set S
int store_hash_values[100][100];
//hash function to find the hash value of element x
int hash_func(int x,int a , int b, int c,int n){
    return ((a*x+b)%c)%n;
}

//function to check if element is present in set S or not
bool in_s(int x, int *s, int k){
    for(int i=0;i<k;i++){
        if(s[i]==x) return true;
    }
    return false;
}

//function for checking membership
void check_membership(int m,int *a,int *b,int *c,int n,int k,int *s,int *bloom){
    int fp=0;
    int total=n+n/2+1;
    for(int x=0;x<total;x++){
        if(in_s(x,s,k)) continue;

        bool flag=true;
        for(int j=0;j<m;j++){
            int index=hash_func(x,a[j],b[j],c[j],n);
            flag=flag && bloom[index];
        }

        if(flag){
            fp++;
            cout<<x<<", false positive yes, collusion cases";            
            //checking collisions cases
            for(int j=0;j<m;j++){
                int index=hash_func(x,a[j],b[j],c[j],n);
                for(int p=0;p<k;p++){
                    for(int q=0;q<m;q++){
                        if(store_hash_values[p][q]==index){
                            cout<<", <"<<s[p]<<","<<q+1<<">";
                        }
                    }   
                }
            }            
            cout<<endl;
        }
        else{
            cout<<x<<", false positive no."<<endl;
            
        }
        
    }
    //printing fraction
    cout<<"Fraction of false positives , p = "<<float(fp)/(total-k);
}


void perform(int m,int *a,int *b,int *c,int n,int k,int *s){
    int bloom[n]={0};

    //calculating hash values for element inside S
    for(int i=0;i<k;i++){
        for(int j=0;j<m;j++){
            int index=hash_func(s[i],a[j],b[j],c[j],n);
            store_hash_values[i][j]=index;
            bloom[index]=1;
        }
    }
    
    cout<<"m = "<<m<<endl<<"n = "<<n<<endl<<"k = "<<k<<endl;
    cout<<"Bloom filter is "<<endl;
    for(int i=0;i<n;i++){
        cout<<bloom[i]<<" ";
    }
    cout<<endl<<endl;

    check_membership(m,a,b,c,n,k,s,bloom);
}

//function for loading data from ip.txt
void loadData(){
    ifstream indata;
    indata.open("ip.txt");

    if(!indata){
        //outdata<<"No file available"<<endl;
        cout<<"No file available"<<endl;
        exit(1);
    }

    string tp;
    int m=-1,n,k,s[100];
    int a[100]={0},b[100]={0},c[100]={0};
    int line=0;
    string str="";
    bool flag=false;
    while(getline(indata,tp)){
        int i=0;
        if(flag){
            break;
        }
        //for value of m
        if(line==0){
            while(tp[i]==' ' || tp[i]=='\t') i++;
            str="";
            
            if(i==tp.length()) continue;

            while(tp[i]!='\0' && tp[i]!=' '){
                if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                    str+=tp[i++];
                else{
                    cout<<"Only numeric values are allowed.";
                    exit(1);
                }
            }
            m=stoi(str);
        
            
        }
        // for values of a,b,c
        else if(line<=m){
            while(tp[i]==' ' || tp[i]=='\t') i++;
            string str="";

            while(tp[i]!='\0' && tp[i]!=' '){
                if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                    str+=tp[i++];
                else{
                    cout<<"Only numeric values are allowed.";
                    exit(1);
                }
            }
            a[line-1]=stoi(str);

            while(tp[i]==' ' || tp[i]=='\t') i++;
            str="";

            while(tp[i]!='\0' && tp[i]!=' '){
                if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                    str+=tp[i++];
                else{
                    cout<<"Only numeric values are allowed.";
                    exit(1);
                }
            }

            b[line-1]=stoi(str);

            while(tp[i]==' ' || tp[i]=='\t') i++;
            str="";

            while(tp[i]!='\0' && tp[i]!=' '){
                if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                    str+=tp[i++];
                else{
                    cout<<"Only numeric values are allowed.";
                    exit(1);
                }
            }

            c[line-1]=stoi(str);

            
        }
        //taking input value of n
        else if(line==m+1){
            while(tp[i]==' ' || tp[i]=='\t') i++;
            str="";

            while(tp[i]!='\0' && tp[i]!=' '){
                if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                    str+=tp[i++];
                else{
                    cout<<"Only numeric values are allowed.";
                    exit(1);
                }
            }

            n=stoi(str);
        }
        //taking size of S as input in k
        else if(line==m+2){
            while(tp[i]==' ' || tp[i]=='\t') i++;
            str="";

            while(tp[i]!='\0' && tp[i]!=' '){
                if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                    str+=tp[i++];
                else{
                    cout<<"Only numeric values are allowed.";
                    exit(1);
                }
            }

            k=stoi(str);
        }
        //storing the elements of set S
        else{
            str="";
            for(int j=0;j<k;j++){
                while(tp[i]==' ' || tp[i]=='\t') i++;
                str="";
                while(tp[i]!='\0' && tp[i]!=' '){
                    if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                        str+=tp[i++];
                    else{
                        cout<<"Only numeric values are allowed.";
                        exit(1);
                    }
                }
                s[j]=stoi(str);
            }            
            flag=true;
        }
        line++;
    } 
    //bloom filter of size n
    freopen(("op_m"+to_string(m)+"n"+to_string(n)+"k"+to_string(k)+".txt").c_str(),"w",stdout);
    perform(m,a,b,c,n,k,s);
}

int main(){
    loadData();
    return 0;
}    


