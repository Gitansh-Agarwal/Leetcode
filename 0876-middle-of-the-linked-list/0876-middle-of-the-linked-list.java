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
    public ListNode middleNode(ListNode head) {
        
        //TC=O(N+N/2).
        
        //Finding the length of the linked list
//         int cnt=0;
//         ListNode temp=head;
//         while(temp!=null){
//             cnt++;
//             temp=temp.next;
//         }
        
//         //Finding the middle node based on the length of the linked list.
//         int middNode=(cnt/2)+1;
//         temp=head;
//         while(temp!=null){
//             middNode--;
//             if(middNode==0){
//                 break;
//             }
//             temp=temp.next;
//         }
//         return temp;
        
        
        
        //Optimal Code
        //TC=O(N/2).
        ListNode slow=head, fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
}