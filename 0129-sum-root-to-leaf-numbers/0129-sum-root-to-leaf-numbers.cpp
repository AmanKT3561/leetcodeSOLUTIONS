class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int path) {
        if (!node) return 0;
        path = path * 10 + node->val;
        if (!node->left && !node->right) return path;
        return dfs(node->left, path) + dfs(node->right, path);
    }
};