// Interval List Intersections
// Leetcode : 986
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int m = firstList.size(), n = secondList.size();
        while (i < m && j < n)
        {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if (start1 <= start2)
            {
                if (end1 >= start2)
                {
                    int s = max(start1, start2);
                    int e = min(end1, end2);
                    res.push_back({s, e});
                }
            }
            else
            {
                if (end2 >= start1)
                {
                    int s = max(start1, start2);
                    int e = min(end1, end2);
                    res.push_back({s, e});
                }
            }

            if (end1 <= end2)
                i++;
            else
                j++;
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> firstList = {{0, 2}, {5, 6}, {8, 9}, {15, 24}, {25, 26}, {0, 0}};
    vector<vector<int>> secondList = {{1, 3}, {4, 6}, {7, 9}, {16, 24}, {24, 25}};
    vector<vector<int>> result = sol.intervalIntersection(firstList, secondList);

    cout << "Intersections: ";
    for (auto interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}