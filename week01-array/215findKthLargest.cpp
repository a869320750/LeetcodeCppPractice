#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include "../tools/Testcase.h"

using namespace std;


class MaxHeap {
    private:
        vector<int> heap;
    
        void heapifyUp(int i) {
            while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
                swap(heap[i], heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }
    
        void heapifyDown(int i) {
            int n = heap.size();
            while (true) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int largest = i;
                
                if (left < n && heap[left] > heap[largest]) {
                    largest = left;
                }
                if (right < n && heap[right] > heap[largest]) {
                    largest = right;
                }
                if (largest == i) break;
                
                swap(heap[i], heap[largest]);
                i = largest;
            }
        }
    
    public:
        void push(int x) {
            heap.push_back(x);
            heapifyUp(heap.size() - 1);
        }
    
        int pop() {
            int top = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
            return top;
        }
    
        bool empty() {
            return heap.empty();
        }
    };


class Solution {
    public:
        // 快排解法，使用快排的patition函数，把一段数据
        int patition(vector<int> &nums, int left, int right) {
            int target = nums[left];
            int l = left + 1;
            int r = right;
            while (r>=l)
            {
                if (nums[l]<= target && nums[r]>= target)
                {
                    swap(nums[l],nums[r]);
                    ++l;
                    --r;
                } 
                
                else if (nums[l]> target)
                {
                    ++l;
                }
                else if (nums[r]< target)
                {
                    --r;
                }
                
            }
            swap(nums[left], nums[r]);
            return r;
        }
        int findKthLargest(vector<int>& nums, int k) {
            int left = 0;
            int right = nums.size() - 1;
            int r;
            while (true)
            {
                r = patition(nums,left,right);
                if (r == k-1) {
                    return nums[r];
                } else if(r > k-1) {
                    right = r-1;
                } else if(r < k-1) {
                    left = r+1;
                }
            }
        }
    
        // 堆排序算法：
        int findKthLargestPre(vector<int>& nums, int k){
            MaxHeap maxHeap;
            int result;
            for (int num : nums) {
                maxHeap.push(num);
            }

            vector<int> sorted;
            while (!maxHeap.empty() && k>0) {
                result = maxHeap.pop();
                --k;
            }
            reverse(sorted.begin(), sorted.end()); // 最大堆需反转
            return result;
        }

    
    };

int main()
{
    Solution s;
    // 测试用例1
    vector<int> input = {3,2,1,5,6,4};
    int ans = s.findKthLargestPre(input,2);
    cout << ans << endl;

    // 测试用例2
    input = {3,2,3,1,2,4,5,5,6};
    ans = s.findKthLargestPre(input,4);
    cout << ans << endl;
}