#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>


using namespace std;

class Solution {
    public:
        bool check(unordered_map<char,int> &mp,  unordered_map<char,int> &mt) {
            for (auto kv : mt) {
                if (mp[kv.first] != kv.second) {
                    return false;
                }
            }
            return true;
        }
    
        vector<int> findAnagrams(string s, string p) {
            unordered_map<char,int> smp;
            unordered_map<char,int> pmp;
            vector<int> result;

            for (size_t i = 0; i < s.size(); i++)
            {
                smp[s[i]] = 0;
            }

            for (size_t i = 0; i < p.size(); i++)
            {
                if (!pmp.count(p[i]))
                {
                    pmp[p[i]] = 1;
                } else {
                    pmp[p[i]]++;
                }
            }

            int left = 0;
            int right = left + p.size() - 1;
            for (size_t i = left; i <= right; i++)
            {
                smp[s[i]]++;
            }
            

            while (right < s.size())
            {
                if(check(smp, pmp)) {
                    result.push_back(left);
                }
                smp[s[left]]--;
                ++left;
                ++right;
                smp[s[right]]++;
            }
            return result;
        }
    };

void showResult(vector<int> input)
{
    for(int val:input) {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    Solution s;
    //showResult(s.findAnagrams("cbaebabacd", "abc"));
    //showResult(s.findAnagrams("abab", "ab"));
    showResult(s.findAnagrams("bpaa", "aa"));
}