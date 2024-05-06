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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
            return head;
        }
        
        ListNode *first=head, *second=head->next;
        ListNode *temp1=first, *temp2=second;
        ListNode *temp=second->next;
        bool flag=true;
        while(temp!=nullptr){
            if(flag){
                temp1->next=temp;
                temp1=temp1->next;
                flag=false;
            }
            else{
                temp2->next=temp;
                temp2=temp2->next;
                flag=true;
            }
            temp=temp->next;
        }
        temp2->next=nullptr;
        temp1->next=second;
        
        return first;
    }
};