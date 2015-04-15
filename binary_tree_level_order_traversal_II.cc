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
  void traverse(TreeNode* root, int level, vector<vector<int> >& res) {
    if (!root) {
      return;
    }
    if (res.size() <= level) {
      res.push_back(vector<int>());
    }
    res[level].push_back(root->val);
    traverse(root->left, level+1, res);
    traverse(root->right, level+1, res);
  }

  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > result;
    if (!root) {
      return result;
    }

    traverse(root, 0, result);
    vector<vector<int> > final(result.rbegin(), result.rend());
    return final;
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  vector<vector<int> > res = s.levelOrderBottom(root);

  cout << "Res: " << endl;
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}