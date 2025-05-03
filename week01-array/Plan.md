# 序号	题目	关键词	难度

- [x]  1	两数之和	哈希表	简单
- [x]  2	三数之和	排序 + 双指针 + 哈希	中等
- [x]  3	四数之和	排序 + 双指针 + 哈希	中等
- [x]  4	存在重复元素	哈希表	简单
- [x]  5	存在重复元素 II（允许距离 <= k）	哈希表	简单
- [x]  6	数组中第一个出现一次的数字	哈希表	简单
- [x]  7	和为K的子数组	前缀和 + 哈希表	中等
    第一次听说前缀和
- [x]  8	连续数组（0和1数量相等的最长子数组）	哈希表	中等
想到了用前缀和，但是缺少优化，知道了一般是用前缀和做key，用下表做value
- [x]  9	最长连续序列	哈希表	中等
使用set存数据可以去重，然后依次判断是不是开头的，是开头的就往后走一遍算，不是开头的就跳过
- [x]  10	两个数组的交集	哈希表	简单
确实比较简单，这个老哥的答案有点东西：
```cpp
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        unordered_map<int ,int>hash;
        for(const auto &c:nums1)
        {
            hash[c]=1;
        }
        for(const auto &c:nums2)
        {
            --hash[c];
            if(hash[c]==0)
            result.push_back(c);
        }
        return result;
    }
```
- [x]  11	两个数组的交集 II	哈希表	简单
这个题目描述纯属瞎写啊，这道题本身比较简单，就不单独搞文件了，直接在平台上写了
```cpp
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto &&i:nums1) {
            if (mp1.count(i)) {
                ++mp1[i];
            } else {
                mp1[i] = 1;
            }
        }
        for(auto &&i:nums2) {
            if (mp2.count(i)) {
                ++mp2[i];
            } else {
                mp2[i] = 1;
            }
        }
        for(auto &&i:mp1){
            if (mp2.count(i.first)) {
                for(int j = 0; j < min(i.second,mp2[i.first]); j++) {
                    result.push_back(i.first);
                }
            }
        }
        return result;
    }
```
- [x]  12	数组中的第K个最大元素	堆 / 快排	中等

竟然是考过的一道题，两种方法
快速排序的特殊版本（快速选择）。分离函数通过双指针分离，然后外界一个循环类似折半查找。
第二种方法是堆排序，在C++里面就是priority_queue
```cpp
vector<int> heapSort(vector<int>& nums) {
    priority_queue<int> maxHeap; // 默认最大堆
    for (int num : nums) {
        maxHeap.push(num); // 所有元素入堆
    }
    
    vector<int> sorted;
    while (!maxHeap.empty()) {
        sorted.push_back(maxHeap.top()); // 取堆顶（最大值）
        maxHeap.pop(); // 删除堆顶
    }
    reverse(sorted.begin(), sorted.end()); // 最大堆需反转
    return sorted;
}
```
- [x]  13	缺失的第一个正数	哈希 + 原地置换	困难
- [x]  14	除自身以外数组的乘积	前后缀积	中等

有点意思,一个数组存左边的乘积，一个数组存右边的乘积：
```cpp
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> Left(nums.size());
        vector<int> Right(nums.size());
        int temp = 1;
        for(int i = 0; i < nums.size(); i++) {
            Left[i] = temp;
            temp = temp * nums[i];
        }
        temp = 1;
        for(int i = nums.size() - 1; i >= 0; --i) {
            Right[i] = temp;
            temp = temp * nums[i];
        }

        for(int i = 0; i < nums.size(); i++) {
            Left[i] = Left[i] * Right[i];
        }

        return Left;
    }
```
- [x]  15	移动零	双指针	简单

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
```cpp
void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while(right < nums.size()) {
            if(nums[right] != 0) {
                swap(nums[right], nums[left]);
                ++left;
                ++right;
            } else if (nums[right] == 0) {
                ++right;
            }
        }
    }
```
