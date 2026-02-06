#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};


/*
Node* head
head is a copy of the pointer
Changing it does NOT change original head

Node*& head
head is a reference to the pointer

Changing it changes the original pointer
*/
void addlast(Node*& head, Node*& tail, int data){

   Node* nn = new Node(data);

   if(head == NULL){
    head = tail = nn;
   }
   else{
    tail->next = nn;
    tail = nn;
   }
}

void display(Node* head){

    for(Node* it = head; it != NULL; it = it->next){
        cout<<it->data<<",";
    }
    
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    addlast(head, tail, 1);
    addlast(head, tail, 2);
    addlast(head, tail, 3);
    addlast(head, tail, 4);
    addlast(head, tail, 5);
    addlast(head, tail, 6);

    display(head);
    return 0;
}