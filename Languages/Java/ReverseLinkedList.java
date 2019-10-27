/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    static ListNode revH = null;
    public ListNode reverseList(ListNode head) {
       if(head==null)
           return null;
        revLL(head);
        return revH;
    }
    
    public  void revLL(ListNode head){
        
         if(head.next == null){
            revH = head;
             return;
           }
        
        revLL(head.next);
        head.next.next = head;
        head.next = null;
       
    }
    
}
