#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int,int> recorder;
            for (int i = 0; i<nums.size();i++) {
                if (recorder.find(nums[i]) == recorder.end()) {
                    recorder[nums[i]] = i;
                }
                else {
                    if (abs(recorder[nums[i]] - i) <= k) {
                        return true;
                    } else {
                        recorder[nums[i]] = i;
                    }
                    
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
    bool ans = s.containsNearbyDuplicate(input,3);
    cout << ans << endl;

    // 测试用例2
    input = {1,0,1,1};
    ans = s.containsNearbyDuplicate(input,1);
    cout << ans << endl;

    // 测试用例3
    input = {1,2,3,1,2,3};
    ans = s.containsNearbyDuplicate(input,2);
    cout << ans << endl;
}