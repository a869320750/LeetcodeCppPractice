#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); i++)
        {
            if (us.find(nums[i]) != us.end())
            {
                return true;
            }
            else
            {
                us.insert(nums[i]);
            }
            
        }
        return false;
    }
};

int main()
{
    Solution s;
    // 测试用例1
    vector<int> input = {1, 2, 3, 1};
    bool ans = s.containsDuplicate(input);
    cout << ans << endl;

    // 测试用例2
    input = {1,2,3,4};
    ans = s.containsDuplicate(input);
    cout << ans << endl;

    // 测试用例3
    input = {1,1,1,3,3,4,3,2,4,2};
    ans = s.containsDuplicate(input);
    cout << ans << endl;
}