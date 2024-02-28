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
    int findBottomLeftValue(TreeNode* root) {
        //we are performing level order traversal and that is BFS only.
        deque<TreeNode*> dq;
        dq.push_back(root);
        TreeNode* node = dq.front();
        while(!dq.empty()){
            dq.pop_front();
            
            if(node->right)
                dq.push_back(node->right);
            if(node->left)
                dq.push_back(node->left);
            
            if(!dq.empty())
                node = dq.front();
            
        }
        return node->val;
    }
};