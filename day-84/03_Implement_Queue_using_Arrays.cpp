// Implement Queue using Arrays
// Striver
#include <iostream>
#include <vector>
using namespace std;
class ArrayQueue
{
public:
  int arr[100];
  int size = 100;
  int currSize = 0;
  int start;
  int end;
  ArrayQueue()
  {
    start = -1;
    end = -1;
  }

  void push(int x)
  {
    if (currSize == size)
    {
      return;
    }

    if (currSize == 0)
    {
      start = 0;
      end = 0;
    }
    else
    {
      end = (end + 1) % size;
    }
    arr[end] = x;
    currSize++;
  }

  int pop()
  {
    if (currSize == 0)
    {
      return -1;
    }
    int poped = arr[start];
    if (currSize == 1)
    {
      start = end = -1;
    }
    else
    {
      start = (start + 1) % size;
    }
    currSize -= 1;
    return poped;
  }

  int peek()
  {
    if (currSize == 0)
    {
      return -1;
    }
    return arr[start];
  }

  bool isEmpty()
  {
    return currSize == 0;
  }
};
int main()
{
  ArrayQueue q;
  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Peek: " << q.peek() << endl;
  cout << "Pop: " << q.pop() << endl;
  cout << "Pop: " << q.pop() << endl;
  cout << "Is Empty: " << q.isEmpty() << endl;
  cout << "Pop: " << q.pop() << endl;
  cout << "Is Empty: " << q.isEmpty() << endl;
  return 0;
}