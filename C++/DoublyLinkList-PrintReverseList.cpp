#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

struct Node *start = NULL;

void display() {
    Node* temp = start;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtLast(int info) {
    Node *temp = new Node();
    Node *traverse = start;
    temp->data = info;
    temp->next = NULL;
    if (start == NULL) {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
    } else {
        while (traverse->next != NULL) {
        traverse = traverse->next;
        }
        traverse->next = temp;
        temp->prev = traverse;
    }
}

void reversePrint() {
    Node *temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != start) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << start->data;
}

int main()
{
    int N;
    cout << "\nPROGRAM TO REVERSE PRINT THE DOUBLY LINK LIST\n";
    cout << "How many elements do you want to enter : ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        int element;
        cout << "Enter the element : ";
        cin >> element;
        insertAtLast(element);
        cout << "List after insertion : ";
        display();
        cout << "\n";
    }
    
    cout << "List After Reversal : ";
    reversePrint();

    return 0;
}