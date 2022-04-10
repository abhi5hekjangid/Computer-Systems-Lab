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

void checkvalid(int * l,int * r,int n){
    int count1=1;

    for(int i=0;i<n;i++){
        if(l[i]!=-1) count1++;
        if(r[i]!=-1) count1++;
    }

    if(count1!=n){
        cout<<"Invalid Tree.";
        exit(1);
    }
}

//function for finding height of tree
int height(Node* root){
    if(!root) return -1;
    int l=height(root->left);
    int r=height(root->right);

    return max(l,r)+1;
}

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
    if(q.Front()->isL ==-1 && q.Front()->isR==-1)
    {   q.pop();
        insertValue(i,n,data,l,r,q);
        return;
    }
    //making curr node as the left child of root
    if (q.Front()->isL!=-1){
        q.Front()->left = node;
        q.push(node);
    }
    
    //making curr node as right child of tree
    if(q.Front()->isR!=-1) {
        if(q.Front()->isL!=-1){
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
    cout<<"the preorder traversal of the tree is ";
    printTreePre(root);
    cout<<"\nthe inorder traversal of the tree is ";
    printTreeIn(root);
}
void emptyQueue(Queue &q){
    while(!q.isEmpty()){
        q.pop();
    }
}
void farNode(Node* root,int h,int lvl,Queue &q){
    if(!root) return;
    if(lvl==h){
        q.push(root); 
    }
    farNode(root->left,h,lvl+1,q);
    farNode(root->right,h,lvl+1,q);
}

//function for finding the farthest node in tree
void findFarNode(Node* root){
    Queue q;
    int h=height(root);
    farNode(root,h,0,q);

    cout<<"\n\nFor the aforementioned example, the farthest leaf node(s): ";
    while(!q.isEmpty()){
        cout<<q.Front()->data<<" ";
        q.pop();
    }
    cout<<"\nThe distance of the leaf from the root is: "<<h;
}
//function for performing right rotation on value 'x'
Node* rightRotate(Node* root,int x,bool &flag){
    if(!root) return NULL;
    if(root->data==x){
        
        Node *x = root->left;
        if(x!=NULL ){
            // Perform rotation
            Node* T2=x->right;
            x->right = root;
            root->left = T2;
            flag=true;
            return x;
        }
    }
    root->left=rightRotate(root->left,x,flag);
    root->right=rightRotate(root->right,x,flag);
    return root;
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
        data[n]=stoi(str);
        while(tp[i]==' ' || tp[i]=='\t') i++;

        if(tp[i]=='\0'){
            cout<<"Less values than expected in input.";
            exit(1);
        
        }
        str="";
        while(tp[i]!='\0' && tp[i]!=' '){
            if(tp[i]=='-' || (tp[i]-'0'>=0 && tp[i]-'0'<=9))
                str+=tp[i++];
            else{
                cout<<"Only numeric values are allowed.";
                exit(1);
            }
        }    
        l[n]=stoi(str);

       
        while(tp[i]==' ' || tp[i]=='\t') i++;

        if(tp[i]=='\0'){
            cout<<"Less values than expected in input.";
            exit(1);
        }        
        str="";
        while( tp[i]!='\0' && tp[i]!=' '){
            if(tp[i]=='-' || (tp[i]-'0'>=0 && tp[i]-'0'<=9))
                str+=tp[i++];
            else{
                cout<<"Only numeric values are allowed.";
                exit(1);
            }
        }
        
        r[n]=stoi(str);

        while(tp[i]==' ' || tp[i]=='\t') i++;
        
        if(i!=tp.length()){
            cout<<"Invalid Input.";
            exit(1);
        }
        n++;

    } 
    checkvalid(l,r,n);
    Node* root = new Node(data[0],l[0],r[0]);
    Queue q;
    q.push(root);
    insertValue(1,n,data,l,r,q);
    printTree(root);
    findFarNode(root);

    bool flag=false;
    int x;
    cout<<"\n\nFor the aforementioned example,\nEnter key value for right rotation: ";
    cin>>x;
    //calling the right rotation function
    rightRotate(root,x,flag);
    if(!flag){
        cout<<"\nRight rotation w.r.t "<<x<<" is not possible.";  
    }
    else{
        cout<<"\nRight rotation w.r.t "<<x<<" is possible."<<endl;
        cout<<"The tree after right rotation.\n"<<endl;
        printTree(root);
    }
}

int main(){
    readData();
    return 0;
}