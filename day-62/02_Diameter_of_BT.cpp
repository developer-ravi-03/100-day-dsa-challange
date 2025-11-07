// Leetcode :- 543
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
  int ans = 0;
  int height(TreeNode *node)
  {
    if (node == NULL)
      return 0;
    int LH = height(node->left);
    int RH = height(node->right);
    ans = max((LH + RH), ans);
    return max(LH, RH) + 1;
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    height(root);
    return ans;
  }
};

int main()
{
  // Create a binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution solution;
  int diameter = solution.diameterOfBinaryTree(root);
  cout << "Diameter of the binary tree is: " << diameter << endl;

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}