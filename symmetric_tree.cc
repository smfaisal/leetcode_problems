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
  bool isSame(TreeNode* tree1, TreeNode* tree2) {
    if (!tree1 && !tree2) {
      return true;
    } else if (!tree1 || !tree2) {
      return false;
    }
    if (tree1->val != tree2->val) {
      return false;
    }
    return (isSame(tree1->left, tree2->right) && isSame(tree1->right, tree2->left));
  }

  bool isSymmetric(TreeNode *root) {
    if (!root || (!root->left && !root->right)) {
      return true;
    }
    if (!root->left || !root->right) {
      return false;
    }
    return isSame(root->left, root->right);
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(9);
  root->left->left = new TreeNode(0);
  root->right->right = new TreeNode(0);

  cout << "Symmetric?: " << s.isSymmetric(root) << endl;
  return 0;
}