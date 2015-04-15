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

class Solution{
public:
  void traverse(TreeNode* root, int level, vector<vector<int> >& res) {
    if (!root) {
      return;
    }
    if (res.size() <= level-1) {
      vector<int> r;
      res.push_back(r);
    }

    res[level-1].push_back(root->val);
    traverse(root->left, level+1, res);
    traverse(root->right, level+1, res);
  }

  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > res;
    if (!root) {
      return res;
    }

    traverse(root, 1, res);
    return res;
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(0);

  vector<vector<int> > result = s.levelOrder(root);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << endl;
  }

  return 0;
}