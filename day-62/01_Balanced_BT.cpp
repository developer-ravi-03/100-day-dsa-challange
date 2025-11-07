// Leetcode :- 110
#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};

class Solution
{
public:
  bool isBalanced(TreeNode *root) { return bfsHt(root) != -1; }

  int bfsHt(TreeNode *node)
  {
    if (node == NULL)
      return 0;

    int LH = bfsHt(node->left);
    int RH = bfsHt(node->right);

    if (LH == -1 || RH == -1)
      return -1;
    if (abs(LH - RH) > 1)
      return -1;

    return max(LH, RH) + 1;
  }
};

int main()
{
  // Create a sample binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution solution;
  bool result = solution.isBalanced(root);
  cout << "Is the tree balanced? " << (result ? "Yes" : "No") << endl;

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}