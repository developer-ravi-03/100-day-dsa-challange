#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  bool checkChildrenSum(TreeNode *root)
  {
    // Your code goes here
    if (root == NULL)
      return true;
    if (root->left == NULL && root->right == NULL)
      return true;

    int LS = (root->left) ? root->left->val : 0;
    int RS = (root->right) ? root->right->val : 0;

    if (root->val != LS + RS)
      return false;

    return checkChildrenSum(root->left) && checkChildrenSum(root->right);
  }
};

int main()
{
  Solution sol;

  // Build a sample tree that satisfies the children sum property:
  //        10
  //       /  \
  //      8    2
  //     / \
  //    3   5
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(8);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(5);

  cout << (sol.checkChildrenSum(root) ? "True\n" : "False\n");

  // Cleanup
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}