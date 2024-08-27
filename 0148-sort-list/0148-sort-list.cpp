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
private:
    ListNode* findMiddle(ListNode* head){
        ListNode *slow=head, *fast=head;
        
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergedList(ListNode* leftHead, ListNode* rightHead){
        ListNode *mergeHead=nullptr, *temp=nullptr;
        while(leftHead!=nullptr && rightHead!=nullptr){
            if(leftHead->val < rightHead->val){
                if(mergeHead==nullptr){
                    mergeHead=leftHead;
                    temp=leftHead;
                }
                else{
                    temp->next=leftHead;
                    temp=temp->next;
                }
                leftHead=leftHead->next;
            }
            else{
                if(mergeHead==nullptr){
                    mergeHead=rightHead;
                    temp=rightHead;
                }
                else{
                    temp->next=rightHead;
                    temp=temp->next;
                }
                rightHead=rightHead->next;
            }
        }
        if(leftHead==nullptr){
            temp->next=rightHead;
        }
        else{
            temp->next=leftHead;
        }
        return mergeHead;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        
        ListNode* middleNode=findMiddle(head);
        ListNode* rightHead=middleNode->next;
        middleNode->next=nullptr;
        ListNode* leftHead=head;
        
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        
        return mergedList(leftHead, rightHead);
    }
};