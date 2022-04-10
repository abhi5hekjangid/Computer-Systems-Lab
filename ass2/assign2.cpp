//Abhishek Jangid
//2111CS01

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

struct Node{
    int data;
    Node* left,*right;
    
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

Node* last=NULL;

Node* push(Node* head,int x){
    if(head==NULL) last=NULL;
    Node*  newnode=new Node(x);
    newnode->right=head;
    
    if(head!=NULL)
        head->left=newnode;
    head=newnode;

    if(last==NULL) last=head;
    else{
        last->right=head;
        head->left=last;
    }
    return head;
}
int pow(int base,int p){
    int  n=1;
    while(p--)
        n*=base;
    return n;
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

pair<Node*,Node*> readInput(){
    ifstream indata;
    indata.open("ip.txt");

    if(!indata){
        cout<<"No file available"<<endl;
        exit(1);
    }
    int count=0;
    string tp;
    Node *head,*first=NULL,*second=NULL;
    string _str="";
    bool neg=0;
    int no=0;
    int nocount=0;
    while(getline(indata,tp)){
        count=0;
        
        if(tp.length()!=0) nocount++;
        head=NULL;
        neg=0;
        if(nocount>2){
            cout<<"More than 2 Numbers.";
            exit(1);
        }
        for(int k=0;k<tp.length();){
            if(k==0){
                while((tp[k]==' '||tp[k]=='\t' || tp[k]=='0' || tp[k]=='-' ) && k<tp.length()){
                    if(tp[k]=='-')
                        neg=1;
                    k++;
                }
                
            }
            int num;
            if(k==tp.length()){
                if (neg==1) {
                cout<<"-0 invalid.";
                exit(1);
                }
                else num=0;
            }            
            else{
                int n=5;
                
                if((tp.length()-k)%5!=0)
                 n=(tp.length()-k)%5;
                
                string str="";
                
                while(n--){
                    if(tp[k]-'0'<0 || tp[k]-'0'>9){
                        cout<<"Only numbers allowed inside input.";
                        exit(1);
                    }
                    str+=tp[k++];
                }
                num=convert(str);
            }
            //cout<<"no is "<<num<<endl;
            head=push(head,num);
            
            count++;
        }
        if(tp.length()!=0){
            if(neg) count*=-1;
            head=push(head,count);
            if(no==0)
                first=head;
            else   
                second=head;
            no++;  
        }
    }
    
    return {first,second};

}
int compare(Node* a,Node* b,Node* A,Node* B,int count){
    if(a!=NULL && b!=NULL){
        do{
            
            if(a->data==b->data){
                a=a->left;
                b=b->left;
            }
            else if(a->data>b->data){
                if((A->data<0 && B->data<0)) return -1;
                return 1;
            }
                
            else{
                if((A->data<0 && B->data<0)) return 1;    
                return -1;
            }
        }while(a!=A && b!=B);
        if(a==A && b==B) return 0;
    }
    if(a!=NULL) return 1;
    if(b!=NULL) return -1;
}
Node* add(Node* res,Node* a,Node* b,Node* A,Node* B,int carry){
    if(a==A && b==B){
        if(carry!=0){
            res=push(res,carry);
        }
        return res;
    }
    if(a==A){
        res=push(res,b->data);   
        return res;
    }
    if(b==B){
        res=push(res,a->data);
        return res;
    }

    int x=a->data+b->data+carry;
    carry=x/100000;
    x=x%100000;
    //cout<<"x is "<<x<<" carry is "<<carry<<endl;
    //cout<<"a->right "<<a->right<<" b->right "<<b->right<<" "<<A<<" "<<B<<endl;
    res= push(res,x);
    return add(res,a->right,b->right,A,B,carry);
}
Node* sub1(Node* res,Node* a, Node* b,Node* A,Node* B)
{
    //Your code here
    if(a==A && b==B){
        return res;
    }
    if(a==A){
        res=push(res,abs(b->data));  
         
        return sub1(res,a,b->right,A,B);
    }
    if(b==B){
        res=push(res,abs(a->data));
        return sub1(res,a->right,b,A,B);
    }
    int x=a->data-b->data;
    
    
    //cout<<"x is "<<x<<" carry is "<<endl;
    //cout<<"a->right "<<a->right<<" b->right "<<b->right<<" "<<A<<" "<<B<<endl;
    res= push(res,abs(x));
    return sub1(res,a->right,b->right,A,B);
}

int findcount(int n){
    int c=0;
    if(n==0) return 1;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}
void printList(Node* first){
    if(first==NULL) return;
    Node* temp=first;
        do
        { 
            int c=findcount(temp->data);
            c=5-c;
            while(c-- && temp!=first->left && temp!=first) cout<<"0";
            
            cout << temp->data;
            if(temp->right!=first)
                cout<<"->";
            
            temp = temp->right; 
        } 
        while (temp != first);
                
        cout<<endl;
}
void printAddSub(Node* first,ofstream &outdata){
    if(first==NULL) return;
    Node* temp=first;
        do
        {   
            int c=findcount(temp->data);
            c=5-c;
            while(c-- && temp!=first){ 
                cout<<"0";
                outdata<<"0";
            }
            cout << temp->data;
            outdata << temp->data ;
            if(temp->right!=first && temp->left!=NULL){
                cout << ","; 
                outdata << ",";
            } 
            temp = temp->right; 
        } 
        while (temp!=NULL && temp != first);
        outdata<<endl;
        cout<<endl;
}

bool sign1(Node* A,Node* B){
    bool sign=1;
    Node* a=A->left,*b=B->left;

    do{
        if(a->data>b->data){
            sign=1;
            break;
        }
        else {
            sign=0;
            break;
        }
        a=a->left;
        b=b->left;
    }while(a!=A && b!=B);

    return sign;
  
}
Node* addhelper(Node* sub12,Node* first,Node* second,int res){
    bool s=sign1(first,second);
    if(first->data>0 && second->data<0){
            if(s==1) return sub1(sub12,first->right,second->right,first,second);
            
            sub12= sub1(sub12,first->right,second->right,first,second);
            sub12->data*=-1;
            return sub12;     
    }
    else if(first->data<0 && second->data>0 ){
        if(s==1){
            sub12=sub1(sub12,second->right,first->right,second,first);
            sub12->data*=-1;
            return sub12;
        }
        else
             return sub1(sub12,second->right,first->right,second,first);
        }
    else if(first->data<0 && second->data<0){
        sub12= add(sub12,first->right,second->right,first,second,0);
        sub12->data*=-1;
        return sub12;
    }
    else{
        return add(sub12,first->right,second->right,first,second,0);
    }
}
Node* subhelper(Node* sub12,Node* first,Node* second,int res){
    bool s=sign1(first,second);

    if(first->data>0 && second->data<0){
        return add(sub12,first->right,second->right,first,second,0);
    }
    else if(first->data<0 && second->data>0 ){
        sub12= add(sub12,first->right,second->right,first,second,0);
        sub12->data*=-1;
        return sub12;
    }
    else if(first->data<0 && second->data<0){
        if(s==1){
            sub12=sub1(sub12,second->right,first->right,second,first);
            sub12->data*=-1;
            return sub12;
        }
        else{
            sub12=sub1(sub12,second->right,first->right,second,first);
            return sub12;
        }
    }
    else{
        if(s==0){
            sub12=sub1(sub12,first->right,second->right,first,second);
            sub12->data*=-1;
            return sub12;
        }
        return sub1(sub12,first->right,second->right,first,second);
    }
}

int main(){
    ofstream outdata;
    auto head=readInput();
    
    Node* first=head.first,*second=head.second;
    printList(first);
    printList(second);
    cout<<endl;
    int res=compare(first,second,first,second,0);

    
    outdata.open("op.txt",ios::out); // opens the file
    cout<<"Comparison result:";
    outdata<<"Comparison result:";
    if(res==1){
        outdata<<" first number is greater than the second number"<<endl;
        cout<<" first number is greater than the second number"<<endl;
    }
    else if(res==-1){
        outdata<<" first number is lesser than the second number"<<endl;
        cout<<" first number is lesser than the second number"<<endl;
    }
    else{
        outdata<<" first number is equal to the second number"<<endl;
        cout<<" first number is equal to the second number"<<endl;
    }
    Node* additon=NULL;
    additon=addhelper(additon,first,second,res);
    
    cout<<"Addition result: ";
    outdata<<"Addition result: ";
    printAddSub(additon,outdata);
    
    Node* sub12=NULL;
    sub12=subhelper(sub12,first,second,res);

    cout<<"Subtraction result: ";
    outdata<<"Subtraction result: ";
    
    if(res==0)
        cout<<res;
    else printAddSub(sub12,outdata);
    return 0;
}