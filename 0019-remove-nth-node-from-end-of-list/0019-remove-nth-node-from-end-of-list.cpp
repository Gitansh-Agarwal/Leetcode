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
        int length=0;
        ListNode* temp = head;
        while(temp!=nullptr){
            length++;
            temp=temp->next;
        }
        if(length == n){
            temp = head->next;
            delete head;
            return temp;
        }
        int breakPoint = length - n;
        breakPoint--;
        temp=head;
        while(breakPoint > 0){
            temp=temp->next;
            breakPoint--;
        }
        // if(temp == nullptr || temp->next == nullptr){
        //     return nullptr;
        // }
        ListNode* temp1 = temp->next;
       
        temp->next = temp->next->next;
        delete temp1;
        
        
        return head;
    }
};