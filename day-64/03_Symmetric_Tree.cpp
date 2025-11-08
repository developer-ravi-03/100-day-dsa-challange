// Leetcode :- 101
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
  bool isSymmetric(TreeNode *root)
  {
    return root == NULL || isSymmetricHelp(root->left, root->right);
  }

  bool isSymmetricHelp(TreeNode *left, TreeNode *right)
  {
    if (left == NULL && right == NULL)
    {
      return true;
    }
    if (left != NULL && right == NULL)
    {
      return false;
    }
    if (left == NULL && right != NULL)
    {
      return false;
    }

    if (left->val != right->val)
      return false;

    return isSymmetricHelp(left->left, right->right) &&
           isSymmetricHelp(left->right, right->left);
  }
};
int main()
{
  // Create a sample tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  Solution solution;
  bool result = solution.isSymmetric(root);
  cout << "Is tree symmetric? " << (result ? "Yes" : "No") << endl;

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}