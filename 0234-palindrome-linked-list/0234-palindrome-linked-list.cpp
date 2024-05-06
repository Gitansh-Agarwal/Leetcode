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
    bool isPalindrome(ListNode* head) {
        //Inefficient Solution.
//         ListNode *slow=head, *fast=head;
//         while(fast!=nullptr && fast->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         ListNode *prev=nullptr, *curr=nullptr, *front;
//         if(fast==nullptr){
//             front=slow;
//             ListNode* backHead;
//             while(front!=nullptr){
//                 prev=curr;
//                 curr=front;
//                 front=front->next;
//                 curr->next=prev;
//             }
//             backHead=curr;
//             ListNode* temp1=head;
//             ListNode* temp2=backHead;
//             while(temp2!=nullptr){
//                 if(temp1->val!=temp2->val){
//                     return false;
//                 }
//                 temp1=temp1->next;
//                 temp2=temp2->next;
//             }
            
//         }//return false;
//         //fast->next==nullptr
//         else{
//             prev=nullptr, curr=nullptr, front=slow->next;
//             ListNode *backHead;
//             while(front!=nullptr){
//                 prev=curr;
//                 curr=front;
//                 front=front->next;
//                 curr->next=prev;
//             }
//             backHead=curr;
//             ListNode *temp1=head;
//             ListNode *temp2=backHead;
//             while(temp2!=nullptr){
//                 if(temp1->val!=temp2->val){
//                     return false;
//                 }
//                 temp1=temp1->next;
//                 temp2=temp2->next;
//             }
//         }
//         return true;
        
        
        
        //IInd Method 
        //Copy all the elements in an array and then check for palindrome.
        vector<int> temp;
        ListNode* temp1=head;
        while(temp1!=nullptr){
            temp.push_back(temp1->val);
            temp1=temp1->next;
        }
        int left=0, right=temp.size()-1;
        while(left < right){
            if(temp[left] != temp[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};