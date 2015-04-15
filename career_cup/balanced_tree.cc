#include <iostream>

using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  int getmaxdepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return 1+max(getmaxdepth(root->left), getmaxdepth(root->right));
  }

  int getmindepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return 1+min(getmindepth(root->left), getmindepth(root->right));
  }

  bool isbalanced(TreeNode* root) {
    if (!root) {
      return true;
    }

    int mx = getmaxdepth(root);
    int mn = getmindepth(root);
    cout << "max: " << mx << " min: " << mn << endl;
    if (abs(mx-mn) > 1) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);


  cout << "Balanced?: " << s.isbalanced(root) << endl;

  return 0;
}