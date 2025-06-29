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
  int prevOrder = 0;

  int kthSmallest(TreeNode *root, int k)
  {

    if (root == NULL)
    {
      return -1;
    }

    if (root->left != NULL)
    {
      int leftAns = kthSmallest(root->left, k);
      if (leftAns != -1)
        return leftAns;
    }

    if (prevOrder + 1 == k)
    {
      return root->val;
    }

    prevOrder = prevOrder + 1;

    if (root->right != NULL)
    {
      int rightAns = kthSmallest(root->right, k);
      if (rightAns != -1)
        return rightAns;
    }
    return -1;
  }
};

int main()
{
  // Example BST:
  //       5
  //      / \
  //     3   6
  //    / \
  //   2   4
  //  /
  // 1

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);

  Solution sol;
  int k = 3;
  int result = sol.kthSmallest(root, k);
  cout << "The " << k << "rd smallest element is: " << result << endl;

  // Clean up memory
  delete root->left->left->left;
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}