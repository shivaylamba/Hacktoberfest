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

void deleteAtLast() {
    Node *traverse = start;
    Node *temp;
    if (start == NULL) {
        cout << "\nList is already Empty!\n";
    } else if (start->next == NULL) {
        Node *temp = start;
        start = NULL;
        free(temp);
    } else {
        while (temp->next != NULL) {
        traverse = traverse->next;
        temp = traverse->next;
        }
        traverse->next = NULL;
        free(temp);
    }
}

int main()
{
    int N;
    cout << "\nPROGRAM TO  DELETE A NODE AT THE LAST POSITION\n";
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
    
    cout << "List after Deletion : ";
    deleteAtLast();
    display();
    
    return 0;
}