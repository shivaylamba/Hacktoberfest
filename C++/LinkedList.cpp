#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) //constr
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void printtemp(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
Node *takeInput()
{
    int data;
    cout << "Enter Data Values\n";
    cin >> data;
    Node *head = NULL; //ll is empty
    Node *tail = NULL; //also ll is empty

    while (data != -1)
    {
        //creating LL
        Node *n = new Node(data);
        //checking 1st Node
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n; //inserting at tail
            tail = n;       //or tail=tail->next;
        }
        cin >> data;
    }
    return head;
}
int main()
{
    //In terminal just write the int values and to end the linked list, enter -1

    Node *head = takeInput();

    printtemp(head);
}
