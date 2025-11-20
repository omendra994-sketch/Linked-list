#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display list safely (limit to 20 nodes to avoid infinite loop)
    void displaySafe() {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < 20) {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        cout << (count == 20 ? "... (loop suspected)\n" : "NULL\n");
    }

    // 🔍 Your loop detection logic goes here
    void detectCycle() {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "There is a loop in the linked list\n";
            return;
        }
    }

    cout << "There is no loop in the linked list\n";
}

    // Find and return the node where the cycle begins
Node* findCycleStart() {
    Node* slow = head;
    Node* fast = head;

   bool isCycle = false;

   while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
        isCycle = true;
        break;
    }
   }
   if(!isCycle){
    return NULL;
   }
   slow = head;
   while(slow != fast){
    slow = slow->next;
    fast = fast->next;
   }
   cout<<slow->data;
   return slow;
}

};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    // Manually create a loop: last node points to second node
    //list.head->next->next->next->next->next = list.head->next;

    list.head->next->next->next->next->next = list.head->next->next;

    cout << "Displaying list (safe mode):\n";
    list.displaySafe();
    cout<<endl;
    list.detectCycle();  // 🔍 Test your loop detection here
    cout<<endl;
    list.findCycleStart();
    

    return 0;
}