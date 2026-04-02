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

Node* merge_list(Node* head, Node* head_2){
    Node* dummy = new Node();
    Node* tail = dummy;

    Node* temp = head;
    Node* temp_2 = head_2;

    while(temp != NULL && temp_2 != NULL){
        if(temp->data > temp_2->data){
            tail->next = new Node();
            tail = tail->next;
            tail->data = temp_2->data;
            tail->next = NULL;
            temp_2 = temp_2->next;
        }else{
            tail->next = new Node();
            tail = tail->next;
            tail->data = temp->data;
            tail->next = NULL;
            temp = temp->next;
        }
    }
    while(temp != NULL){
        tail->next = new Node();
        tail = tail->next;
        tail->data = temp->data;
        tail->next = NULL;
        temp = temp->next;
    }

    while(temp_2 != NULL){
        tail->next = new Node();
        tail = tail->next;
        tail->data = temp_2->data;
        tail->next = NULL;
        temp_2 = temp_2->next;
    }
    return dummy->next;
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
    Node* head_2 = NULL;
    Node* m_head = NULL;
    Insert_At_End(head, 1);
    Insert_At_End(head, 3);
    Insert_At_End(head, 5);

    Insert_At_End(head_2, 2);
    Insert_At_End(head_2, 4);
    Insert_At_End(head_2, 6);
    
    printList(head);
    printList(head_2);

    // head = Reverse(head);
    m_head =  merge_list(head,head_2);
    printList(m_head);
    
}