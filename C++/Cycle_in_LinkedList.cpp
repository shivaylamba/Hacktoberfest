#include <iostream>
#include <cmath>
using namespace std;

class node {
public:
    int value;
    node* next;

    node(int val){
        value = val;
        next = NULL;
    }
};

void makeCycle(node* head, int pos) { 
    //creates a cycle at the given position 'pos'
    //which means the 'next' of the last node will point towards the node at position 'pos'

    if(head == NULL) cout << "Imposibile to make cycle, list size = 0" << endl;

    int count = 0;
    node* temp;
    while(head->next != NULL) {
        if(count == pos) temp = head;
        head = head->next;
        count++;
    }

    head->next = temp;
}

bool detectCycle(node* head) { 
    // based on Floyd's Algorithm (Hare & Tortoise)

    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }

    return false;
}

void removeCycle(node* head) {
    //makes the 'next' of the last node as 'NULL'

    node* slow = head;
    node* fast = head;

    while (true)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) break;
    }

    fast = head;

    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = NULL;
}
