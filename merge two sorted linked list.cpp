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
int main() {
    node *head1;
    node *head2;
    insertathead(head1,10);
    insertathead(head1,8);
    insertathead(head1,2);
    insertathead(head1,1);
    print(head1);
    cout << endl;
    insertathead(head2,23);
    insertathead(head2,19);
    insertathead(head2,17);
    insertathead(head2,4);
    insertathead(head2,3);
    print(head2);
    cout << endl;
    head1=merge(head1,head2);
    print(head1);
}
