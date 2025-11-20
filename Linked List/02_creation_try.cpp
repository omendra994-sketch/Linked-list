#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList(){
        head  = nullptr;
    }

    //  Insert at end
    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(head==nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next=newNode;

    }

    // Display
    void display(){
        if(head == nullptr){
            cout<<"List is empty!";
            return;
        }
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout << "NULL\n";
    }

   // Insert at position
void insertAtPos(int value, int pos){
    Node* newNode = new Node(value);

    // Case 1: Insert at beginning
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Traverse to (pos - 1)th node
    Node* temp = head;
    int i = 1;
    while (i < pos - 1 && temp != nullptr) {
        temp = temp->next;
        i++;
    }

    // Case 3: Invalid position
    if (temp == nullptr) {
        cout << "Invalid position!";
        delete newNode;
        return;
    }

    // Case 4: Insert in middle or end
    newNode->next = temp->next;
    temp->next = newNode;
}


    // Delete from Position
void deleteFromPos(int pos) {
    if (head == nullptr) {
        cout << "List is empty!";
        return;
    }

    // Case 1: Delete from beginning
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted successfully\n";
        delete temp;
        return;
    }

    // Traverse to the node just before the one to delete
    Node* temp = head;
    int i = 1;
    while (i < pos - 1 && temp->next != nullptr) {
        temp = temp->next;
        i++;
    }

    // If position is invalid (too large)
    if (temp->next == nullptr) {
        cout << "Invalid position!";
        return;
    }

    // Delete the node at position
    Node* delNode = temp->next;
    temp->next = delNode->next;
    cout << delNode->data << " deleted successfully\n";
    delete delNode;
}

    };

    
int main(){
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtPos(15,2);
    list.insertAtPos(25,4);
    list.insertAtPos(35,6);

    list.display();

    list.deleteFromPos(1);
    list.display();
    list.deleteFromPos(10);

    return 0;
}