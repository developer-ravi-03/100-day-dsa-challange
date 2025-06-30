// Leetcode : 99
// Recover BST
// Optimised Space with Morris Inorder Traversal
// TC : O(n)
// SC : O(1)
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
  void recoverTree(TreeNode *root)
  {
    TreeNode *prev = NULL;
    TreeNode *first = NULL;
    TreeNode *second = NULL;

    while (root != NULL)
    {
      if (root->left == NULL)
      {
        if (prev != NULL && prev->val > root->val)
        {
          if (first == NULL)
          {
            first = prev;
          }
          second = root;
        }
        prev = root;
        root = root->right;
      }
      else
      {
        // find prev (IP)
        TreeNode *IP = root->left;
        while (IP->right != NULL && IP->right != root)
        {
          IP = IP->right;
        }
        if (IP->right == NULL)
        {
          IP->right = root;
          root = root->left;
        }
        else
        {
          if (prev != NULL && prev->val > root->val)
          {
            if (first == NULL)
            {
              first = prev;
            }
            second = root;
          }
          prev = root;
          IP->right = NULL;
          root = root->right;
        }
      }
    }
    if (first != NULL && second != NULL)
    {
      int temp = first->val;
      first->val = second->val;
      second->val = temp;
    }
  }
};
// print the tree in in order
void inorder(TreeNode *root)
{
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main()
{
  // Construct a BST with two nodes swapped
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(3);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(8);
  root->right->right = new TreeNode(9);

  cout << "Before recovery: ";
  inorder(root);
  cout << endl;

  Solution sol;
  sol.recoverTree(root);

  cout << "After recovery: ";
  inorder(root);
  cout << endl;

  // Clean up memory
  delete root->right->left;
  delete root->right;
  delete root->left;
  delete root;
  return 0;
}