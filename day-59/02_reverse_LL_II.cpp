// Leetcode -92
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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {

    if (!head || left == right)
      return head;

    ListNode *dummy = new ListNode(0, head);
    ListNode *leftPrev = dummy;
    ListNode *curr = dummy->next;

    for (int i = 0; i < left - 1; i++)
    {
      leftPrev = curr;
      curr = curr->next;
    }

    ListNode *subListHead = curr;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    for (int i = 0; i < right - left + 1; i++)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    leftPrev->next = prev;
    subListHead->next = curr;

    return dummy->next;
  }
};

int main()
{
  // Create a sample linked list: 1->2->3->4->5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  int left = 2, right = 4;

  Solution sol;
  ListNode *newHead = sol.reverseBetween(head, left, right);

  // Print the reversed list
  ListNode *curr = newHead;
  while (curr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
  return 0;
}