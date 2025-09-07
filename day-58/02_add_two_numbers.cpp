// Leetcode - 2
#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//       while (condition)
//       {
//         /* code */
//       }

//     }
// };

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  int numl1 = 0;
  int numl2 = 0;
  while (l1)
  {
    numl1 = numl1 * 10 + l1->val;
    l1 = l1->next;
  }

  while (l2)
  {
    numl2 = numl2 * 10 + l2->val;
    l2 = l2->next;
  }
  int sum = numl2 + numl1;
  int revnum = 0;
  while (sum > 0)
  {
    int digit = sum % 10;
    revnum = revnum * 10 + digit;
    sum /= 10;
  }
  // cout << "\n";
  // cout << revnum;

  // using stack-> in stack store digit and make ll from it

  stack<int> st;
  while (revnum > 0)
  {
    st.push(revnum % 10);
    revnum /= 10;
  }

  // create ll
  ListNode *head = new ListNode(st.top());
  st.pop();
  ListNode *curr = head;
  // store in ll
  while (!st.empty())
  {
    curr->next = new ListNode(st.top());
    st.pop();
    curr = curr->next;
  }
  return head;
}

int main()
{
  ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  // Solution sol;
  ListNode *result = addTwoNumbers(l1, l2);

  // Print the result list
  while (result)
  {
    cout << result->val;
    if (result->next)
      cout << " -> ";
    result = result->next;
  }
  cout << endl;

  return 0;
}