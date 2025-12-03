#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<string> tag_name;
map<string, string> mp;

void insert_mp(string &attrName, string &attrValue)
{
  string fullname;
  for (string &str : tag_name)
  {
    fullname += str + '.'; // tag1.tag2.
  }
  fullname.pop_back();        // tag1.tag2
  fullname += "~" + attrName; // tag.tag2~name
  mp[fullname] = attrValue;
}

int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < a; i++)
  {
    char ch;
    cin >> ch; // taking <

    if (cin.peek() == '/')
    { // </tag>
      string cn;
      cin >> cn;
      tag_name.pop_back();
    }
    else
    {
      string name;
      cin >> name; // taking tag name

      if (name.back() == '>')
      {                           //<tag1>
        name.pop_back();          // tag1> => tag1
        tag_name.push_back(name); // adding tag name int vector
      }
      else
      {
        tag_name.push_back(name); // adding tag name int vector
        for (;;)
        {
          string attrName, attrValue;
          char eq;
          cin >> attrName >> eq >> attrValue;
          if (attrValue.back() == '>')
          {
            attrValue.pop_back();
            attrValue.pop_back();
            attrValue = attrValue.substr(1); // HelloWorld
            insert_mp(attrName, attrValue);
            break;
          }
          else
          {
            attrValue.pop_back();
            attrValue = attrValue.substr(1); // HelloWorld
            insert_mp(attrName, attrValue);
          }
        }
      }
    }
  }

  for (int i = 0; i < b; i++)
  {
    string query;
    cin >> query;
    if (mp.find(query) != mp.end())
    {
      cout << mp[query] << endl;
    }
    else
    {
      cout << "Not Found!" << endl;
    }
  }

  return 0;
}
