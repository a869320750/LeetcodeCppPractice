#include<iostream>
#include<unordered_map>
#include<string>


using namespace std;

class Solution {
    public:
        bool check(unordered_map<char,int> &mp,  unordered_map<char,int> &mt) {
            for (auto key : mt) {
                if (mp[key.first] < key.second) {
                    return false;
                }
            }
            return true;
        }
        string minWindow(string s, string t) {
            unordered_map<char,int> st;
            unordered_map<char,int> mt;
            for(char c : s) {
                st[c] = 0;
            }
            for (char c : t) {
                if (!mt.count(c))
                {
                    mt[c] = 1;
                } else {
                    mt[c]++;
                }
            }
            for (char c : t) {
                if (!st.count(c))
                {
                    return "";
                }
            }

            int left = 0;
            int right = 1;
            st[s[left]] = 1;
            int ans_left = 0;
            int ans_right = 0;
            int minlength = s.size() + 1;
            while (right <= s.size()) {
                if(!check(st,mt)) {
                    st[s[right]]++;
                    ++right;
                } else {
                    if (right - left < minlength) {
                        minlength = right -left;
                        ans_left = left;
                        ans_right = right;
                    }
                    st[s[left]]--;
                    ++left;
                    
                }
            }
            if (ans_left == ans_right)
            {
                return "";
            }
            return s.substr(ans_left,ans_right - ans_left);
        }
    };

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.minWindow("a", "a") << endl;
    cout << s.minWindow("a", "aa") << endl;
    cout << s.minWindow("ab", "a") << endl;
}