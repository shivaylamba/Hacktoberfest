#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
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
        temp->data = info;
        temp->next = start;
        start = temp;
    } else {
        while (traverse->next != NULL) {
        traverse = traverse->next;
        }
        traverse->next = temp;
    }
}

void reverse() {
    Node *current_node, *previous_node, *next_node;
    current_node = start;
    previous_node = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    start = previous_node;
}

int main()
{
    int N;
    cout << "\nPROGRAM TO  REVERSE A LINKED LIST\n";
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
    reverse();
    display();
    
    return 0;
}