#include <iostream>
using namespace std;

// Definition of singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to convert binary linked list to decimal integer
int getDecimalValue(ListNode* head) {
    int res = 0;
    while (head) {
        // Left shift the current result by 1 (multiply by 2)
        // Then OR with the current node's value (0 or 1)
        res = (res << 1) | head->val;
        head = head->next; // Move to next node
    }
    return res;
}

// Helper function to insert a new node at the end of the linked list
ListNode* insertAtEnd(ListNode* head, int data) {
    if (!head) return new ListNode(data);
    ListNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new ListNode(data);
    return head;
}

// Main function to test the program
int main() {
    ListNode* head = nullptr;

    // Example: Binary number 1011 (which is 11 in decimal)
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 0);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 1);

    // Display the result
    cout << "Decimal value: " << getDecimalValue(head) << endl;

    return 0;
}
