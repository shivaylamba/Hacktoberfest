#include<iostream>
using namespace std;
class Node
{
        public:
        char data;
        Node *next;
        Node(char info)
{
        data=info;
        next=NULL;
}
};
class List
{
        public:
        Node *head;
        int c;
        Node *tail;
List()
{
        head=NULL;
        c=0;
        tail=NULL;
}
List* createList()
{

        List *new1=new List;
        return new1;
        }


void insert(char val)
        {
        Node * new_node = new Node(val);
        if (head == NULL)
        {head = new_node;
        tail=new_node;
        }
        else
        {
        tail->next = new_node;
        tail = new_node;
        }
}
// function for checking vowel
bool isVowel(char x)
{
    return (x == 'a' || x == 'e' || x == 'i'|| x == 'o' || x == 'u' || x == 'A'|| x == 'E' || x == 'I' || x == 'O'|| x == 'U');
}

// Function to remove the vowels Node
void removeVowels()
{
    // Node pointing to head Node
    Node* ptr = head;

    // Case 1 : Remove the trailing vowels
    while (ptr != NULL) {

        // If current Node is a vowel node then move the pointer to next node
        if (isVowel(ptr->data))
            ptr = ptr->next;

        // Else break if a consonant node is found
        else
            break;
    }

    // This prev node used to link prev consonant to next consonant after vowels
    Node* prev = ptr;

    // Head points to the first consonant of the linked list
    head = ptr;

    ptr = ptr->next;

    // Case 2: If vowels found in between of the linked list
    while (ptr != NULL) {

        // If current node is vowel
        if (isVowel(ptr->data)) {

            // Move ptr to the next node
            ptr = ptr->next;

            // Check for vowels occurring continuously
            while (ptr != NULL) {

                // If ptr is a vowel move to next pointer
                if (isVowel(ptr->data)) {
                    ptr = ptr->next;
                }
                // Else break if consonant found
                else
                    break;
            }

            // Case 3: If we have ending vowels then link the prev consonant to NULL
            if (ptr == NULL) {
                prev->next = NULL;
                break;
            }

            // Case 2: change the next link of prev to current consonant pointing to ptr
            else {
                prev->next = ptr;
            }
        }

        // Move prev and ptr to next for next iteration
        prev = prev->next;
        ptr = ptr->next;
    }
}


void display()
{
            Node* temp = head;
            while(temp != NULL)
            {
            cout << temp->data << " ";
            temp = temp->next;
            }
            cout << endl;
}
};
int main()
{
        List l;
        string n;
        // inserting elements
        cout<<"Enter any Name : ";
        cin>>n;
        for(int i=0;i<n.size();i++)
        {
        l.insert(n[i]);
        }
        cout << "Current Linked List: ";
        l.display();
        l.removeVowels();
        cout << "Linked List after removing vowels: ";
        l.display();
}
