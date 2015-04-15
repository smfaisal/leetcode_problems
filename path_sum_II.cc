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
  void ps(TreeNode* root, int sum, vector<int> r, vector<vector<int> >& res) {
    if (!root->left && !root->right) {
      if (sum == root->val) {
        r.push_back(root->val);
        res.push_back(r);
      }
    } else if (!root->left) {
      r.push_back(root->val);
      ps(root->right, sum-root->val, r, res);
    } else if (!root->right){
      r.push_back(root->val);
      ps(root->left, sum-root->val, r, res);
    } else {
      r.push_back(root->val);
      ps(root->right, sum-root->val, r, res);
      ps(root->left, sum-root->val, r, res);
    }
  }
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > res;
    if (!root) {
      return res;
    }
    vector<int> r;
    ps(root, sum, r, res);
    return res;
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(-10);
  root->left = new TreeNode(2);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(3);
  root->right->right = new TreeNode(5);
  root->right->right->right = new TreeNode(5);

  vector<vector<int> > res = s.pathSum(root, 4);

  cout << "Paths: " << endl;
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }

  return 0;
}