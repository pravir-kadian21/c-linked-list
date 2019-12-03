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
    node *temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
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
    n->next=NULL;
}

void insertatmiddle(node *&head,int data,int p){
    if(head==NULL||p==0){
        insertathead(head,data);
    }
    else if(p>len(head)){
        insertattail(head,data);
    }
    else{
        int jumps=1;
        node *temp=head;
        while(jumps<=p-1){
            temp=temp->next;
            jumps++;
        }
        node *n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

void print(node *head){
    while(head!=NULL){
        cout << head->data << "->";
        head = head->next;
    }
}

int main() {
    node *head = NULL;
    insertathead(head,5);
    insertathead(head,3);
    insertathead(head,1);
    insertatmiddle(head,6,2);//insert 6 after 2 positions
    insertattail(head,7);
    print(head);
}
