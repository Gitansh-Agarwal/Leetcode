/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Brute Force Solution
        //TC=O(length) + O(length-n) , extra SC=O(1).
//         int length=0;
//         ListNode* temp = head;
//         while(temp!=nullptr){
//             length++;
//             temp=temp->next;
//         }
//         if(length == n){
//             temp = head->next;
//             delete head;
//             return temp;
//         }
//         int breakPoint = length - n;
//         breakPoint--;
//         temp=head;
//         while(breakPoint > 0){
//             temp=temp->next;
//             breakPoint--;
//         }
//         ListNode* temp1 = temp->next;
//         temp->next = temp->next->next;
//         delete temp1;
        
//         return head;
        
        
        
        //Optimal Solution
        //TC=O(length), extra SC=O(1).
        ListNode* fast=head;
        for(int i=0; i<n; i++){
           fast=fast->next; 
        }
        if(fast == nullptr){
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        ListNode* slow = head;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
        
    }
};