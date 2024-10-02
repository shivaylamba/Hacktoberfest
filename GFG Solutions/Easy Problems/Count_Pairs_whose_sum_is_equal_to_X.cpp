/*
Count Pairs whose sum is equal to X
Given two linked list head1 and head2 with distinct elements, determine the count of all distinct pairs from both lists whose sum is equal to the given value x.

Note: A valid pair would be in the form (x, y) where x is from first linked list and y is from second linked list.

Example 1:

Input:
head1 = 1->2->3->4->5->6
head2 = 11->12->13
x = 15
Output: 3
Explanation: There are total 3 pairs whose sum is 15 : (4,11) , (3,12) and (2,13)
Example 2:

Input:
head1 = 7->5->1->3
head2 = 3->5->2->8
x = 10
Output: 2
Explanation: There are total 2 pairs whose sum is 10 : (7,3) and (5,5)
Your Task:
You only need to implement the given function countPairs() that take two linked list head1 and head2 and return the count of distinct pairs whose sum is equal to x.

Expected Time Complexity: O(length(head1)+lenght(head2)).
Expected Auxiliary Space: O(length(head1)) or O(length(head2)).

Constraints:
1<=length(head1), lenght(head2)<=105
1 <= Value of elements of  linked lists <= 109
1<= x <= 109
Note : All elements in each linked list are unique.
*/
/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
/*
Method 3 (Hashing): Hash table is implemented using unordered_set in C++. 
We store all first linked list elements in hash table. For elements of 
second linked list, we subtract every element from x and check the result 
in hash table. If result is present, we increment the count.
Time Complexity: O(n1 + n2) 
Auxiliary Space: O(n1), hash table should be created of the array having 
                 smaller size so as to reduce the space complexity.
*/
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        int count = 0 ;
        unordered_set<int> s;
        // insert all the elements of 1st list
    // in the hash table(unordered_set 's')
        while(head1!=nullptr){
            s.insert(head1->data);
            head1=head1->next;
        }
         // for each element of 2nd list
        while(head2!=nullptr){
            // find (x - head2->data) in 's'
            if(s.find(x-head2->data) != s.end()){
                count++;
            }
            // move to next node
            head2=head2->next;
        }
        // required count of pairs
        return count;
    }
};
/*
Method 2 (Sorting): Sort the 1st linked list in ascending order and the 
2nd linked list in descending order using merge sort technique. Now traverse 
both the lists from left to right in the following way:
Time Complexity: O(n1*logn1) + O(n2*logn2) 
Auxiliary Space: O(1) 

Sorting will change the order of nodes. If order is important, then copy of the 
linked lists can be created and used.
*/
// Brute Approach
// Time Complexity O(n^2)
// Space Complexity O(1)
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        int count = 0 ;
        Node* p1= head1 , *p2 = head2;
        for(p1 = head1 ; p1!=nullptr ; p1 = p1->next){
            for(p2 = head2 ; p2!=nullptr ; p2 = p2->next){
            if(p1->data + p2->data == x){
                count++;
            }
        }
        }
        
        return count;
    }
};