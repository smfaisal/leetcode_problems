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
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    } else if (!root->left && !root->right) {
      return 1;
    } else if (!root->left) {
      return 1 + minDepth(root->right);
    } else if (!root->right) {
      return 1 + minDepth(root->left);
    } else {
      return 1 + min(minDepth(root->left), minDepth(root->right));
    }
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(3);
  root->right->right = new TreeNode(5);
  root->right->right->right = new TreeNode(5);

  cout << "Min depth? " << s.minDepth(root) << endl;

  return 0;
}