// Leetcode : 430
// Flatten a Multilevel Doubly Linked List
// TC : O(n)
#include <iostream>
using namespace std;
class Node
{
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution
{
public:
  Node *flatten(Node *head)
  {
    if (head == NULL)
      return head;
    Node *curr = head;
    while (curr != NULL)
    {
      if (curr->child != NULL)
      {

        // flatten the child Node
        Node *next = curr->next;
        curr->next = flatten(curr->child);

        curr->next->prev = curr;
        curr->child = NULL;

        // find tail
        while (curr->next != NULL)
          curr = curr->next;

        // Attach tail with next ptr
        if (next != NULL)
        {
          curr->next = next;
          next->prev = curr;
        }
      }
      curr = curr->next;
    }
    return head;
  }
};

int main()
{
  // Creating a multilevel doubly linked list:
  // 1 - 2 - 3 - 4 - 5
  //         |
  //         6 - 7 - 8
  //             |
  //             9 - 10

  Node *n1 = new Node{1, nullptr, nullptr, nullptr};
  Node *n2 = new Node{2, nullptr, nullptr, nullptr};
  Node *n3 = new Node{3, nullptr, nullptr, nullptr};
  Node *n4 = new Node{4, nullptr, nullptr, nullptr};
  Node *n5 = new Node{5, nullptr, nullptr, nullptr};
  Node *n6 = new Node{6, nullptr, nullptr, nullptr};
  Node *n7 = new Node{7, nullptr, nullptr, nullptr};
  Node *n8 = new Node{8, nullptr, nullptr, nullptr};
  Node *n9 = new Node{9, nullptr, nullptr, nullptr};
  Node *n10 = new Node{10, nullptr, nullptr, nullptr};

  // Main list: 1-2-3-4-5
  n1->next = n2;
  n2->prev = n1;
  n2->next = n3;
  n3->prev = n2;
  n3->next = n4;
  n4->prev = n3;
  n4->next = n5;
  n5->prev = n4;

  // 3's child is 6
  n3->child = n6;

  // 6-7
  n6->next = n7;
  n7->prev = n6;
  n7->next = n8;
  n8->prev = n7;

  // 7's child is 8
  n7->child = n9;

  // 9 - 10
  n9->next = n10;
  n10->prev = n9;

  Solution sol;
  Node *flatHead = sol.flatten(n1);

  // Print flattened list
  Node *curr = flatHead;
  while (curr != nullptr)
  {
    cout << curr->val << " - ";
    curr = curr->next;
  }
  cout << endl;

  // Free memory (optional)
  curr = flatHead;
  while (curr != nullptr)
  {
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }
  return 0;
}