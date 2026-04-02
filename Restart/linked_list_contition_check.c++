#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void Insert_At_End(Node* &head, int val){
    Node* newNode = new Node();
    Node* temp = head;
    newNode->data = val;
    newNode->next = NULL;

    if(temp == NULL){
        head = newNode;
        return;
    }

    if(true){
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle: " << slow->data << endl;
}

void detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "Cycle detected" << endl;
            return;
        }
    }

    cout << "No cycle" << endl;
}

Node* Make_Cycle(Node* &head){
    Node* temp = head;
    if(temp == NULL){
        return head;
    }
    Node* temp_2 = temp;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = temp_2;
    return head; 
}

void Print_List(Node* head){
    Node* temp = head;
    int count = 0;

    while(temp != NULL && count < 20){
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "..." << endl;
}


int main(){
    Node* head = NULL;;
    Insert_At_End(head, 1);
    Insert_At_End(head, 2);
    Insert_At_End(head, 3);
    Insert_At_End(head, 4);
    Insert_At_End(head, 5);
    Print_List(head);
    findMiddle(head);
    head = Make_Cycle(head);
    Print_List(head);
    detectCycle(head);

}
