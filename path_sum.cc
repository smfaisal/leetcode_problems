#include <iostream>

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
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) {
      return false;
    } else if (!root->left && !root->right) {
      return (sum == root->val);
    } else if (!root->left) {
      return hasPathSum(root->right, sum-root->val);
    } else if (!root->right) {
      return hasPathSum(root->left, sum-root->val);
    } else {
      return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(-10);
//  root->left = new TreeNode(2);
//  root->right = new TreeNode(4);
//  root->left->left = new TreeNode(3);
//  root->left->left->left = new TreeNode(3);
//  root->right->right = new TreeNode(5);
//  root->right->right->right = new TreeNode(5);

  cout << "Path sum? " << s.hasPathSum(root, -10) << endl;

  return 0;
}