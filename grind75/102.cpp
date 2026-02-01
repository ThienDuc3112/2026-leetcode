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
#include "../common_header.hpp"
#include "../ds/treeNode.hpp"

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr)
      return res;
    queue<pair<int, TreeNode *>> q;
    q.push({0, root});
    while (!q.empty()) {
      auto [layer, node] = q.front();
      q.pop();
      if (layer == res.size())
        res.push_back({});
      res[layer].push_back(node->val);
      if (node->left != nullptr)
        q.push({layer + 1, node->left});
      if (node->right != nullptr)
        q.push({layer + 1, node->right});
    }
    return res;
  }
};
