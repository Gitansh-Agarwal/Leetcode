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
        //Brute force Solution.
        //TC=O(2N), SC=O(N){stack space}.
        //  ListNode *p=head,*q=nullptr,*r=nullptr;
        // while(p!=nullptr){
        //     r=q;
        //     q=p;
        //     p=p->next;
        //     q->next=r;
        // }
        // head=q;
        // return head;
        
        
        //TC=O(N), SC=O(1).
        //Using three Pointers
        // ListNode *prev=nullptr, *curr=nullptr, *front=head;
        // while(front!=nullptr){
        //     prev=curr;
        //     curr=front;
        //     front=front->next;
        //     curr->next=prev;
        // }
        // head=curr;
        // return head;
        
        
        //TC=O(N), SC=O(N){recursion stack space.}
        //Using Recursion.
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next=head;
        head->next=nullptr;
        
        return newHead;
        
    }
    ListNode* doubleIt(ListNode* head) {
        head  = reverseList(head);
        
        ListNode* curr=head;
        ListNode* prev=nullptr;
        int carry=0;
        
        while(curr!=nullptr){
            int newValue=curr->val*2 + carry;
            curr->val=newValue%10;

            if(newValue>=10){
                carry=1;
            }
            else{
                carry=0;
            }
            prev=curr;
            curr=curr->next;
        
        }
        
        if(carry==1){//carry!=0
            prev->next = new ListNode(carry);
        }
        
        return reverseList(head);
    }
};