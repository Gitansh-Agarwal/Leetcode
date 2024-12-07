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
        
//         if (root == nullptr) {
//         return {};
//     }
    
//     queue<pair<TreeNode*, int>> q; 
//     q.push({root, 0}); 
    
//     vector<vector<int>> result;
//     vector<int> elementsAtCurrLevel;
//     int currentLevel = 0; 

//     while (!q.empty()) {
//         TreeNode* currNode = q.front().first;
//         int nodeVal = currNode->val;
//         int nodeLevel = q.front().second;
//         q.pop();
        
//         if (nodeLevel != currentLevel) {
            
//             result.push_back(elementsAtCurrLevel);
//             elementsAtCurrLevel.clear();
//             currentLevel = nodeLevel;
//         }

//         elementsAtCurrLevel.push_back(nodeVal);

//         if (currNode->left != nullptr) {
//             q.push({currNode->left, nodeLevel + 1});
//         }
//         if (currNode->right != nullptr) {
//             q.push({currNode->right, nodeLevel + 1});
//         }
//     }

   
//     if (!elementsAtCurrLevel.empty()) {
//         result.push_back(elementsAtCurrLevel);
//     }

//     return result;
//     }
        
        
        
        
        
        
        
        
        if(!root)
        return {};
      int level = 1;
      queue<pair<TreeNode*, int>> q;
      vector<vector<int>> result;
      vector<int> elementsAtCurrLevel;
      q.push({root, 1});
      
      
      while(!q.empty()){
          TreeNode* node = q.front().first;
          int nodeVal = node->val;
          
          int currLevel = q.front().second;
          q.pop();
          
          if(currLevel>level){
              result.push_back(elementsAtCurrLevel);
              elementsAtCurrLevel.clear();
              level++;
          }
          
              elementsAtCurrLevel.push_back(nodeVal);
          
          
          
          if(node->left){
              q.push({node->left, currLevel+1});
              
          }
          if(node->right){
              q.push({node->right, currLevel+1});
          }
      }
      
        if(elementsAtCurrLevel.size() != 0)
            result.push_back(elementsAtCurrLevel);
      return result;
    }
};