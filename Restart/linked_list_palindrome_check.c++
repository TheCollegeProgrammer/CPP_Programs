#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};


Node* Insert_at_end(Node* &head, int val){
    Node* temp = head;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return head;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* Find_mid(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void Reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool Check_Palindrom(Node* head){
    if(head == NULL || head->next == NULL) return true;

    Node* secondHalf = Find_mid(head);

    Reverse(secondHalf);

    Node* firstHalf = head;
    Node* temp = secondHalf;

    while(temp != NULL){
        if(firstHalf->data != temp->data){
            Reverse(secondHalf); // restore
            return false;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    Reverse(secondHalf);

    return true;
}

void Print_list(Node* head){
    Node* temp = head;
    if(head == NULL){
        cout<<"List is empty";
    }

    while(temp != NULL){
        cout<< temp->data <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;

    Insert_at_end(head, 1);
    Insert_at_end(head, 2);
    Insert_at_end(head, 3);
    Insert_at_end(head, 4);
    Insert_at_end(head, 4);
    Insert_at_end(head, 3);
    Insert_at_end(head, 2);
    Insert_at_end(head, 1);


    Print_list(head);
    if(Check_Palindrom(head)){
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }
}

