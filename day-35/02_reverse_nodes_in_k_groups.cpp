// Leetcode : 25
// Reverse Nodes in k groups
// TC : O(n)
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *temp = head;
    int count = 0;

    // check if k nodes exist
    while (count < k)
    {
      if (temp == NULL)
        return head;
      temp = temp->next;
      count++;
    }

    // recursivelt call for rest of LL
    ListNode *prevNode = reverseKGroup(temp, k);

    // reverse current group
    temp = head;
    count = 0;
    while (count < k)
    {
      ListNode *next = temp->next;
      temp->next = prevNode;

      prevNode = temp;
      temp = next;

      count++;
    }
    return prevNode;
  }
};

int main()
{
  // Create linked list: 1->2->3->4->5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int k = 2; // Example group size

  Solution sol;
  ListNode *result = sol.reverseKGroup(head, k);

  // Print the reversed list
  while (result != nullptr)
  {
    cout << result->val;
    if (result->next)
      cout << "->";
    result = result->next;
  }
  cout << endl;
  return 0;
}