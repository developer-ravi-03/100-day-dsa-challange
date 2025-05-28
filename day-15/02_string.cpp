#include <iostream>

using namespace std;
int main()
{
  string str = "Ravi Kumar";

  cout << str << endl;
  // update
  str = "mohan";
  cout << str << endl;

  string str1 = "Ravi";
  string str2 = str + str1;
  cout << str2 << endl;
  cout << (str < str1) << endl;
  cout << (str == str1) << endl;

  string str3 = "Ravi";
  cout << (str1 == str3) << endl;
  cout << str2.length() << endl;

  string str5;
  // cout << "enter name :";
  // cin >> str5;
  // cout << str5;

  cout << "enter name :";
  getline(cin, str5);
  cout << str5 << endl;

  // for (int i = 0; i < str5.length(); i++)
  // {
  //   cout << str5[i] << " ";
  // }

  for (char ch : str5)
  {
    cout << ch << " ";
  }

  return 0;
}