#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();
            int result = n + 1;
            for(int i = 0; i< n ;i++) {
                if(nums[i] <= 0) {
                    nums[i] = n + 1;
                }
            }
            for(int i = 0; i< n ;i++) {
                int temp = abs(nums[i]);
                if (temp > 0 && temp <= n) {
                    if(nums[temp - 1] > 0) {
                        nums[temp - 1] =  -nums[temp - 1];
                    }
                }
            }
            for(int i = 0; i< n ;i++) {
                int temp = nums[i];
                if (temp > 0) {
                    result = min(result,i+1);
                }
            }
            return result;
        }
    };

int main()
{
    Solution s;
    // 测试用例1
    vector<int> input = {1,2,0};
    int ans = s.firstMissingPositive(input);
    cout << ans << endl;

    // 测试用例2
    input = {3,4,-1,1};
    ans = s.firstMissingPositive(input);
    cout << ans << endl;

    // 测试用例3
    input = {7,8,9,11,12};
    ans = s.firstMissingPositive(input);
    cout << ans << endl;

    // 测试用例4
    input = {-5};
    ans = s.firstMissingPositive(input);
    cout << ans << endl;

    // 测试用例5
    input = {-1,-2,-60,40,43};
    ans = s.firstMissingPositive(input);
    cout << ans << endl;

    // 测试用例5
    input = {1, 1};
    ans = s.firstMissingPositive(input);
    cout << ans << endl;
}