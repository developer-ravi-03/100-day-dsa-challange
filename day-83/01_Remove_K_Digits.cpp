//Remove K Digits
//GFG: Problem of the day
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        int n=s.size();
        if(k==s.size()) return "0";
        
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k && s[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        
        //if k is remaining
        while(!st.empty() && k){
            st.pop();
            k--;
        }
        
        string res="";
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        while(res.size()>1 && res.back()=='0'){
            res.pop_back();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
int main()
{
  Solution sol;
  string s = "1432219";
  int k = 3;
  cout << sol.removeKdig(s, k) << endl;
  return 0;
}