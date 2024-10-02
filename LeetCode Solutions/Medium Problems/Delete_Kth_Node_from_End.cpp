/*
Delete Kth Node From End
Sample Input 1 :
6 3
1 2 3 4 5 6 
Sample Output 1 :
1 2 3 5 6
Explanation for Sample Input 1:
In the given linked list the node with data ‘4’ will be removed as this is the 3rd node from the end of the Linked List.
Sample Input 2 :
3 3
1 2 3
Sample Output 2 :
2 3
Constraints :
1 <= 'N' <= 10^3
1 <= 'K' <= 'N'
1 <= 'data' <= 10^3

Time Limit: 1 sec.
*/
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
int getLength(Node* head){
    int count =0;
    if(head==nullptr){
        return count ;
    }
    while(head!=nullptr){
        count++;
        head=head->next;
    }
    return count ;
}
Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int lastEnd = getLength(head) - K;
    Node* temp = head;
    Node* prev = nullptr;
    if(lastEnd==0){
        head=head->next;
        return head;
    }
    int i=0;
    while(i<lastEnd){
        prev=temp;
        i++;
        if(temp!=nullptr){
                    temp=temp->next;
        }
    }
    prev->next = temp->next;
    return head;

}
