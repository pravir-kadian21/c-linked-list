#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data=d;
        next=NULL;
    }
};

void insertathead(node *&head,int data){
    node *n=new node(data);
    n->next=head;
    head=n;
}

int len(node *head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

void insertattail(node *&head,int data){
    node *n=new node(data);
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void inseratmiddle(node *&head,int data,int p){
    if(head==NULL||p==0){
        insertathead(head,data);
    }
    if(p>len(head)){
        insertattail(head,data);
    }
    else{
        node *n=new node(data);
        int jumps=1;
        node *temp=head;
        while(jumps<=p-1){
            temp=temp->next;
            jumps++;
        }
        n->next=temp->next;
        temp->next=n;
    }
}

int iterativesearch(node *&head,int element){//iterative search
    node *temp=head;
    int pos=1;
    while(temp!=NULL){
        if(temp->data==element){
            return pos;
        }
        temp=temp->next;
        pos++;
    }
    return -1;//return -1 if not present
}




void print(node *head){
    while(head!=NULL){
        cout << head->data << "->";
        head=head->next;
    }
}

int main() {
    node*head=NULL;
    insertathead(head,5);
    insertathead(head,4);
    insertathead(head,6);
    inseratmiddle(head,7,2);
    inseratmiddle(head,9,1);
    insertattail(head,10);
    print(head);
    cout << endl;

    cout << iterativesearch(head,3) << endl;
    cout << "present at position " << iterativesearch(head,10) << endl;
    
}
