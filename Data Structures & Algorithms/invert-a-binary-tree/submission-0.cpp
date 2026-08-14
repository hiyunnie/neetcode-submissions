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
    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;
        swap(root->left, root->right);
        
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        dfs(root);
        return root;
    }
};
/**
## Approach

Use DFS to visit every node.

For each node:

1. Swap its left and right child.
2. Recursively invert the left subtree.
3. Recursively invert the right subtree.

## Complexity

- Time: `O(n)`
- Space: `O(h)`

`h` is the height of the tree because of the recursion stack.

## Interview Explanation
I use DFS to visit every node.
For each node, I swap its left and right child, then recursively invert both subtrees.
Since every node is visited once, the time complexity is O(n).
The space complexity is O(h) because of the recursive call stack.

## Follow-up

Can you solve this iteratively using BFS?

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelsize = q.size();
            for (int i = 0; i < levelsize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                swap(curr->left, curr->right);

                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
            }
        }
        return root;
    }
};

## Note

This is wrong:
`if (root->right == nullptr || root->left == nullptr) return;`
A node with only one child still needs to be inverted.**/