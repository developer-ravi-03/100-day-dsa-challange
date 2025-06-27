// Leetcode : 543
// Diameter of Binary Tree
// Optimised approach
// TC : O(n)
#include <iostream>
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
  int ans = 0;
  int height(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    ans = max(leftHt + rightHt, ans); // currDiam of root node

    return max(leftHt, rightHt) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root)
  {
    height(root);

    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  Solution sol;
  cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(root) << endl;
  return 0;
}