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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> myStack;
        myStack.push(root);
        while(!myStack.empty()){
            TreeNode* temp = myStack.top();
            ans.push_back(temp->val);
            myStack.pop();
            if(temp->right != nullptr) myStack.push(temp->right);
            if(temp->left != nullptr) myStack.push(temp->left);
        }
        return ans;
    }
};