class Solution {
public:
    int max_diameter = 0;

    // 回傳以 root 為根的子樹「高度」
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);

        // 以當前節點為轉折點的直徑 = 左高度 + 右高度
        max_diameter = max(max_diameter, left_height + right_height);

        // 回傳給上一層父節點的高度
        return max(left_height, right_height) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return max_diameter;
    }
};