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
    string tree2str(TreeNode* root) {
        
        if(!root)
            return "";
        
        string resultantString = to_string(root->val);
        if(root->left && root->right){
            
            resultantString = resultantString + '(';
            resultantString = resultantString + tree2str(root->left);
            resultantString = resultantString + ')';
            
            resultantString = resultantString + '(';
            resultantString = resultantString + tree2str(root->right);
            resultantString = resultantString + ')';
        }
        else if(root->left){
            
            resultantString = resultantString +'(';
            resultantString = resultantString + tree2str(root->left);
            resultantString = resultantString + ')';
            
        }
        else if(root->right){
            
            resultantString = resultantString + "()(";
            resultantString = resultantString + tree2str(root->right);
            resultantString = resultantString + ')';
            
        }
        return resultantString;
    }
};