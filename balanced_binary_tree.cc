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
  void getMaxDepth(TreeNode* root, int& left, int& right) {
    if (!root) {
      left = 0;
      right = 0;
      return;
    }
    int my_left = 0;
    int my_right = 0;
    getMaxDepth(root->left, my_left, my_right);
    left = 1+max(my_left, my_right);
    my_left = 0;
    my_right = 0;
    getMaxDepth(root->right, my_left, my_right);
    right = 1+max(my_left, my_right);
  }

  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }
//
//    int left = getMaxDepth(root->left);
//    int right = getMaxDepth(root->right);

    int left = 0, right = 0;
    getMaxDepth(root, left, right);

    if (abs(left-right) > 1) {
      return false;
    } else {
      return isBalanced(root->left) && isBalanced(root->right);
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