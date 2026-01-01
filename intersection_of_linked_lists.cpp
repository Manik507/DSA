#include <iostream>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if (head1 == NULL || head2 == NULL)
            return NULL;

        Node* ptr1 = head1;
        Node* ptr2 = head2;

        int cnt1 = 0, cnt2 = 0;

        // Count length of first list
        while (ptr1 != NULL) {
            cnt1++;
            ptr1 = ptr1->next;
        }

        // Count length of second list
        while (ptr2 != NULL) {
            cnt2++;
            ptr2 = ptr2->next;
        }

        int d = cnt1 - cnt2;

        // Reset pointers
        ptr1 = head1;
        ptr2 = head2;

        // Move pointer of longer list
        if (d > 0) {
            while (d--) {
                ptr1 = ptr1->next;
            }
        } else {
            while (d++) {
                ptr2 = ptr2->next;
            }
        }

        // Traverse both lists together
        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1 == ptr2)
                return ptr1;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return NULL;
    }
};

// Utility function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    /*
        Creating following intersecting lists:

        List1: 1 -> 2 -> 3
                            -> 6 -> 7 -> NULL
        List2:       4 -> 5
    */

    // Common part
    Node* common = new Node(6);
    common->next = new Node(7);

    // First linked list
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    // Second linked list
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Solution obj;
    Node* intersection = obj.intersectPoint(head1, head2);

    if (intersection != NULL) {
        cout << "Intersection point data: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
