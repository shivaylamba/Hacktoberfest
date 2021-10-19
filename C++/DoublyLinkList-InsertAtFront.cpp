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

void insertAtFront(int info) {
    Node *temp = new Node();
    temp->data = info;
    if (start == NULL) {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
    } else {
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}

int main()
{
    int N;
    cout << "\nPROGRAM TO  INSERT A NODE AT THE BEGINNING IN DOUBLY LINK LIST\n";
    cout << "How many elements do you want to enter : ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        int element;
        cout << "Enter the element : ";
        cin >> element;
        insertAtFront(element);
        cout << "List after insertion : ";
        display();
        cout << "\n";
    }

    return 0;
}
