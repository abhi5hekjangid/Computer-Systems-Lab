

Node* sub(Node* a, Node* b,Node* A,Node* B)
{
    //Your code here
    Node* head=new Node(0),*c;
    c=head;
    int count=0,diff;

    while(a!=A && b!=B){
        count++;
        if(a->data < b->data){
            a->data+=100000;
            a->right->data-=1;
        }
        diff=a->data-b->data;
        Node* newnode=new Node(diff);
        //cout<<"data0 is "<<diff<<endl;
        if(head->right==NULL){
            head->right=newnode;
            newnode->left=head;
            c=c->right;
        }
        else{
            c->right=newnode;
            newnode->left=c;
            c=c->right;
        }
        a=a->right;
        b=b->right;
    }

    if(b==B && a!=A){
        while(a!=A){
            count+=1;
        
        if(a->data<0){
            a->data+=100000;
            a->right->data-=1;
        }
        Node* newnode= new Node(a->data);
        cout<<"data is "<<a->data<<endl;
        
        c->left=newnode;
        newnode->left=c;
        c=newnode;
        a=a->right;
    }
        
    }
    head->data=count;
    if(count>0){
        c->right=head;
        head->left=c;
    }
    return head;
}
