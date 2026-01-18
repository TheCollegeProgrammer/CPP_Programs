#include <iostream>
using namespace std;

// Class representing a single node in the list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = nullptr; // nullptr is the modern C++ standard for NULL
    }
};

// Class to manage linked list operations
class LinkedList {
private:
    Node* head;

public:
    // Initialize head to nullptr
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning: O(1) time complexity
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Traverse and print all elements: O(n) time complexity
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Deletes the first occurrence of a value: O(n) time complexity
    void deleteNode(int target) {
        if (head == nullptr) return;

        // If the head itself holds the value
        if (head->data == target) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Search for the node before the target node
        Node* current = head;
        while (current->next != nullptr && current->next->data != target) {
            current = current->next;
        }

        // If the value was found, bypass the node
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Destructor to free memory when the object is destroyed
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Example usage
int main() {
    LinkedList list;

    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    cout << "Current List: ";
    list.display(); // Output: 10 -> 20 -> 30 -> NULL

    cout << "Deleting 20..." << endl;
    list.deleteNode(20);
    
    cout << "Updated List: ";
    list.display(); // Output: 10 -> 30 -> NULL

    return 0;
}
