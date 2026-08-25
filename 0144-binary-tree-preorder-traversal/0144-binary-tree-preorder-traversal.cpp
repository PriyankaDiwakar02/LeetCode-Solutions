class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
    
    void dfs(TreeNode* node, vector<int>& result) {
        if (!node) return;
        result.push_back(node->val); // Visit root
        dfs(node->left, result);     // Traverse left subtree
        dfs(node->right, result);    // Traverse right subtree
    }
};