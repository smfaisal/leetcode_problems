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
    TreeNode* holder;
    holder = root->right;
    if (root->left) {
      flatten(root->left);
      root->right = root->left;
      root->left = NULL;
      while (root->right) {
        root = root->right;
      }
      root->right = holder;
    }
    flatten(holder);
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(0);

  s.flatten(root);
  TreeNode* tmp = root;
  while (tmp) {
    cout << tmp->val << "->";
    tmp = tmp->right;
  }
  cout << endl;
  return 0;
}