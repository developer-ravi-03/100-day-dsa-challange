#include <iostream>
using namespace std;

class CircularQueue
{
  int *arr;
  int currSize, cap;
  int f, r;

public:
  CircularQueue(int size)
  {
    cap = size;
    currSize = 0;
    arr = new int[cap];
    f = 0, r = -1;
  }

  void push(int data)
  {
    if (currSize == cap)
    {
      cout << "CQ is full\n";
      return;
    }

    r = (r + 1) % cap;
    arr[r] = data;
    currSize++;
  }

  void pop()
  {
    if (empty())
    {
      cout << "CQ is Empty\n";
      return;
    }
    f = (f + 1) % cap;
    currSize--;
  }

  int front()
  {
    if (empty())
    {
      cout << "CQ is Empty\n";
      return -1;
    }
    return arr[f];
  }

  bool empty()
  {
    return currSize == 0;
  }

  void printArr()
  {
    for (int i = 0; i < cap; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  CircularQueue cq(3);

  cq.push(1);
  cq.push(2);
  cq.push(3);

  cq.printArr();

  cq.pop();
  cq.push(4);
  cq.push(5);

  cq.printArr();

  return 0;
}