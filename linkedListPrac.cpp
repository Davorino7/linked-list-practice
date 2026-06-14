#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;  // pointer to the next node — this IS the "link"
};

class LinkedList {
public:
    Node* head;  // pointer to the first node (nullptr if empty)

    LinkedList() {
        head = nullptr;  // start empty
    }
    // pushFront — add a new node at the BEGINNING
    // 1. create a new Node with "new Node"
    // 2. set its data
    // 3. point its "next" to the current head
    // 4. update head to point to this new node
    void pushFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // printList — walk through the list and print each value
    // use a pointer "current" starting at head,
    // loop while current != nullptr, print current->data,
    // then move current = current->next
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // search — return true if value exists in the list
    // same traversal pattern as printList, but check current->data == value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
        temp = temp->next;
        }
        return false;
    }
};

int main() {
    LinkedList list;

    list.pushFront(30);
    list.pushFront(20);
    list.pushFront(10);

    cout << "List contents: ";
    list.printList();

    cout << "\nSearching for 20: " << (list.search(20) ? "Found" : "Not found");
    cout << "\nSearching for 99: " << (list.search(99) ? "Found" : "Not found");

    return 0;
}