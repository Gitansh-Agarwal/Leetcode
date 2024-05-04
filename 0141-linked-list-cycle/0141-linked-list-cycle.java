/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        
        //TC=O(N),
        //SC=O(N).
        // if(head==nullptr || head->next==nullptr){
        //     return false;
        // }
        // ListNode *tempHead=head;
        // unordered_set<ListNode*> st;
        // while(tempHead!=nullptr && st.find(tempHead)==st.end()){
        //     st.insert(tempHead);
        //     tempHead=tempHead->next;
        // }
        // if(tempHead==nullptr){
        //     return false;
        // }
        // return true;
        
        
        
        //Optimal Solution= Floyd's Tortoise and Hare Algorithm.
        //TC=O(N)
        //SC=O(1).
        if(head==null || head.next==null)
            return false;
        ListNode slow=head;
        ListNode fast=head;
        do{
            slow=slow.next;
            fast=fast.next;
            if(fast!=null)
                fast=fast.next;
        }while(slow!=fast && fast!=null);
        if(slow==fast)
            return true;
        return false;
    }
}