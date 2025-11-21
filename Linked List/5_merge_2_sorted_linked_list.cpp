#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert at end of list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Display the list
void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Recursive merge function
Node* mergeSortedLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeSortedLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSortedLists(l1, l2->next);
        return l2;
    }
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Create first sorted list: 1 → 3 → 5
    insert(list1, 1);
    insert(list1, 3);
    insert(list1, 5);

    // Create second sorted list: 2 → 4 → 6
    insert(list2, 2);
    insert(list2, 4);
    insert(list2, 6);

    cout << "List 1: ";
    display(list1);

    cout << "List 2: ";
    display(list2);

    // Merge the two lists
    Node* merged = mergeSortedLists(list1, list2);

    cout << "Merged List: ";
    display(merged);

    return 0;
}