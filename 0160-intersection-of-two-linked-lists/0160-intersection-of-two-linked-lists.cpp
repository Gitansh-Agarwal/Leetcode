/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* collisionPoint(ListNode* t1, ListNode* t2, int d){
        while(d){
            --d;
            t2=t2->next;
        }
        
        while(t1 != t2){
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Using Hashing.
        //we can also use a map for hashing the nodes of first linked list .
        //TC=O(N1*O(1)) + O(N2*O(1)).
        //SC=O(N1).
//         unordered_set<ListNode*> st;
//         ListNode* temp=headA;
//         while(temp!=nullptr){
//             st.insert(temp);
//             temp=temp->next;
//         }
        
//         temp=headB;
//         while(temp!=nullptr){
//             if(st.find(temp) != st.end()){
//                 // return temp;
//                 break;
//             }
//             temp=temp->next;
//         }
//         return temp;
        
        
        
        
        //TC=O(N1+2*N2).
        //SC=O(1).
        ListNode* temp=headA;
        int N1=0;
        int N2=0;
        while(temp!=nullptr){
            N1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=nullptr){
            N2++;
            temp=temp->next;
        }
        
        if(N1 < N2){
            return collisionPoint(headA, headB, N2-N1);
        }
        else{
            return collisionPoint(headB, headA, N1-N2);
        }
        
        
        
        
    }
};