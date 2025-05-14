#include <iostream>
#include <array>
using namespace std;

void modifyarray(array<int, 8> a) // Pass by value
{
  for (int i = 0; i < a.size(); i++)
  {
    a[i] = a[i] + a.size(); // Modify the local copy of the array
  }
}

// Function to print the array
void printarray(const array<int, 8> &arr) // Passed by reference (read-only)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  array<int, 8> arr = {1, 2, 3, 4, 5, 6, 7, 8}; // Using std::array
  printarray(arr);

  modifyarray(arr); // Array passed by value (a copy is modified)
  cout << "After modifying the array (pass by value): " << endl;
  printarray(arr); // Original array is not modified

  return 0;
}
