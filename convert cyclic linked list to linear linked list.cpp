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

void createcyclic(node *&head){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *temp1=head;
    temp1=temp1->next;
    temp->next=temp1;
}

void convertcyclictolinear(node *&head){
    node *slow=head;
    node *fast=head;
    fast=fast->next->next;
    slow=slow->next;
    while(fast!=slow){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    node*temp=slow;
    while(temp!=NULL){
        temp=temp->next;
        if(temp->next == slow){
            break;
        }
    }
    temp->next=NULL;
}
int main() {
    node *head=NULL;
    insertathead(head,20);
    insertathead(head,4);
    insertathead(head,15);
    insertathead(head,10);

    if(iscyclic(head)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    createcyclic(head);
    if(iscyclic(head)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    convertcyclictolinear(head);
    if(iscyclic(head)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    print(head);
   
}
