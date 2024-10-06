#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *head, *tail, *temp, *ptr;

void Insert_At_Front();
void Insert_At_End();
void Insert_At_Pos();
void Delete_At_Front();
void Delete_At_End();
void Delete_At_Pos();
void Display();
void Length();
int ele;

int main() {
    int ch;
    cout << "\n\n\t All Basic Features of Doubly Linked List" << endl;
    cout << "\t **************************************************" << endl;

    do {
        cout << "\t 1) Insert at Front\t \t 2) Insert at End " << endl;
        cout << "\t 3) Insert at position\t \t 4) Delete at Front" << endl;
        cout << "\t 5) Delete at End\t \t 6) Delete at Position" << endl;
        cout << "\t 7) Length\t \t\t 8) Display" << endl;
        cout << "\t 9) Exit" << endl;
        cout << "\t ***************************************************\n ENTER YOUR CHOICE: " << endl;
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
//-------------------------------------------------------------
void Insert_At_End() {
    ptr = (struct node*) malloc(sizeof(struct node));
    cout << "ENTER THE ELEMENT" << endl;
    cin >> ele;
    ptr->data = ele;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL) {
        head = ptr;
        tail = ptr;
        cout << "Inserted Successfully." << endl;
        cout << "\t **************************************************" << endl;
    } else {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
        cout << "Inserted Successfully." << endl;
        cout << "\t **************************************************" << endl;
    }
}
//--------------------------------------------------------------
void Insert_At_Front() {
    ptr = (struct node*) malloc(sizeof(struct node));
    cout << "ENTER THE ELEMENT" << endl;
    cin >> ele;
    ptr->data = ele;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL) {
        head = ptr;
        tail = ptr;
        cout << "Inserted Successfully." << endl;
        cout << "\t **************************************************" << endl;
    } else {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        cout << "Inserted Successfully." << endl;
        cout << "\t **************************************************" << endl;
    }
}
//-------------------------------------------------------------
void Insert_At_Pos() {
    int loc;
    cout << "ENTER THE ELEMENT" << endl;
    cin >> ele;
    cout << "ENTER THE LOCATION" << endl;
    cin >> loc;

    if (loc == 1) {
        Insert_At_Front();
    } else {
        ptr = (struct node*) malloc(sizeof(struct node));
        ptr->data = ele;
        temp = head;

        for (int i = 1; i < loc - 1; i++) {
            temp = temp->next;
        }

        ptr->next = temp->next;
        ptr->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = ptr;

        temp->next = ptr;

        cout << "Inserted Successfully." << endl;
        cout << "\t **************************************************" << endl;
    }
}
//-------------------------------------------------------------
void Delete_At_Front() {
    if (head == NULL) {
        cout << "List is Empty" << endl;
        cout << "\t **************************************************" << endl;
    } else {
        ptr = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        free(ptr);
        cout << "Deleted Successfully" << endl;
        cout << "\t **************************************************" << endl;
    }
}
//-------------------------------------------------------------
void Delete_At_End() {
    if (head == NULL) {
        cout << "List is Empty" << endl;
        cout << "\t **************************************************" << endl;
    } else {
        temp = tail;
        tail = tail->prev;

        if (tail != NULL)
            tail->next = NULL;

        free(temp);
        cout << "Deleted Successfully" << endl;
        cout << "\t **************************************************" << endl;
    }
}
//-------------------------------------------------------------
void Delete_At_Pos() {
    int loc;
    cout << "ENTER THE LOCATION" << endl;
    cin >> loc;

    if (loc == 1) {
        Delete_At_Front();
    } else {
        temp = head;
        for (int i = 1; i < loc; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
        cout << "Deleted Successfully" << endl;
        cout << "\t **************************************************" << endl;
    }
}
//-------------------------------------------------------------
void Display() {
    int i = 1;
    temp = head;
    cout << "S.No\t Data\t Pointer\t Prev Pointer" << endl;
    while (temp != NULL) {
        cout << i << "\t" << temp->data << "\t" << temp->next << "\t" << temp->prev << endl;
        temp = temp->next;
        i++;
    }
    cout << "\t ***********************************************" << endl;
}
//-------------------------------------------------------------
void Length() {
    int Count = 0;
    temp = head;
    while (temp != NULL) {
        Count++;
        temp = temp->next;
    }
    cout << "Total no. of Nodes: " << Count << endl;
    cout << "\t ***********************************************" << endl;
}
