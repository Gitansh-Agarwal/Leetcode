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
    vector<vector<int>> levelOrder(TreeNode* root) {
// //         int level=0;
// //         queue<pair<TreeNode*, int>> q;
// //         q.push({root, 1});
        
// //         vector<vector<int>> result;
        
// //         vector<int> elementsAtCurrLevel;
// //         while(!q.empty()){
// //             TreeNode* currNode = q.front().first;
// //             int node  = (q.front().first)->val;
// //             int currLevel = q.front().second;
// //             q.pop();
            
// //             elementsAtCurrLevel.push_back(node);
            
// //             if(currLevel>level){
// //                 result.push_back(elementsAtCurrLevel);
// //                 elementsAtCurrLevel.clear();
// //                 level++;
// //             }
            
// //             if(currNode->left!=nullptr){
// //                 q.push({currNode->left, currLevel+1});
// //                 cout<<currLevel<<endl;
// //             }
// //             if(currNode->right!=nullptr){
// //                 q.push({currNode->right, currLevel+1});
// //                 cout<<currLevel<<endl;
// //             }
            
            
            
// //         }
// //         return result;
        
        
        
        
//         vector<vector<int>> result;
//         if(!root) return result;
        
//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(NULL);
//         vector<int> cur_vec;
//         while(!q.empty()){
//             TreeNode* t = q.front();
//             q.pop();
            
//             if(t == NULL){
//                 result.push_back(cur_vec);
//                 cur_vec.resize(0);
//                 if(q.size()>0){
//                     q.push(NULL);
//                 }
//             }
//             else{
                
//             cur_vec.push_back(t->val);
//             if(t->left) {
//                 q.push(t->left);
//             }
//             if(t->right) {
//                 q.push(t->right);
//             }
        
            
//     }
              
//         }
//         return result;
        
        
        
        
        
        if (root == nullptr) {
        return {}; // Handle the edge case of an empty tree.
    }
    
    queue<pair<TreeNode*, int>> q; // Queue to store nodes along with their level.
    q.push({root, 0}); // Start with root node at level 0.
    
    vector<vector<int>> result; // Final result to store level-order traversal.
    vector<int> elementsAtCurrLevel; // Temporarily store elements at the current level.
    int currentLevel = 0; // To track the current level.

    while (!q.empty()) {
        TreeNode* currNode = q.front().first;
        int nodeVal = currNode->val;
        int nodeLevel = q.front().second;
        q.pop();
        
        if (nodeLevel != currentLevel) {
            // Transition to a new level.
            result.push_back(elementsAtCurrLevel);
            elementsAtCurrLevel.clear();
            currentLevel = nodeLevel;
        }

        elementsAtCurrLevel.push_back(nodeVal);

        if (currNode->left != nullptr) {
            q.push({currNode->left, nodeLevel + 1});
        }
        if (currNode->right != nullptr) {
            q.push({currNode->right, nodeLevel + 1});
        }
    }

    // Push the last level's elements.
    if (!elementsAtCurrLevel.empty()) {
        result.push_back(elementsAtCurrLevel);
    }

    return result;
    }
};