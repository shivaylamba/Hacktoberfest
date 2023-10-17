#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Function to delete a node with a given value
    void deleteNode(int data) {
        Node* current = head;
        while (current) {
            if (current->data == data) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to search for a node with a given value
    bool search(int data) {
        Node* current = head;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to print the linked list
    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "Original list: ";
    list.printList();

    list.deleteNode(2);
    std::cout << "List after deleting 2: ";
    list.printList();

    list.insert(4);
    std::cout << "List after inserting 4: ";
    list.printList();

    bool found = list.search(3);
    if (found) {
        std::cout << "Node with value 3 found in the list." << std::endl;
    } else {
        std::cout << "Node with value 3 not found in the list." << std::endl;
    }

    return 0;
}
