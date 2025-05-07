#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> answer;
        int length = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            {
                break;
            }
            if ((long)nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
            {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                {
                    break;
                }
                if ((long)nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)
                {
                    continue;
                }
                int left = j + 1;
                int right = length - 1;
                while (right > left)
                {
                    long temp = nums[i] + nums[j] + nums[left] + nums[right];
                    if (temp == target)
                    {
                        answer.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        right--;
                    }
                    else if (temp > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
        return answer;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v;
    // 测试用例1
    vector<int> input = {1, 0, -1, 0, -2, 2};
    v = s.fourSum(input, 0);
    cout << v.size() << endl;

    // 测试用例2
    input = {2, 2, 2, 2, 2};
    v = s.fourSum(input, 8);
    cout << v.size() << endl;
}