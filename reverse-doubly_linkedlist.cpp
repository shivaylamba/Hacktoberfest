/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

// main code solution:

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* ptr1 = llist;
    DoublyLinkedListNode* ptr2 = llist->next;
    while(ptr1 != NULL) {
        ptr1->next = ptr1->prev;
        ptr1->prev = ptr2;
        if(ptr2 == NULL) {
            llist = ptr1;
            ptr1 = ptr2;
        }
        else {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
    }
    return llist;
}