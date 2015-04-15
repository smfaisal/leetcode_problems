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
  void getsum(TreeNode* root, int& m_path, int& t_path) {
    if (!root) {
      return;
    }
    int l = 0, r = 0;
    getsum(root->left, l, t_path);
    getsum(root->right, r, t_path);
    int v = root->val;
    if (l > 0) {
      v+= l;
    }
    if (r > 0) {
      v+= r;
    }
    m_path = root->val;//(root->val>0)?root->val:0;
    int tm = max(l, r);
    if (tm > 0) {
      m_path = m_path + tm;
    }
    t_path = max(t_path, v);
  }

  int maxPathSum(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int max_path = INT_MIN;
    int thru_path = INT_MIN;
    getsum(root, max_path, thru_path);
    return max(max_path, thru_path);
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(-2);
//  root->left = new TreeNode(6);
////  root->right = new TreeNode(-2);
//  root->left->left = new TreeNode(0);
//  root->left->right = new TreeNode(-6);

  int m = s.maxPathSum(root);

  cout << "Max: " << m << endl;
  return 0;
}
