// leetcode-125
// Valid Pallindrome
// TC - O(n)
#include <iostream>
using namespace std;
bool isAlphaNumeric(char ch)
{
  if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
  {
    return true;
  }
  return false;
}

bool isPalindrome(string s)
{
  int st = 0, end = s.length() - 1;
  while (st < end)
  {
    if (!isAlphaNumeric(s[st]))
    {
      st++;
      continue;
    }

    if (!isAlphaNumeric(s[end]))
    {
      end--;
      continue;
    }

    if (tolower(s[st]) != tolower(s[end]))
    {
      return false;
    }
    st++;
    end--;
  }
  return true;
}
int main()
{
  string str = "race a car";
  bool pallindrom = isPalindrome(str);
  if (pallindrom)
  {
    cout << "Valid Pallindrome";
  }
  else
  {
    cout << "Not Valid Pallindrome";
  }

  return 0;
}