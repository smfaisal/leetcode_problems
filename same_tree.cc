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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    } else if (!p || !q) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
  }

};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(9);
  root->left->left = new TreeNode(0);
  root->right->right = new TreeNode(0);

  return 0;
}