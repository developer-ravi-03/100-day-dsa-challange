#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

Node *insert(Node *root, int val)
{
  if (root == NULL)
    return new Node(val);
  if (val < root->data)
  {
    root->left = insert(root->left, val);
  }
  else
  {
    root->right = insert(root->right, val);
  }
  return root;
}

Node *buildBST(vector<int> arr)
{
  Node *root = NULL;

  for (int val : arr)
  {
    root = insert(root, val);
  }
  return root;
}

void inorder(Node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// Search
bool Search(Node *root, int key)
{
  if (root == NULL)
    return false;
  if (root->data == key)
    return true;

  if (root->data > key)
    return Search(root->left, key);
  else
    return Search(root->right, key);
}

int main()
{
  vector<int> arr = {3, 2, 1, 5, 6, 4};

  Node *root = buildBST(arr);

  inorder(root);
  cout << endl;

  int key = 5;
  int index = Search(root, key);
  if (index)
    cout << "item found" << endl;
  else
    cout << "item not found" << endl;

  return 0;
}