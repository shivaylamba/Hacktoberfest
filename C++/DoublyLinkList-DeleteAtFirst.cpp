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

void deleteAtFirst() {
    Node *temp;
    if (start->next == NULL) {
        temp = start;
        start = NULL;
        free(temp);
    } else {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
    }
}

int main()
{
    int N;
    cout << "\nPROGRAM TO  DELETE A NODE AT THE FIRST POSITION IN DOUBLY LINK LIST\n";
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
    deleteAtFirst();
    display();
    
    return 0;
}
