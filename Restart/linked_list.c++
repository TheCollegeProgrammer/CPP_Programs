#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void Insert_At_End(Node* &head, int val){
    Node* newNode  = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* Reverse(Node* head){
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = NULL;

    Insert_At_End(head, 1);
    Insert_At_End(head, 2);
    Insert_At_End(head, 3);

    printList(head);
    head = Reverse(head);
    printList(head);
    
}