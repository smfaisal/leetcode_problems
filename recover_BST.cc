#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* inorder(TreeNode* node, TreeNode* prev_node, int& prev, vector<TreeNode* >& err_node, vector<TreeNode* >& err_parent) {
    if (!node) {
      return prev_node;
    }
    prev_node = inorder(node->left, prev_node, prev, err_node, err_parent);

    if (node->val < prev) {
      err_node.push_back(node);
      err_parent.push_back(prev_node);
      if (err_node.size() == 2) {
        return node;
      }
    }
    prev = node->val;
    return inorder(node->right, node, prev, err_node, err_parent);
  }

  void recoverTree(TreeNode *root) {
    if (!root) {
      return;
    }
    int prev = INT_MIN;
    vector<TreeNode* > err_node;
    vector<TreeNode* > err_parent;

    inorder(root, NULL, prev, err_node, err_parent);

    if (err_node.size() == 2) {
      int tmp = err_parent[0]->val;
      err_parent[0]->val = err_node[1]->val;
      err_node[1]->val = tmp;
    } else {
      int tmp = err_node[0]->val;
      err_node[0]->val = err_parent[0]->val;
      err_parent[0]->val = tmp;
    }
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  s.recoverTree(root);

  return 0;
}