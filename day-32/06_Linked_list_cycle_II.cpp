// Leetcode : 142
// Linked List Cycle II
// Problem: Detect if a linked list has a cycle
// Slow and Fast Approach
// TC: O(n)
// SC: O(1)
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        isCycle = true;
        break;
      }
    }

    if (!isCycle)
    {
      return NULL;
    }

    slow = head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  // Creating a cycle for testing
  head->next->next->next->next->next = head->next->next; // 5 points to 3

  Solution sl;
  ListNode *cycleStart = sl.detectCycle(head);
  if (cycleStart)
  {
    cout << "The linked list has a cycle starting at node with value: " << cycleStart->val << endl;
  }
  else
  {
    cout << "The linked list does not have a cycle." << endl;
  }
  return 0;
}