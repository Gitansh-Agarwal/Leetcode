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
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        ListNode *tempHead=head;
        unordered_set<ListNode*> st;
        while(tempHead!=nullptr && st.find(tempHead)==st.end()){
            st.insert(tempHead);
            tempHead=tempHead->next;
        }
        if(tempHead==nullptr){
            return false;
        }
        return true;
    }
};