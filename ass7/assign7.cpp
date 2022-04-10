//2111cs01
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
using namespace std;

//for storing the color of each vertex
int color[100];

//structure of each node
struct Node{
    int data;
    Node* right;
    Node(){
        right=NULL;
    }
};

//class graph which contains printing methods and sturcture of graph
class Graph
{
    public:
        int V;
        Node* arr[100]; 
    public:
        Graph(int V)
        {
            this->V = V;
             //total vertices
            for (int i = 0; i < V; ++i){
                arr[i]=new Node();
                arr[i]->data=i;
            }
        }
    //function for adding edges to graph
    void addEdge(int src, int dst)
    {	
        Node* head=arr[src];
        while(head->right){
            head=head->right;
        }
        Node* newnode=new Node();
        newnode->data=dst;
        head->right=newnode;
    }

    void printGraph()
    {       cout<<"\nOriginal Graph"<<endl;
            int v;
            for (v = 0; v < V; ++v)
            {   
                Node* temp=arr[v];
                if(temp->right){
                    cout<<temp->data<<" -> ";
                    temp=temp->right;
                }
                while(temp){
                    if(temp->right==NULL)
                        cout<<temp->data;
                    else               
                        cout<<temp->data<<", ";

                    temp=temp->right;
                }
                cout<<endl;
            }
    }
    void printGraphRed()
    {
             cout<<"\nRed SubGraph"<<endl;
            int v;
            for (v = 0; v < V ; ++v)
            {   
                if(color[v]==0) continue;
                Node* temp=arr[v];
                if(temp->right){
                    cout<<temp->data<<" -> ";
                    temp=temp->right;
                }
                while(temp){
                    if(color[temp->data]!=0){
                       cout<<temp->data<<", ";
                    }
                    temp=temp->right;
                }
                cout<<endl;
            }
    }
    void printGraphBlue()
    {
            cout<<"\nBlue SubGraph"<<endl;
            int v;
            for (v = 0; v < V  ; ++v)
            {   
                if(color[v]==1) continue;
                Node* temp=arr[v];
                if(temp->right){
                    cout<<temp->data<<" -> ";
                    temp=temp->right;
                }
                while(temp){
                    if(color[temp->data]!=1){
                        cout<<temp->data<<", ";
                    }
                    temp=temp->right;
                }
                cout<<endl;
            }
    }
};

Graph *g;


bool vis[100];
int cyc[100];
int index=-1;
int check[100]={0};

//dfs function to find cycle inside whole graph
bool dfs(int s, int p,int root){
    vis[s]=1;
    for (Node* curr=g->arr[s]->right;curr!=NULL ; curr=curr->right) {
        int i=curr->data;
        if(i>=root){    
            cyc[++index]=i;
            if (!vis[i]) {if (dfs(i,s,root)) return 1;}
            else if (i!=p){return 1;}
            index=index-1;
        }
    }
    return 0;
}

//dfs function to find cycle in color graphs
bool dfsColor(int s, int p,int c,int root){
    vis[s]=1;
    for (Node* curr=g->arr[s]->right;curr!=NULL;curr=curr->right) {
        int i=curr->data;
        if((i>=root) && color[i]==c){    
            cyc[++index]=i;
            if (!vis[i]) {if (dfsColor(i,s,c,root)) return 1;}
            else if (i!=p){return 1;}
            index=index-1;
        }
    }
    return 0;
}

//function for calling dfs and printing cycles for whole graph
 void solve(){
     bool flag=true;
     index=-1;
     for(int i=0;i<g->V;i++){
         cyc[i]=vis[i]=0;
     }
     cout<<"\nMulti Color Cycles "<<endl;
     for(int i=0;i<g->V;i++){
      
        cyc[++index]=i;

        for(int j=0;j<g->V;j++) vis[j]=0;
        
        if (!vis[i] && dfs(i,-1,i)){
            
            int ans[100];
            int idx=-1;
            ans[++idx]=cyc[index];

           
            flag=false;
            for(auto j=index-1;j>=0;j--){
                ans[++idx]=cyc[j];

                if(cyc[j]==cyc[index]) break;
            }
            cout<<endl;
            for(int i=idx;i>=0;i--){
                if(i==0)
                    cout<<ans[i]<<" color (";
                else cout<<ans[i]<<"-";
            }
            
            //printing color of vertexes
            for(int i=idx;i>=0;i--){
                if(color[ans[i]]==0){
                    if(i!=0)
                        cout<<"b-";
                    else cout<<"b)";
                }
                else{
                    if(i!=0)
                        cout<<"r-";
                    else cout<<"r)";
                    
                }
            }
        }
        index--;
    }
    if(flag){
        cout<<"No cycle detected";
    }
    cout<<endl;
 }

Graph* getcolGraph(Graph* g,int c){
    int n=0;
    for(int i=0;i<g->V;i++){
        if(color[i]==c){
            n++;
        }
    }
    Graph *gc=new Graph(n);
    int k=0;
    //initializing the nodes of new subgraph
    for(int i=0;i<g->V;i++){
        if(color[i]==c){
            gc->arr[k++]->data=i;
        }
    }
    return gc;
}

