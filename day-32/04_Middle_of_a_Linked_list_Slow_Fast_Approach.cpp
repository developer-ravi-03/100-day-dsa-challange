// Leetcode : 876
// Problem: Find the middle of a linked list
// Slow and Fast Approach
// TC: O(n)
// SC: O(1)
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
  ListNode *middleNode(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
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
  head->next->next->next->next->next = new ListNode(6);

  Solution sl;
  ListNode *midNode = sl.middleNode(head);
  if (midNode != NULL)
  {
    cout << "Middle value: " << midNode->val << endl;
  }
  else
  {
    cout << "The list is empty." << endl;
  }

  return 0;
}