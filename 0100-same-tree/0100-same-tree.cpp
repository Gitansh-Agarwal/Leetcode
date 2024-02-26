/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //for below input the below method is giving wrong answer.
//     [1,2]
// [1,null,2]
//     vector<int> preorderTraversal(TreeNode* node, vector<int>& temp){
//         if(!node)
//             return {};
    
//         static vector<int> temp1;
//         temp1.push_back(node->val);
//         preorderTraversal(node->left, temp1);
//         preorderTraversal(node->right, temp1);
//         return temp;
//     }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // vector<int> temp = preorderTraversal(p, temp);
        // vector<int> temp2 = preorderTraversal(q, temp2);
        // if(temp==temp2)
        //     return true;
        // return false;
        
        
        
        //TC=O(N)
        //SC=O(1){Auxiliary Space}, O(depth/height of tree){Recursion Stack Space}
        if(!p and !q)
            return true;
        if(!p or !q or p->val!=q->val)
            return false;
        
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};