// Implement Stack using Arrays
// Striver
#include <iostream>
#include <vector>
using namespace std;
class ArrayStack
{
public:
  vector<int> arr;
  int topIndex;
  // int size=0;
  ArrayStack()
  {
    topIndex = -1;
  }

  void push(int x)
  {

    arr.push_back(x);
    topIndex++;
  }

  int pop()
  {
    if (topIndex == -1)
    {
      cout << "Stack is Empty\n";
      return -1;
    }
    int poped = arr[topIndex];
    arr.pop_back();
    topIndex--;
    return poped;
  }

  int top()
  {
    if (topIndex == -1)
    {
      return -1;
    }
    return arr[topIndex];
  }

  bool isEmpty()
  {
    return topIndex == -1;
  }
};
int main()
{
  ArrayStack stack;

  stack.push(10);
  stack.push(20);
  stack.push(30);

  cout << "Top element: " << stack.top() << endl;

  cout << "Popped: " << stack.pop() << endl;
  cout << "Popped: " << stack.pop() << endl;

  cout << "Top element: " << stack.top() << endl;

  cout << "Is empty: " << stack.isEmpty() << endl;

  stack.pop();
  stack.pop();

  cout << "Is empty: " << stack.isEmpty() << endl;
  return 0;
}