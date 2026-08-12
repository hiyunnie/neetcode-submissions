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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
/**

## Brute Force

這題 DFS 本身已經是最佳解，因為每個 node 至少都需要被檢查一次。

## Optimized Approach

Use DFS recursively.

For each node:
- recursively calculate the depth of the left subtree
- recursively calculate the depth of the right subtree
- take the larger one and add 1 for the current node

## Complexity

- Time: `O(n)`
- Space: `O(h)`

`h` is the height of the tree.

Worst case:
- skewed tree: `O(n)`

Balanced tree:
- `O(log n)`

## Interview Explanation

I use DFS recursively to calculate the maximum depth.
For each node, I calculate the depth of the left and right subtrees, take the larger one, and add one for the current node.
The time complexity is O(n) because every node is visited once.
The space complexity is O(h) because of the recursive call stack.

## Follow-up
Can you solve this problem iteratively using BFS?
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int levelsize = q.size();
            for (int i = 0; i < levelsize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
            }
            depth++;
        }
        return depth;
    }
};
## Note


**/