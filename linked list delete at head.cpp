#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data =d;
        next=NULL;
    }

};

void inserathead(node *&head,int data){
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

void insertinmiddle(node *&head,int data,int p){
    if(head==NULL||p==0){
        inserathead(head,data);
    }
    else if(p>len(head)){
        insertattail(head,data);
    }
    else{
        node *temp=head;
        int jumps=1;
        while(jumps<=p-1){
            temp=temp->next;
            jumps++;
        }
        node *n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

void deletehead(node *&head){
    node *temp=head;
    head=head->next;
    delete temp;
}

void print(node *head){
    while(head!=NULL){
        cout << head->data << "->";
        head=head->next;
    }
}

int main() {
    node *head=NULL;
    inserathead(head,5);
    inserathead(head,4);
    inserathead(head,3);
    inserathead(head,2);
    inserathead(head,1);
    insertinmiddle(head,6,2);
    insertattail(head,7);
    print(head);
    cout << endl;
    deletehead(head);
    print(head);
}
