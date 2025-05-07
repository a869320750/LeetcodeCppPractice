#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            int result = 0;
            unordered_map<int,int> mp;
            int count = 0;
            mp[count] = -1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 1)
                {
                    ++count;
                } else
                {
                    --count;
                }

                if (mp.find(count)!= mp.end())
                {
                    result = max(result,i - mp[count]);
                } else {
                    mp[count] = i; 
                }
            }
            return result;
        }
};
int main()
{
    Solution s;
    // 测试用例1
    vector<int> input = {0, 1};
    int ans = s.findMaxLength(input);
    cout << ans << endl;

    // 测试用例2
    input = {0, 1, 0};
    ans = s.findMaxLength(input);
    cout << ans << endl;

    // 测试用例3
    input = {0,1,1,1,1,1,0,0,0};
    ans = s.findMaxLength(input);
    cout << ans << endl;
}