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

void insertattail(node *&head,int data){
    node *n=new node(data);
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertathead(node *&head,int data){
    node *n=new node(data);
    n->next=NULL;
    head=n;
}

void print(node *head){
    while(head!=NULL){
        cout << head->data << "->";
        head = head->next;
    }
}
void buildlist(node *&head){
    int data;
    cin>>data;
    insertathead(head,data);
    cin>>data;
    while(data!=-1){
        insertattail(head,data);
        cin>>data;
    }
}

node *midpoint(node *head){//finding the midpoint of linked list by runner technique
    if(head==NULL||head->next==NULL){
        return head;
    }
    node *fast=head->next;
    node *slow = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

istream& operator>>(istream &is,node *&head){
    buildlist(head);
    return is;
}

ostream& operator<<(ostream &os,node *head){
    print(head);
    return os;
}

int main() {
    node *head = NULL;
    
    cin>>head;
    cout << head << endl;
    
    node *m=midpoint(head);
    cout << m->data << endl;
    return 0;
}
