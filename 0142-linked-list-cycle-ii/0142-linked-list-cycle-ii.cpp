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
    ListNode *detectCycle(ListNode *head) {
        //TC=O(N*2*logN) or (N*2*1)
        //SC=O(N).
//         unordered_set<ListNode*> st;
        
//         if(head==nullptr || head->next==nullptr){
//             return nullptr;
//         }
        
//         ListNode *temp=head;
//         while(temp!=nullptr){
//             if(st.find(temp)!=st.end()){
//                 break;
//             }
//             st.insert(temp);
//             temp=temp->next;
//         }
//         return temp;
        
        
        
        //Optimal Method
        //TC=O(N).
        //SC=O(1).
        ListNode *slow=head, *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;//Both fast and slow are standing at the starting point of loop in the linked list.
            }
        }
        return nullptr;
    }
};