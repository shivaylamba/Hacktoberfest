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

void reverse(Node* temp) {
    if (temp->next == NULL) {
        start = temp;
        return;
        
    }
    reverse(temp->next);
    Node* previous = temp->next;
    previous->next = temp;
    temp->next = NULL;
}

int main()
{
    int N;
    cout << "\nPROGRAM TO  REVERSE THE LIST USING RECURSION\n";
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
    
    cout << "Original List : ";
    display();
    cout << "\nList After Reversal : ";
    reverse(start);
    display();
    
    
    return 0;
}