#include <queue>

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

using namespace std;

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q_left;
        q_left.push(root->left);

        queue<TreeNode*> q_right;
        q_right.push(root->right);

        while (!q_left.empty() && !q_right.empty()) {
            TreeNode *curr_left = q_left.front();
            q_left.pop();
            TreeNode *curr_right = q_right.front();
            q_right.pop();
            if (curr_left == nullptr && curr_right == nullptr) continue;
            if (curr_left == nullptr || curr_right == nullptr) return false;
            if (curr_left->val != curr_right->val) return false;
            q_left.push(curr_left->left);
            q_left.push(curr_left->right);
            q_right.push(curr_right->right);
            q_right.push(curr_right->left);
        }
        return true;
    }
};