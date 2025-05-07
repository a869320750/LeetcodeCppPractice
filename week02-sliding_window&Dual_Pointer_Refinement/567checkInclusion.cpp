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
        bool checkInclusion(string s1, string s2) {
            unordered_map<char,int> smp;
                unordered_map<char,int> pmp;
                vector<int> result;
    
                for (size_t i = 0; i < s2.size(); i++)
                {
                    smp[s2[i]] = 0;
                }
    
                for (size_t i = 0; i < s1.size(); i++)
                {
                    if (!pmp.count(s1[i]))
                    {
                        pmp[s1[i]] = 1;
                    } else {
                        pmp[s1[i]]++;
                    }
                }
    
                int left = 0;
                int right = left + s1.size() - 1;
                for (size_t i = left; i <= right; i++)
                {
                    smp[s2[i]]++;
                }
                
    
                while (right < s2.size())
                {
                    if(check(smp, pmp)) {
                        return true;
                    }
                    smp[s2[left]]--;
                    ++left;
                    ++right;
                    smp[s2[right]]++;
                }
                return false;
        }
    };

    int main()
    {
        Solution s;
        cout << s.checkInclusion("dinitrophenylhydrazine", "dimethylhydrazine") << endl;
    }