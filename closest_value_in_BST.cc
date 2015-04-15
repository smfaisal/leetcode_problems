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
  void getclosest(TreeNode* root, int target, int& closest) {
    if (!root) {
      return;
    }
    if (root->val == target) {
      closest = root->val;
      return;
    }
    if (target < root->val) {
      getclosest(root->left, target, closest);
      if (abs(target-root->val) < abs(target-closest)) {
        closest = root->val;
      }
    } else {
      getclosest(root->right, target, closest);
      if (abs(target-root->val) < abs(target-closest)) {
        closest = root->val;
      }
    }
  }
  int findClosest(TreeNode* root, int target) {
    if (!root) {
      return INT_MIN;
    }
    int closest = 1000;
    getclosest(root, target, closest);
    return closest;
  }
};


int main() {
  Solution s;
  TreeNode* root = new TreeNode(15);
  root->left = new TreeNode(5);
  root->right = new TreeNode(24);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(8);

  cout << "Closest: " << s.findClosest(root, 9) << endl;
  return 0;
}