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
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return 1+max(maxDepth(root->left), maxDepth(root->right));
  }
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return 1+min(minDepth(root->left), minDepth(root->right));
  }


  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }
    int max_depth = maxDepth(root);
    int min_depth = minDepth(root);

    if (max_depth-min_depth > 1) {
      return false;
    } else {
      return true;
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

  cout << "Balanced? " << s.isBalanced(root) << endl;

  return 0;
}