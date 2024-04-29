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
    void deleteNode(ListNode* node) {
        
        ListNode* nextNode=node->next;
        
        //step1: Assign/Copy the value at nextNode to node.
        node->val=nextNode->val;
        
        //step2: Make node point on node pointed by nextNode.
        node->next=nextNode->next;
        
        //step3: Remove the link b/w nextNode and its Next i.e., make nextNode->next=nullptr.
        nextNode->next=NULL;
        
        //step4: Remove/Delete the nextNode from memory.
        delete(nextNode);
        
    }
};