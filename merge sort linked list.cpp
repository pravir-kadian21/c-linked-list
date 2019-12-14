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

void print(node *head){
    while(head!=NULL){
        cout << head->data << "->";
        head=head->next;
    }
}

node *midpoint(node *head){
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node *merge(node *a,node *b){
    
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node *c;

    if(a->data > b->data){
        c=b;
        c->next=merge(a,b->next);
    }
    else{
        c=a;
        c->next=merge(a->next,b);
    }
    return c;
}

node *mergesort(node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }

    node *mp = midpoint(head);

    node *a=head;
    node *b=mp->next;
    mp->next = NULL;

    a=mergesort(a);
    b=mergesort(b);

    node *c=merge(a,b);
    return c;
}
int main() {
    node *head;
    node *head1;
    insertathead(head,10);
    insertathead(head,8);
    insertathead(head,2);
    insertathead(head,19);
    print(head);
    cout << endl;
    head1=mergesort(head);
    print(head1);
}
