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
    public ListNode reverseList(ListNode head) {
        //TC=O(N), SC=O(1).
        //Using three Pointers
        // ListNode prev=null, curr=null, front=head;
        // while(front!=null){
        //     prev=curr;
        //     curr=front;
        //     front=front.next;
        //     curr.next=prev;
        // }
        // head=curr;
        // return head;
        
        
        //TC=O(N), SC=O(N){recursion stack space.}
        //Using Recursion.
        if(head==null || head.next==null){
            return head;
        }
        ListNode newHead = reverseList(head.next);
        ListNode front = head.next;
        front.next=head;
        head.next=null;
        
        return newHead;
    }
}