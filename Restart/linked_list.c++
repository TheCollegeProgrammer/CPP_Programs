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

    
}