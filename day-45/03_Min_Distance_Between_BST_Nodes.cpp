// Leetcode : 783
// Min Distance b/w two BST Nodes
// TC : O(n)
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  TreeNode *prev = NULL;
  int minDiffInBST(TreeNode *root)
  {
    if (root == NULL)
      return INT_MAX;

    int ans = INT_MAX;
    if (root->left != NULL)
    {
      int leftMin = minDiffInBST(root->left);
      ans = min(ans, leftMin);
    }

    if (prev != NULL)
      ans = min(ans, root->val - prev->val);

    prev = root;

    if (root->right != NULL)
    {
      int rightMin = minDiffInBST(root->right);
      ans = min(ans, rightMin);
    }
    return ans;
  }
};

int main()
{
  // Example BST:
  //      4
  //     / \
  //    2   6
  //   / \
  //  1   3
  //       \
  //        52

  TreeNode *root = new TreeNode(83);
  root->left = new TreeNode(62);
  root->right = new TreeNode(88);
  root->left->left = new TreeNode(42);
  root->left->right = new TreeNode(82);
  root->left->left->right = new TreeNode(52);

  Solution sol;
  int minDiff = sol.minDiffInBST(root);
  cout << "Minimum difference: " << minDiff << endl;

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}