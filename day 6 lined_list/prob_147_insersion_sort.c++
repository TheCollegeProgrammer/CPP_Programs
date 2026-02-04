#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertionSortList(ListNode* head) {

    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode dummy(0);
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* prev = &dummy;
        ListNode* nextNode = curr->next;

        while (prev->next != nullptr && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = nextNode;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {

    // Create list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List:\n";
    printList(head);

    head = insertionSortList(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}
