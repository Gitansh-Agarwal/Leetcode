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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        
        function<void(TreeNode* )> traverse = [&](TreeNode* node) -> void{
            if(!node)
                return;
            
            if(node->val >= low && node->val <= high){
                ans+=node->val;
                traverse(node->left);
                traverse(node->right);
            }
            else if(node->val < low){
                traverse(node->right);
            }
            else{
                traverse(node->left);
            }
        };
        
        traverse(root);
        
        return ans;
    }
};