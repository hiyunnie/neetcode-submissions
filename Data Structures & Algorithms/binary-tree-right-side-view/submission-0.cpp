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
    vector<int> res;
    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        // 如果當前深度等於結果數組大小，代表這是該層第一個被看見的節點
        if (depth == res.size()) {
            res.push_back(node->val);
        }

        // 優先走右子樹（右視圖情境）
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
