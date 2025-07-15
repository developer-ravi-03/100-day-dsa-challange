// Largest BST in BT
// TC : O(n)
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

class Info
{
public:
  int min, max, size;

  Info(int mi, int ma, int sz)
  {
    min = mi;
    max = ma;
    size = sz;
  }
};

Info helper(TreeNode *root)
{
  if (root == NULL)
  {
    return Info(INT_MAX, INT_MIN, 0);
  }

  Info left = helper(root->left);
  Info right = helper(root->right);

  if (root->val > left.max && root->val < right.min)
  {
    int currMin = min(root->val, left.min);
    int currMax = min(root->val, right.max);
    int currSz = left.size + right.size + 1;

    return Info(currMin, currMax, currSz);
  }
  else
  {
    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
  }
}

int largestBSTinBT(TreeNode *root)
{
  Info info = helper(root);
  return info.size; // max BST SIze
}

int main()
{
  // Construct a BST with two nodes swapped
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(8);
  root->right->right = new TreeNode(57);
  // inorder(root);

  cout << largestBSTinBT(root) << endl;
  return 0;
}