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
  int sum;

  int getsum(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int v = root->val;
    int l = getsum(root->left);
    int r = getsum(root->right);
    if (l > 0) {
      v += l;
    }
    if (r > 0) {
      v += r;
    }
    sum = max(sum, v);

    if (max(l, r) > 0) {
      return max(l, r) + root->val;
    } else {
      return root->val;
    }
  }

  int maxPathSum(TreeNode *root) {
    sum = -9999;
    getsum(root);
    return sum;
  }
};