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

node *kthfromlast(node *head,int k){
    node *slow=head;
    node *fast = head;
    int jumps = 1;
    while(jumps<=k){
        fast =fast->next;
        jumps++;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow = slow->next;
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
    
    int k;
    cin>>k;
    node *e=kthfromlast(head,k);
    cout << e->data << endl;
    return 0;
}
