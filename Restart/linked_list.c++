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

Node* remove_Nth_node(Node* &head, int n){
    Node* slow = head;
    Node* fast = head;

    for(int i = 0; i < n; i++){
        fast = fast->next;
    }

    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;
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
    Insert_At_End(head, 1);
    Insert_At_End(head, 2);
    Insert_At_End(head, 3);
    Insert_At_End(head, 4);
    Insert_At_End(head, 5);
    Insert_At_End(head, 6);
    Insert_At_End(head, 7);
    Insert_At_End(head, 8);
    Insert_At_End(head, 9);
    printList(head);
    // head = Reverse(head);
    int n = 5;
    head_2 = remove_Nth_node(head, n);
    printList(head_2);
    
}