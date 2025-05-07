#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count_zero = 0;
        if(nums[0] == 0) {
            count_zero++;
        }
        int result = 0;
        while(right < nums.size() && left < nums.size()) {
            if (count_zero == k) {
                while (right + 1 < nums.size() && nums[right + 1] != 0)
                {
                    right++;
                }
                
                result = max(result,right - left + 1);
                if (nums[left] == 0) {
                    --count_zero;
                }
                ++left;
                ++right;
                if(right == nums.size()) {
                    result = max(result,right - left);
                    break;
                }
                if(nums[right] == 0) {
                    count_zero++;
                }
            }
            else if (count_zero > k) {
                if (nums[left] == 0) {
                    --count_zero;
                }
                ++left;
            }
            else {
                ++right;
                if(right == nums.size()) {
                    result = max(result,right - left);
                    break;
                }
                if(nums[right] == 0) {
                    count_zero++;
                }
            }
        }
        return result;
    }
};

    int main()
    {
        Solution s;
        vector<int> input = {1,1,1,0,0,0,1,1,1,1,0};
        cout << s.longestOnes(input, 2) << endl;
        input = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        cout << s.longestOnes(input, 3) << endl;
    }