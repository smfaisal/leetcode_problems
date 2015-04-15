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
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int left = (root->left)?maxDepth(root->left):0;
    int right = (root->right)?maxDepth(root->right):0;

    return 1 + max(left, right);
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);

  int depth = s.maxDepth(root);

  cout << "Max depth: " << depth << endl;

  return 0;
}