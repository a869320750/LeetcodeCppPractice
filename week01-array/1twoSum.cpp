#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> myhash;
            for(int i = 0; i < nums.size() ;i++) {
                auto temp = myhash.find(target - nums[i]);
                if(temp != myhash.end()) {
                    return {temp->second, i};
                } else {
                    myhash[nums[i]] = i;
                }
            }
            return {};
    
        }
    };

int main()
{
    Solution s;
    vector<int> v;
    // 测试用例1
    vector<int> input = {2,7,11,15};
    v = s.twoSum(input, 9);
    cout<< v[0] << "," << v[1] << endl;

    // 测试用例2
    input = {3,2,4};
    v = s.twoSum(input, 6);
    cout<< v[0] << "," << v[1] << endl;

    // 测试用例3
    input = {3,3};
    v = s.twoSum(input, 6);
    cout<< v[0] << "," << v[1] << endl;

}