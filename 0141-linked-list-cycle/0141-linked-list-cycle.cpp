/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
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
        if(head==nullptr || head->next==nullptr)
            return false;
        ListNode *slow=head;
        ListNode *fast=head;
        do{
            slow=slow->next;
            fast=fast->next;
            if(fast)
                fast=fast->next;
        }while(slow!=fast && fast!=nullptr);
        if(slow==fast)
            return true;
        return false;
    }
};