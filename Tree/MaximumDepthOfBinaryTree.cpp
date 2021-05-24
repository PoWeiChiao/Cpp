#include <queue>

// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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

class Solution_DFS {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution_BFS {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            depth++;
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right); 
            }
        }
        return depth;
    }
}