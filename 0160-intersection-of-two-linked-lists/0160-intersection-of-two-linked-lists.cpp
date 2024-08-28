/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include<stack>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> stk1,stk2;
        ListNode *p1=headA,*p2=headB;
        while(p1!=nullptr){
            stk1.push(p1);
            p1=p1->next;
        }
        while(p2!=nullptr){
            stk2.push(p2);
            p2=p2->next;
        }
        ListNode* intersect=nullptr;
        // if(!stk1.empty() && !stk2.empty()){
            
        
            while(!stk1.empty() && !stk2.empty() && stk1.top()==stk2.top()){
                intersect=stk1.top();
                stk1.pop();
                stk2.pop();
            }
            return intersect;
        // }
        // return nullptr;
    }
};