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
  void flatten(TreeNode *root) {
    if (!root || (!root->left && !root->right)) {
      return;
    }
    if (root->left) {
      flatten(root->right);
      return;
    }
    TreeNode* right = root->right;
    flatten(root->left);
    root->right = root->left;
    root->left = NULL;
    TreeNode* cur = root->right;
    while (cur->right) {
      cur = cur->right;
    }
    cur->right = right;
    flatten(cur->right);
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
//  root->left = new TreeNode(9);
  root->right = new TreeNode(1);
//  root->left->left = new TreeNode(0);

  s.flatten(root);
  TreeNode* tmp = root;
  while (tmp) {
    cout << tmp->val << "->";
    tmp = tmp->right;
  }
  cout << endl;
  return 0;
}