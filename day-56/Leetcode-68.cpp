#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int MAX_WIDTH;
  string findline(int i, int j, int eachGaddhaSpace, int extraGaddhaSpace,
                  vector<string> &words)
  {
    string line;
    for (int k = i; k < j; k++)
    {
      line += words[k];
      if (k < j - 1)
      {
        for (int z = 1; z <= eachGaddhaSpace; z++)
        {
          line += " ";
        }
        if (extraGaddhaSpace > 0)
        {
          line += " ";
          extraGaddhaSpace--;
        }
      }
    }

    while (line.length() < MAX_WIDTH)
    {
      line += " ";
    }
    return line;
  }

  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    vector<string> result;
    int n = words.size();
    MAX_WIDTH = maxWidth;

    int i = 0;
    while (i < n)
    {
      int lettersCount = words[i].length();
      int j = i + 1;
      int gaddhe = 0;
      while (j < n &&
             words[j].length() + 1 + gaddhe + lettersCount <= maxWidth)
      {
        lettersCount += words[j].length();
        gaddhe += 1;
        j++;
      }

      int remainingGaddhe = maxWidth - lettersCount;
      int eachGaddhaSpace = gaddhe == 0 ? 0 : remainingGaddhe / gaddhe;
      int extraGaddhaSpace = gaddhe == 0 ? 0 : remainingGaddhe % gaddhe;

      if (j == n)
      {
        eachGaddhaSpace = 1;
        extraGaddhaSpace = 0;
      }

      result.push_back(
          findline(i, j, eachGaddhaSpace, extraGaddhaSpace, words));
      i = j;
    }

    return result;
  }
};
int main()
{
  Solution sol;
  vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;
  vector<string> justified = sol.fullJustify(words, maxWidth);
  for (const string &line : justified)
  {
    cout << "\"" << line << "\"" << endl;
  }
  return 0;
}