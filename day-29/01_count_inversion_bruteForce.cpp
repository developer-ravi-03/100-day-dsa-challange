//  Count Inversion in an array using brute force approach
//  TC : O(n^2)
//  SC : O(1)
#include <iostream>
#include <vector>
using namespace std;
int countInversion(vector<int> &arr)
{
  int count = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      if (arr[i] > arr[j])
      {
        count++;
      }
    }
  }
  return count;
}
int main()
{
  vector<int> arr = {6, 3, 5, 2, 7};
  int count = countInversion(arr);
  cout << "Number of inversions: " << count << endl;
  return 0;
}