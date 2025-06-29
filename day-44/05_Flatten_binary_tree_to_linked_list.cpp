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
  TreeNode *nextRight = NULL;

  void flatten(TreeNode *root)
  {
    if (root == NULL)
      return;

    flatten(root->right);
    flatten(root->left);

    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
  }
};

int main()
{
  /*
  Example tree:
        1
       / \
      2   5
     / \   \
    3   4   6

  Flattened: 1 2 3 4 5 6
  */

  // Construct the tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);

  // Flatten the tree
  Solution sol;
  sol.flatten(root);

  // Print the flattened tree (right pointers)
  TreeNode *curr = root;
  while (curr)
  {
    cout << curr->val << " ";
    curr = curr->right;
  }
  cout << endl;

  // Cleanup (optional)
  curr = root;
  while (curr)
  {
    TreeNode *next = curr->right;
    delete curr;
    curr = next;
  }
  return 0;
}