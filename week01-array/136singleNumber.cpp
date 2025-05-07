#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_set<int> record;
            for (int num:nums) {
                if(record.find(num) == record.end()) {
                    record.insert(num);
                } else {
                    record.erase(num);
                }
            }
            return *record.begin();
        }
    };

int main()
{
    Solution s;
    int v;
    // 测试用例1
    vector<int> input = {2,2,1};
    v = s.singleNumber(input);
    cout<< v << endl;

    // 测试用例2
    input = {4,1,2,1,2};
    v = s.singleNumber(input);
    cout<< v << endl;

    // 测试用例3
    input = {1};
    v = s.singleNumber(input);
    cout<< v << endl;

}