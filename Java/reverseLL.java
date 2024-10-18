// 92. Reverse Linked List II
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(left==right|| head==null||head.next==null)
            return head;

        ArrayList<Integer> a=new ArrayList<>();
        ListNode temp=head;
        for(int i=1; i<left; i++)
            temp=temp.next;
        ListNode temp2=temp;
        for(int i=left; i<=right; i++){
            a.add(temp.val);
            temp=temp.next;
        }
        for(int j=a.size()-1; j>=0; j--){
            temp2.val=a.get(j);
            temp2=temp2.next;
        }
        return head;

    }
}