//function for calling dfs and printing cycles for colored graph
 void solveColor(int c){
     index=-1;
     bool flag=true;
     for(int i=0;i<g->V;i++){
         cyc[i]=vis[i]=0;
     }
     if(c)
        cout<<"\nRed Cycles "<<endl;
     else 
        cout<<"\nBlue Cycles "<<endl;
     
     for(int i=0;i<g->V;i++){
    
        cyc[++index]=i;
        check[i]=1;
        for(int j=0;j<g->V;j++) vis[j]=0;

       if (!vis[i] &&  color[i]==c && dfsColor(i,-1,c,i)){
            int ans[100];
            int idx=-1;
            ans[++idx]=cyc[index];

            flag=false;
           
            for(auto j=index-1;j>=0;j--){
                ans[++idx]=cyc[j];

                if(cyc[j]==cyc[index]) break;
            }
            cout<<endl;
            for(int i=idx;i>=0;i--){
                if(i==0)
                    cout<<ans[i]<<" color (";
                else cout<<ans[i]<<"-";
            }
            
            for(int i=idx;i>=0;i--){
                if(c==0){
                    if(i!=0)
                        cout<<"b-";
                    else cout<<"b)";
                }
                else{
                    if(i!=0)
                        cout<<"r-";
                    else cout<<"r)";
                    
                }
            }
            
        }
        index--;
    }
    if(flag){
        cout<<"No cycle detected";
    }
    cout<<endl;
 }


//function for loading data from ip.txt
void readGraph(){
    ifstream indata;
    cout<<"Enter Input File name: ";
    string ipFile;
    cin>>ipFile;
    indata.open(ipFile);
    cout<<"Enter Output file name(with extension) : ";
    string oname;
    cin>>oname;
    freopen(oname.c_str(),"w",stdout);

    if(!indata){
        //outdata<<"No file available"<<endl;
        cout<<"No Input file available."<<endl;
        exit(1);
    }

    string tp;
    int line=0,n;
    string str="";
    while(getline(indata,tp)){
        int i=0;
        if(line==0){
            // cout<<"Reading line 1"<<endl;
            while(tp[i]==' ' || tp[i]=='\t') i++;
            str="";
            
            if(i==tp.length()){
                cout<<"Enter Input data ";
                exit(1);
            }

            while(tp[i]!='\0' && tp[i]!=' '){
                if(tp[i]-'0'>=0 && tp[i]-'0'<=9)
                    str+=tp[i++];
                else{
                    cout<<"Only numeric values are allowed.";
                    exit(1);
                }
            }
            n=stoi(str);
            g=new Graph(n);
        }
        else if(line==1){
            // cout<<"Reading line 2"<<endl;
            while(tp[i]==' ' || tp[i]=='\t') i++;
            str="";

            int index=0;

            while(tp[i]!='\0' && tp[i]!='\n' && index!=n){
                if(tp[i]==' '){
                    i++;
                    continue;
                }
                else if(tp[i]=='r')
                    color[index++]=1;
                
                else if(tp[i]=='b')
                    color[index++]=0;
                else{
                    cout<<"Incompatible Input Values.";
                    exit(1);
                }
                i++;
            }
            if(index!=n){
                cout<<"More than n vertices color values present.";
                exit(1);
            }
        }
        else if(line==2){
        //    cout<<"Reading line 3"<<endl;
           X:
            while(tp[i]==' ' || tp[i]=='\t') i++;

               str="";
               while(tp[i]!='\0' && tp[i]!=' '){

                    if(tp[i]=='-' || (tp[i]-'0'>=0 && tp[i]-'0'<=9))
                        str+=tp[i++];
                    else{
                        cout<<"Only numeric values are allowed 1.";
                        exit(1);
                    }
                }
                int first = stoi(str);
                if(first==-1) break;

                str="";
                
                while(tp[i]==' ' || tp[i]=='\t') i++;

                while(tp[i]!='\0' && tp[i]!=' ' && tp[i]!=','){
                    
                    if((tp[i]-'0'>=0 && tp[i]-'0'<=9) || tp[i]=='-')
                        str+=tp[i++];
                    else{
                        cout<<"Only numeric values are allowed 2."<<endl;
                        exit(1);
                    }
                }
                int second = stoi(str);
                
                if(first>=n || second>=n ||first<0 || second<0) {
                    cout<<"Wrong vertex no in egdes's input.";
                    exit(1);
                }
                g->addEdge(first,second);
                g->addEdge(second,first);
                while(tp[i]==' ' || tp[i]=='\t' || tp[i]==',') i++;

                goto X;
        }
        else{
            continue;
        }
        line++;
    } 
    //g is the graph
    g->printGraph();
    g->printGraphRed();
    g->printGraphBlue();
    
    solveColor(1);
    solveColor(0);
    solve();
}

int main(){
    readGraph();
    return 0;
}
