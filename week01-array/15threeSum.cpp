#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;


class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<int> input = vector<int>(nums.begin(), nums.end());
            sort(input.begin(), input.end());
    
            set<vector<int>> temp;
            if(input.size() < 3) {
                return vector<vector<int>>(temp.begin(),temp.end());
            }
    
            for(int i = 0; i < input.size() -2; i++) {
                int j = i+1;
                int k = input.size()-1;
                while(k > j) {
                    // cout << i << ":" << input[i] << "," << j << ":" << input[j] << ","  << k << ":" << input[k] << "," << endl;
                    if(input[k] + input[j] + input[i] == 0) {
                        temp.insert({input[i], input[j], input[k]});
                        // cout << "check in"<< endl;
                        k=k-1;
                        j=j+1;
                    }
                    if(input[k] + input[j] + input[i] > 0) {
                        k=k-1;
                    }
                    if(input[k] + input[j] + input[i] < 0) {
                        j=j+1;
                    }
                }
            }
    
            return vector<vector<int>>(temp.begin(),temp.end());
        }
    };

int main()
{
    Solution s;
    vector<vector<int>> v;
    // 测试用例1
    vector<int> input = {-1,0,1,2,-1,-4};
    v = s.threeSum(input);
    cout << v.size() << endl;

    // 测试用例2
    input = {0,1,1};
    v = s.threeSum(input);
    cout << v.size() << endl;

    // 测试用例3
    input = {0,0,0};
    v = s.threeSum(input);
    cout << v.size() << endl;
}