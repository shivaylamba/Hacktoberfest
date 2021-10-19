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

void insertAtPosition(int element_at_pos, int position) {
    Node *temp = new Node();
    Node *traverse = start;
    int i = 1;
    temp->data = element_at_pos;
    if (position == 1) {
        temp->next = start;
        start = temp;
        return;
    }
    while (i < position-1) {
        traverse = traverse->next;
        i++;
    }
    temp->next = traverse->next;
    traverse->next = temp;
}

int main()
{
    int N;
    cout << "\nPROGRAM TO  INSERT A NODE AT THE SPECIFIC POSITION\n";
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
    
    cout << "Enter the element to enter at specific position : ";
    int specific_element, index;
    cin >> specific_element;
    cout << "Enter the position : ";
    cin >> index;
    insertAtPosition(specific_element, index);
    display();
    
    return 0;
}