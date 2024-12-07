/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void nAryPostorderTraversal(Node* root, vector<int>& ans){
        if(root==nullptr){
            return;
        }
        
        for(auto it: root->children){
            nAryPostorderTraversal(it, ans);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        nAryPostorderTraversal(root, ans);
        return ans;
    }
};