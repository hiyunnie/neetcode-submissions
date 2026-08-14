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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;

        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;

        // 1. 檢查當前位置是否相同
        if (isSameTree(root, subRoot)) return true;

        // 2. 如果不同，繼續往 root 的左子樹與右子樹遞迴尋找
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
/**

## Approach

Traverse every node in `root`.

For each node:

1. Check whether the tree starting from this node is exactly the same as `subRoot`.
2. If they are the same, return true.
3. Otherwise, recursively search the left and right subtrees.

Use a helper function `isSameTree()` to compare two trees.

## Complexity

Let:

- `n` = number of nodes in `root`
- `m` = number of nodes in `subRoot`

- Time: `O(n * m)` worst case
- Space: `O(h)` for recursion stack

Worst case space can be `O(n)` for a skewed tree.

## Interview Explanation

I traverse the main tree and treat every node as a possible starting point of the subtree.

For each node, I call a helper function to check whether the tree rooted at that node is exactly the same as `subRoot`.

If they are not the same, I continue searching in the left and right subtrees.

## Follow-up

Can you improve the worst-case time complexity?

## Note

`isSameTree()` is the DFS helper function.

It checks:

1. Both nodes are null -> same
2. Only one is null -> different
3. Values are different -> different
4. Otherwise compare left and right subtrees recursively
**/
