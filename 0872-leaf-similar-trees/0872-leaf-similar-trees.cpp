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
    
    vector<int> preorder(TreeNode* root1, vector<int>& vec1){
        // if(!root1)
        //     return vec1;
        // if(!root1->left && !root1->right){
        //     vec1.push_back(root1->val);
        //     return vec1; 
        // }
        // if(!root1->left){
        //     preorder(root1->right, vec1);
        // }
        // else if(!root1->right){
        //     preorder(root1->left, vec1);
        // }
        // else{
        //     preorder(root1->left, vec1);
        //     preorder(root1->right, vec1);
        // }
        // return vec1;
        
        // OR
        
        if(!root1)
            return vec1;
        if(!root1->left && !root1->right){
            vec1.push_back(root1->val);
            return vec1; 
        }
        if(root1->left != nullptr){
            preorder(root1->left, vec1);
        }
        if(root1->right != nullptr){
            preorder(root1->right, vec1);
        }
        
        return vec1;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // vector<int> vec1;
        // vector<int> vec2;
        // vec1= preorder(root1, vec1);
        // vec2 = preorder(root2, vec2);
        // if(vec1 == vec2)
        //     return true;
        // return false;
        
        //OR
        //Using deque or simply using queue
        deque<int> leaves;
        bool ans = 1;
        
        function<void(TreeNode*, bool)> traverse = [&](TreeNode* node, bool push){
            if(!node)
                return;
            
            if(!(node->left) && !(node->right)){
                if(push){
                    leaves.push_back(node->val);
                }
                else{
                    if(leaves.empty() or node->val != leaves.front())
                        ans = 0;
                    
                    if(!leaves.empty())
                        leaves.pop_front();
                }
            }
            
            traverse(node->left, push);
            traverse(node->right, push);
        };
        
        traverse(root1, 1);
        traverse(root2, 0);
        
        return (ans and leaves.empty());
    }
};