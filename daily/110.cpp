#include "../common_header.hpp"
#include "../ds/treeNode.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  pair<bool, int> heightAndBalance(TreeNode *node) {
    if (node == nullptr)
      return {true, 0};
    pair<bool, int> l = heightAndBalance(node->left);
    if (!l.first)
      return {false, 0};
    pair<bool, int> r = heightAndBalance(node->right);
    if (!r.first)
      return {false, 0};
    int height = max(l.second, r.second) + 1;
    return {l.second - r.second <= 1 && r.second - l.second <= 1, height};
  }

public:
  bool isBalanced(TreeNode *root) { return heightAndBalance(root).first; }
};
