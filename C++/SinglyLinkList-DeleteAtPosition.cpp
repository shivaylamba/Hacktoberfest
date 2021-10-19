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

void deleteAtPosition(int position) {
    Node *temp, *traverse = start;
    int i = 1;
    if (position == 1) {
        temp = start;
        start = start->next;
        free(temp);
    } else {
        while (i < position-1) {
            traverse = traverse->next;
            i++;
        }
        temp = traverse->next;
        traverse->next = temp->next;
        free(temp);
    }
}

int main()
{
    int N;
    cout << "\nPROGRAM TO  DELETE A NODE AT THE SPECIFIC POSITION\n";
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
    
    int  index;
    cout << "Enter the position : ";
    cin >> index;
    deleteAtPosition(index);
    display();
    
    return 0;
}