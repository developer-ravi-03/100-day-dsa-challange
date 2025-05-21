#include <iostream>
using namespace std;
int main()
{
  int a = 10;
  int *ptr = &a;
  cout << a << endl;
  cout << *(&a) << endl;
  cout << ptr << endl;
  cout << *ptr << endl;
  cout << &ptr << endl;
  int b = 20;
  ptr = &b; // assign new value to ptr
  cout << *ptr << endl;

  int **ptr1 = &ptr;
  cout << *ptr1 << endl;
  cout << **ptr1 << endl;
  cout << ptr1 << endl;
  return 0;
}