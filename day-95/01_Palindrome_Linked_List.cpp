// Palindrome Linked List
// Leetcode:234
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
  bool isPalindrome(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *curr;
    if (fast != NULL)
      curr = slow->next;
    else
      curr = slow;
    ListNode *nex = NULL;
    ListNode *prev = NULL;

    while (curr != NULL)
    {
      nex = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nex;
    }

    slow = head;
    while (prev != NULL)
    {
      if (slow->val == prev->val)
      {
        slow = slow->next;
        prev = prev->next;
        continue;
      }
      return false;
    }

    return true;
  }
};
int main()
{
  // Create a sample linked list: 1->2->2->1
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);

  Solution sol;
  cout << (sol.isPalindrome(head) ? "true" : "false") << endl;
  return 0;
}