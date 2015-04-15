#include <iostream>
#include <string>

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
  bool validBST(TreeNode* root, long min, long max) {
    if (!root) {
      return true;
    }
    if (root->val <= min || root->val >= max) {
      return false;
    }
    return (validBST(root->left, min, root->val) && validBST(root->right, root->val, max));
  }

  bool isValidBST(TreeNode *root) {
    if (!root) {
      return true;
    }

    return validBST(root, LONG_MIN, LONG_MAX);
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(4);

  cout << "Valid BST?: " << s.isValidBST(root) << endl;
  return 0;
}