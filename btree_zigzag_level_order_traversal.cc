#include <iostream>
#include <vector>
#include <map>

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
  void lorder(TreeNode* root, int level, map<int, vector<int> >& mp) {
    if (!root) {
      return;
    }
    if (mp.find(level) == mp.end()) {
      mp[level] = vector<int>();
    }
    mp[level].push_back(root->val);
    if (root->left) {
      lorder(root->left, level+1, mp);
    }
    if (root->right) {
      lorder(root->right, level+1, mp);
    }
  }

  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > result;
    map<int, vector<int> > mp;
    map<int, vector<int> >::iterator it;
    lorder(root, 0, mp);
    int reverse_if_odd = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (reverse_if_odd%2) {
        reverse(it->second.begin(), it->second.end());
        result.push_back(it->second);
      } else {
        result.push_back(it->second);
      }
      reverse_if_odd++;
    }
    return result;
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(0);

  vector<vector<int> > result = s.zigzagLevelOrder(root);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << endl;
  }

  return 0;
}


