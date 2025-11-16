#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  int search(vector<int> &inorder, int left, int right,
             int target)
  {
    for (int i = left; i <= right; i++)
    {
      if (inorder[i] == target)
      {
        return i;
      }
    }
    return -1;
  }

  TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &preidx,
                   int left, int right)
  {

    if (left > right)
      return NULL;

    TreeNode *root = new TreeNode(preorder[preidx]);
    preidx++;

    int inIdx = search(inorder, left, right, preorder[preidx - 1]);

    root->left = helper(preorder, inorder, preidx, left, inIdx - 1);
    root->right = helper(preorder, inorder, preidx, inIdx + 1, right);

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    int preidx = 0;
    int left = 0;
    int right = inorder.size() - 1;
    return helper(preorder, inorder, preidx, left, right);
  }
};

int main()
{

  Solution solution;
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  TreeNode *root = solution.buildTree(preorder, inorder);

  // Example: Print inorder traversal to verify
  function<void(TreeNode *)> printInorder = [&](TreeNode *node)
  {
    if (!node)
      return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
  };

  cout << "Inorder traversal: ";
  printInorder(root);
  cout << endl;

  return 0;
}