#include<iostream>
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
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // 1. Insert at beginning
   void insertAtBeg(int value){
    Node* newNode = new Node(value);  // Step 1: Create a new node with the given value

    if (head == nullptr) {            // Step 2: If the list is empty
        head = newNode;               // Make the new node the head
        return;                       // Done!
    }

    newNode->next = head;             // Step 3: Link new node to current head
    head = newNode;                   // Step 4: Update head to point to new node
}

    // 2. Insert at end
    void insertAtEnd(int value) {
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

    // 3. Delete from end
    void deleteFromEnd(){
    // Case 1: If the list is empty
    if(head == nullptr){
        cout << "List is empty";
        return;
    }

    // Case 2: If there's only one node
    if(head->next == nullptr){
        cout << head->data << " Deleted successfully\n";
        delete head;
        head = nullptr;
        return;
    }

    // Case 3: Traverse to the second-last node
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    // temp now points to second-last node
    cout << temp->next->data << " Deleted successfully\n";
    delete temp->next;       // delete the last node
    temp->next = nullptr;    // unlink it from the list
}

    // 4. Delete from beginning
    void deleteFromBeg(){

    // Case 1: If the list is empty
    if(head == nullptr){
        cout << "List is empty";
        return;
    }

    // Case 2: If there's only one node
    if(head->next == nullptr){
        cout << head->data << " Deleted successfully\n";
        delete head;
        head = nullptr;
        return;
    }

    // Case 3: More than one node
    Node* temp = head;         // Store current head
    head = head->next;         // Move head to the next node
    cout << temp->data << " Deleted successfully\n";
    delete temp;               // Delete the old head
}

    // Display list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};




int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeg(0);
    list.insertAtBeg(-10);
    list.insertAtBeg(-20);

    list.display();  // Output: 10 -> 20 -> 30 -> NULL

    list.deleteFromBeg();
    list.deleteFromBeg();
    list.display();
    list.deleteFromEnd();
    list.deleteFromEnd();
    list.display();

    return 0;
}