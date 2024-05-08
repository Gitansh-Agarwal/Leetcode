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
    // ListNode* middNode(ListNode* head){
    //     ListNode *slow=head, *fast=head->next;
    //     while(fast!=nullptr && fast->next!=nullptr){
    //         slow=slow->next;
    //         fast=fast->next->next;
    //     }
    //     return slow;
    // }
    //OR Midlle node m1(even length LL) or simply middle node in LL can also be find out using the below method.
    ListNode* middNode(ListNode* head){
        ListNode *slow=head, *fast=head;
        while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    
    ListNode* merge2SortedLL(ListNode* leftHead, ListNode* rightHead){
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
    ListNode* sortList(ListNode* head) {
//         ListNode* temp=head;
//         vector<int> tempVec;
//         while(temp!=nullptr){
//             tempVec.push_back(temp->val);
//             temp=temp->next;
//         }
        
//         sort(tempVec.begin(), tempVec.end());
        
//         temp=head;
//         int i=0;
//         while(temp!=nullptr){
//             temp->val=tempVec[i++];
//             temp=temp->next;
//         }
//         return head;
        
        
        
        //Method 2
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        ListNode *middleNode = middNode(head);
        ListNode *rightHead=middleNode->next;
        middleNode->next=nullptr;
        ListNode *leftHead=head;
        
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        
        return merge2SortedLL(leftHead, rightHead);
    }
};