// Leetcode : 99
// Recover BST
// TC : O(n)
// SC : O(n)
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
  TreeNode *prev = NULL;
  TreeNode *first = NULL;
  TreeNode *sec = NULL;

  void inorder(TreeNode *root)
  { // O(n)
    if (root == NULL)
    {
      return;
    }

    inorder(root->left);

    if (prev != NULL && root->val < prev->val)
    {
      if (!first)
        first = prev;
      sec = root;
    }

    prev = root;
    inorder(root->right);
  }

  void recoverTree(TreeNode *root)
  {
    // inorder => first , second
    inorder(root);

    //  swap the variable
    int temp = first->val;
    first->val = sec->val;
    sec->val = temp;
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