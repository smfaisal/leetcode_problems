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

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    vector<int> in_left;
    vector<int> post_left;
    vector<int> in_right;
    vector<int> post_right;
    TreeNode* head = NULL;
    if (inorder.size() == 0) {
      return NULL;
    } else if (inorder.size() == 1) {
      return new TreeNode(inorder[0]);
    }
    int root = postorder[postorder.size()-1];
    int i = 0;

    while (inorder[i] != root) {
      in_left.push_back(inorder[i]);
      post_left.push_back(postorder[i]);
      i++;
    }
    i++;
    while (i < inorder.size()) {
      in_right.push_back(inorder[i]);
      post_right.push_back(postorder[i-1]);
      i++;
    }
    head = new TreeNode(root);
    if (in_left.size() > 0) {
      head->left = buildTree(in_left, post_left);
    }
    if (in_right.size() > 0) {
      head->right = buildTree(in_right, post_right);
    }
    return head;
  }
};

int main() {
  Solution s;
  int inorder[] = {2, 1};
  vector<int> in(inorder, inorder+2);
  int postorder[] = {2, 1};
  vector<int> post(postorder, postorder+2);
  TreeNode* head = s.buildTree(in, post);
  cout << "Head: " << head->val;
  return 0;
}
