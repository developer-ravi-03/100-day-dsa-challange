#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  char str[] = {'a', 'b', 'c', '\0'};
  cout << str << endl;
  cout << strlen(str) << endl;

  // strore sting
  char str1[] = {"Ravi"};
  cout << str1 << endl;
  cout << strlen(str1) << endl;

  int length = 0;
  for (int i = 0; i < str[i] != '\0'; i++)
  {
    length++;
  }
  cout << "length " << length;

  // // input - it doesnt takes space
  // char str3[100];
  // cout << "Enter input 1: " << endl;
  // cin >> str3;
  // cout << str3 << endl;

  // // input - it takes space also
  // char str4[100];
  // cout << "Enter input 2: " << endl;
  // cin.getline(str4, 100);
  // cout << str4 << endl;

  // input - it doesnt take input after special character that are defied
  // char str5[100];
  // cout << "Enter input 3: " << endl;
  // cin.getline(str5, 100, '$');
  // cout << str5 << endl;

  // input char array
  // char str6[5];
  // cout << "Enter input : " << endl;
  // cin.getline(str6, 5);
  // for (char ch : str6)
  // {

  //   cout << ch << " ";
  // }

  return 0;
}