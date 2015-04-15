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
  void right_view(TreeNode* root, int level, vector<int>& res) {
    if (!root) {
      return;
    }
    if (res.size() < level) {
      res.push_back(root->val);
    }
    right_view(root->right, level+1, res);
    right_view(root->left, level+1, res);
  }

  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;

    right_view(root, 1, res);

    return res;
  }
};

int main() {
  Solution s;

  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  vector<int> res = s.rightSideView(root);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ", ";
  }
  cout << endl;
  return 0;

}