// TC : O(Nlogn)
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

// build tree
static int idx = -1;
Node *buildTree(vector<int> preorder)
{
  idx++;
  if (idx >= preorder.size() || preorder[idx] == -1)
  {
    return NULL;
  }

  Node *root = new Node(preorder[idx]);
  root->left = buildTree(preorder);  // left
  root->right = buildTree(preorder); // right

  return root;
}

// Top View of a Binary Tree
void topView(Node *root)
{
  queue<pair<Node *, int>> Q; //(Node, HD)
  map<int, int> m;            //<HD, node val>

  Q.push({root, 0});

  while (Q.size() > 0)
  {
    Node *curr = Q.front().first;
    int currHD = Q.front().second;
    Q.pop();

    if (m.find(currHD) == m.end())
    {
      m[currHD] = curr->data;
    }

    if (curr->left != NULL)
    {
      Q.push({curr->left, currHD - 1});
    }

    if (curr->right != NULL)
    {
      Q.push({curr->right, currHD + 1});
    }
  }

  for (auto it : m)
  {
    cout << it.second << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(preorder);
  topView(root);

  return 0;
}