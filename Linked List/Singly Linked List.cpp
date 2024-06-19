#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = nullptr;
node* tail = nullptr;

void Insert_At_End() {
    node* ptr = new node();
    cout << "ENTER THE ELEMENT: ";
    cin >> ptr->data;
    ptr->next = nullptr;

    if (head == nullptr) {
        head = ptr;
        tail = ptr;
    } else {
        tail->next = ptr;
        tail = ptr;
    }

    cout << "Inserted Successfully." << endl;
    cout << "\t **************************************************" << endl;
}

void Insert_At_Front() {
    node* ptr = new node();
    cout << "ENTER THE ELEMENT: ";
    cin >> ptr->data;
    ptr->next = nullptr;

    if (head == nullptr) {
        head = ptr;
        tail = ptr;
    } else {
        ptr->next = head;
        head = ptr;
    }

    cout << "Inserted Successfully." << endl;
    cout << "\t **************************************************" << endl;
}

void Insert_At_Pos() {
    int loc;
    cout << "ENTER THE ELEMENT: ";
    cin >> ele;
    cout << "ENTER THE LOCATION: ";
    cin >> loc;

    if (loc < 1) {
        cout << "Invalid position. Position should be greater than 0." << endl;
        cout << "\t **************************************************" << endl;
        return;
    }

    if (loc == 1) {
        Insert_At_Front();
        return;
    }

    node* ptr = new node();
    ptr->data = ele;

    node* temp = head;
    node* prev = nullptr;

    for (int i = 1; i < loc && temp != nullptr; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr && loc > 1) {
        cout << "Position out of bounds." << endl;
        cout << "\t **************************************************" << endl;
        delete ptr; // Free the memory allocated for ptr
        return;
    }

    ptr->next = temp;
    if (prev != nullptr) {
        prev->next = ptr;
    } else {
        head = ptr; // Update head if inserting at the beginning
    }

    cout << "Inserted Successfully." << endl;
    cout << "\t **************************************************" << endl;
}

void Delete_At_Front() {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        cout << "\t **************************************************" << endl;
        return;
    }

    node* ptr = head;
    head = ptr->next;
    delete ptr;

    if (head == nullptr) {
        tail = nullptr; // If list becomes empty, update tail as well
    }

    cout << "Deleted Successfully" << endl;
    cout << "\t **************************************************" << endl;
}

void Delete_At_End() {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        cout << "\t **************************************************" << endl;
        return;
    }

    node* temp = head;
    node* prev = nullptr;

    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == nullptr) {
        delete temp;
        head = nullptr;
        tail = nullptr;
    } else {
        delete temp;
        prev->next = nullptr;
        tail = prev; // Update tail to previous node
    }

    cout << "Deleted Successfully" << endl;
    cout << "\t **************************************************" << endl;
}

void Delete_At_Pos() {
    int loc;
    cout << "ENTER THE LOCATION: ";
    cin >> loc;

    if (loc < 1) {
        cout << "Invalid position. Position should be greater than 0." << endl;
        cout << "\t **************************************************" << endl;
        return;
    }

    if (loc == 1) {
        Delete_At_Front();
        return;
    }

    node* temp = head;
    node* prev = nullptr;

    for (int i = 1; i < loc && temp != nullptr; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        cout << "\t **************************************************" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Deleted Successfully" << endl;
    cout << "\t **************************************************" << endl;
}

void Display() {
    int i = 1;
    node* temp = head;

    cout << "S.No\t Data\t Pointer" << endl;
    while (temp != nullptr) {
        cout << i << "\t" << temp->data << "\t" << temp->next << endl;
        temp = temp->next;
        i++;
    }

    cout << "\t **************************************************" << endl;
}

void Length() {
    int Count = 0;
    node* temp = head;

    while (temp != nullptr) {
        Count++;
        temp = temp->next;
    }

    cout << "Total no. of Nodes : " << Count << endl;
    cout << "\t **************************************************" << endl;
}

int main() {
    int ch;

    cout << "\n\n\t All Basic Features of Singly Linked List" << endl;
    cout << "\t **************************************************" << endl;

    do {
        cout << "\t 1) Insert at Front\t \t 2) Insert at End " << endl;
        cout << "\t 3) Insert at position\t \t 4) Delete at Front" << endl;
        cout << "\t 5) Delete at End\t \t 6) Delete at Position" << endl;
        cout << "\t 7) Length\t \t\t 8) Display" << endl;
        cout << "\t 9) Exit" << endl;
        cout << "\t ***************************************************\n ENTER YOUR CHOICE: ";
        cin >> ch;

        switch (ch) {
            case 1:
                Insert_At_Front();
                break;

            case 2:
                Insert_At_End();
                break;

            case 3:
                Insert_At_Pos();
                break;

            case 4:
                Delete_At_Front();
                break;

            case 5:
                Delete_At_End();
                break;

            case 6:
                Delete_At_Pos();
                break;

            case 7:
                Length();
                break;

            case 8:
                Display();
                break;

            case 9:
                exit(0);
                break;

            default:
                cout << "Invalid Input. Please enter the Number between 1 to 9 " << endl;
        }
    } while (ch != 0);

    return 0;
}
