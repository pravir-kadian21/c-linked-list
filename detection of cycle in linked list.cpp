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
bool iscyclic(node *head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main() {
    node *head=NULL;
    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    print(head);
    cout << endl;
    if(iscyclic(head)){
        cout << "cycle found" << endl;
    }
    else{
        cout << "cycle not found" << endl;
    }
}
