//Abhishek Jangid
//2111CS01

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX_SIZE 101
using namespace std;

//structure of tree node
struct Node{
    int data,isL,isR;
    Node* left,*right;
    
    Node(int x,int l,int r){
        data=x;
        isL=l;
        isR=r;
        left=right=NULL;
    }
};
 
 //implemented queue for building tree
class Queue
{
public:
	Node* A[MAX_SIZE];
	int front, rear; 
public:
	Queue()
	{
		front = -1; 
		rear = -1;
	}

	
	bool isEmpty()
	{
		return (front == -1 && rear == -1); 
	}

	bool isFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}

		void push(Node* x)
	{
		
		if(isFull())
		{
			
			return;
		}
		if (isEmpty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
        
		A[rear] = x;
	}
 
	void pop()
	{
		
		if(isEmpty())
		{
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}
	 
	Node* Front()
	{
		if(front == -1)
		{
			return NULL; 
		}
		return A[front];
	}
};

//function for building tree and inserting data into tree
void insertValue(int i,int n,int *data, int *l, int *r, Queue &q)
{   
    if(q.isEmpty()|| i>=n) return;

    Node* node = new Node(data[i],l[i],r[i]);    
    //data={1,2,3} i=1
    // 1
    // 2 3
    //q=2 3
    //node 3
    //cout<<"data is "<<node->data<<endl; 

    //if a node doesn't have left and right child the we pop from
    //queue and insert next value
    if(q.Front()->isL ==0 && q.Front()->isR==0)
    {   q.pop();
        insertValue(i,n,data,l,r,q);
        return;
    }
    //making curr node as the left child of root
    if (q.Front()->isL==1){
        q.Front()->left = node;
        q.push(node);
    }
    
    //making curr node as right child of tree
    if(q.Front()->isR==1) {
        if(q.Front()->isL==1){
            i++;
            node = new Node(data[i],l[i],r[i]);
            q.Front()->right=node;
            q.push(node); 
        }
        else{
            q.push(node);
            q.Front()->right=node;
        }
    }
    if(!q.isEmpty())
        q.pop();

    insertValue(i+1,n,data,l,r,q);
}

//function to find power
int pow(int base,int p){
    int  n=1;
    while(p--)
        n*=base;
    return n;
}

//function for converting string into number(int)
int convert(string str){
    int num=0;
    //cout<<"string is "<<str<<endl;
    int l=str.length();
    for(int i=0;i<l;i++){
        num=pow(10,l-i-1)*(str[i]-'0')+num;
    }
    return num;
}

//function for printing preorder traversal
void printTreePre(Node* root){
    if(!root){
        return;
    } 
    cout<<root->data<<" ";
    printTreePre(root->left);
    printTreePre(root->right);
}

//function for printing inorder traversal
void printTreeIn(Node* root){
    if(!root){
        return;
    }    
    printTreeIn(root->left);
    cout<<root->data<<" ";
    printTreeIn(root->right);
}

//function for printing tree
void printTree(Node* root){
    if(!root) return;
    cout<<"Preorder : ";
    printTreePre(root);
    cout<<"\nInorder : ";
    printTreeIn(root);
}

//function for finding height of tree
int height(Node* root){
    if(!root) return -1;
    int l=height(root->left);
    int r=height(root->right);

    return max(l,r)+1;
}

//function for checking if tree is valid or invalid
void checkvalid(int * l,int * r,int n){
    int count1=1;

    for(int i=0;i<n;i++){
        if(l[i]) count1++;
        if(r[i]) count1++;
    }

    if(count1!=n){
        cout<<"Invalid Tree.";
        exit(1);
    }
}

//function for making tree left tilted
void makeTilted(Node* root){
    if(!root) return;
    int l=height(root->left);
    int r=height(root->right);
    //if height of left subtree is less than right subtree 
    //the swap left and right child of current node
    if(l<r){
        Node* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    makeTilted(root->left);
    makeTilted(root->right);
}


void readData(){
    ifstream indata;
    indata.open("ip.txt");

    if(!indata){
        //outdata<<"No file available"<<endl;
        cout<<"No file available"<<endl;
        exit(1);
    }

    string tp;
    int data[101];
    int n=0;
    int l[101]={0},r[101]={0};

    while(getline(indata,tp)){
        int i=0;
        while(tp[i]==' ' || tp[i]=='\t') i++;
        string str="";
        
        if(i==tp.length()) continue;

        while(tp[i]!='\0' && tp[i]!=' '){
            if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                str+=tp[i++];
            else{
                cout<<"Only numeric values are allowed.";
                exit(1);
            }
        }
        data[n]=convert(str);
        while(tp[i]==' ' || tp[i]=='\t') i++;

        if(tp[i]=='\0'){
            cout<<"Less values than expected in input.";
            exit(1);
        
        }
        str="";
        while(tp[i]!='\0' && tp[i]!=' '){
            if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                str+=tp[i++];
            else{
                cout<<"Only numeric values are allowed.";
                exit(1);
            }
        }    
        l[n]=convert(str);


        if(l[n]!=0 && l[n]!=1){
            cout<<"Invalid input for key(node) "<<data[n]<<".";
            exit(1);
        }
        while(tp[i]==' ' || tp[i]=='\t') i++;

        if(tp[i]=='\0'){
            cout<<"Less values than expected in input.";
            exit(1);
        }        
        str="";
        while(tp[i]!='\0' && tp[i]!=' '){
            if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                str+=tp[i++];
            else{
                cout<<"Only numeric values are allowed.";
                exit(1);
            }
        }
        
        r[n]=convert(str);
        
        if(r[n]!=0 && r[n]!=1){
            cout<<"Invalid input for key(node) "<<data[n]<<".";
            exit(1);
        }
        
        while(tp[i]==' ' || tp[i]=='\t') i++;
        
        if(i!=tp.length()){
            cout<<"Invalid Input.";
            exit(1);
        }
        n++;

    } 
    //for(int i=0;i<n;i++)
      //  cout<<data[i]<<" "<<l[i]<<" "<<r[i]<<endl;
    
    //finding duplicates

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(data[i]==data[j])
            {
                cout<<"Duplicates keys are present.";
                exit(1);
            }

        }
    }

    checkvalid(l,r,n);
    Node* root = new Node(data[0],l[0],r[0]);
    Queue q;
    q.push(root);
    insertValue(1,n,data,l,r,q);
    cout<<"For the input binary tree\n"<<endl;
    printTree(root);
    makeTilted(root);
    cout<<"\n\nFor the left tilted binary tree\n"<<endl;
    printTree(root);    
}

int main(){
    freopen("op.txt","w",stdout);
    readData();
    return 0;
}