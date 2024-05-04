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
    ListNode* reverseList(ListNode* head) {
        //  ListNode *p=head,*q=nullptr,*r=nullptr;
        // while(p!=nullptr){
        //     r=q;
        //     q=p;
        //     p=p->next;
        //     q->next=r;
        // }
        // head=q;
        // return head;
        
        
        
        ListNode *prev=nullptr, *curr=nullptr, *front=head;
        while(front!=nullptr){
            prev=curr;
            curr=front;
            front=front->next;
            curr->next=prev;
        }
        head=curr;
        return head;
    }
};