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
    private ListNode reverseLL(ListNode head){
        ListNode temp=head, prev=null;
        while(temp!=null){
            ListNode front=temp.next;
            temp.next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    private ListNode addTwoNumbers1(ListNode l1, ListNode l2) 
    {
        ListNode temp1=l1;
        ListNode temp2=l2;
        ListNode dummy=new ListNode(-1);
        ListNode current=dummy;
        int carry=0;
        while(temp1!=null || temp2!=null){
           int sum=carry;
           if(temp1!=null){
            sum+=temp1.val;
            temp1=temp1.next;
           }
           if(temp2!=null){
            sum+=temp2.val;
            temp2=temp2.next;
           }
           current.next=new ListNode(sum%10);
           carry=sum/10;
           current=current.next;
        }
        if(carry>0)
            current.next=new ListNode(carry);
      
        return dummy.next;
        
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            l1=reverseLL(l1);
            l2=reverseLL(l2);
            return reverseLL(addTwoNumbers1(l1, l2));
    }
}
