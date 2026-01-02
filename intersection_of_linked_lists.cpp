/*
------------------------------------------------------------
Intersection of Two Linked Lists
------------------------------------------------------------
Problem:
Given two singly linked lists, find the node at which they
intersect. If the linked lists do not intersect, return NULL.

Note:
- Intersection is determined by reference, not value.
- After the intersection point, both lists share the same tail.

Approaches:
1. Brute Force (Commented)
2. Optimized using Length Difference (Implemented)

Time Complexity (Optimized): O(n + m)
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Utility function to calculate length of a linked list
int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find intersection point of two linked lists
Node* intersectPoint(Node* head1, Node* head2) {

    /*
    ------------------ BRUTE FORCE APPROACH ------------------
    Node* t1 = head1;
    while (t1 != NULL) {
        Node* t2 = head2;
        while (t2 != NULL) {
            if (t1 == t2)
                return t1;
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return NULL;
    ----------------------------------------------------------
    */

    // -------- OPTIMIZED APPROACH (USING LENGTH DIFFERENCE) --------
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {

    // Common part of the linked lists
    Node* common = new Node(6);
    common->next = new Node(7);

    // First linked list: 1 -> 2 -> 3 -> 6 -> 7
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    // Second linked list: 4 -> 5 -> 6 -> 7
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    Node* intersection = intersectPoint(head1, head2);

    if (intersection != NULL)
        cout << "Intersection at node with data: " 
             << intersection->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
