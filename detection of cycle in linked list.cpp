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
void iscyclic(node *head){
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        if(fast==slow){
            cout << "is cyclic" << endl;
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast == NULL || fast->next == NULL){
        cout << "not cyclic" << endl;
    }
}
int main() {
    node *head=NULL;
    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    print(head);
    cout << endl;
    iscyclic(head);
}
