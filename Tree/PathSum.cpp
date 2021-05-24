// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool DFS(TreeNode* curr, int sum, int targetSum) {
        if (curr == nullptr) return false;
        if (curr->left == nullptr && curr->right == nullptr) return curr->val + sum == targetSum ? true : false;
        return DFS(curr->left, curr->val + sum, targetSum) || DFS(curr->right, curr->val + sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return DFS(root, 0, targetSum);
    }
};