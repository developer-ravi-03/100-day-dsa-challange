// Implement Stacks using LL
// Striver
#include <iostream>
#include <stack>
using namespace std;
class LinkedListStack
{
private:
  struct Node
  {
    int data;
    Node *next;
    Node(int x)
    {
      data = x;
      next = NULL;
    }
  };

  Node *topNode;

public:
  LinkedListStack()
  {
    topNode = NULL;
  }

  void push(int x)
  {
    Node *newNode = new Node(x);
    newNode->next = topNode;
    topNode = newNode;
  }

  int pop()
  {
    if (isEmpty())
    {
      return -1;
    }
    Node *temp = topNode;
    int poped = temp->data;
    topNode = topNode->next;
    delete temp;
    return poped;
  }

  int top()
  {
    if (isEmpty())
    {
      return -1;
    }
    return topNode->data;
  }

  bool isEmpty()
  {
    return topNode == NULL;
  }
};
int main()
{
  LinkedListStack stack;

  stack.push(10);
  stack.push(20);
  stack.push(30);

  cout << "Top: " << stack.top() << endl;
  cout << "Popped: " << stack.pop() << endl;
  cout << "Top: " << stack.top() << endl;
  cout << "Popped: " << stack.pop() << endl;
  cout << "Popped: " << stack.pop() << endl;
  cout << "Is Empty: " << stack.isEmpty() << endl;
  return 0;
}