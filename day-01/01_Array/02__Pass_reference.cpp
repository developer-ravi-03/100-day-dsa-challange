#include <iostream>
using namespace std;
void modifyarray(int (&a)[8])
{
  int size = sizeof(a) / sizeof(a[0]);
  for (int i = 0; i < size; i++)
  {
    // *(a + i) = *(a + i) + size;

    a[i] = a[i] + size;

    // cout << "Inside modifyarray: " << size << endl;
    // cout << "Inside modifyarray: " << a[i] << endl;
  }
}
// Function to print the array
void printarray(int (&arr)[8])
{
  int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main()
{
  int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  printarray(arr);
  modifyarray(arr);
  cout << "After modifying the array: " << endl;
  printarray(arr);

  return 0;
}