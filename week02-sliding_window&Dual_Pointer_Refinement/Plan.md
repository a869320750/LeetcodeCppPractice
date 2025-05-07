# 🧊 模块1：滑动窗口 & 双指针精进
## LeetCode 题号	题名	类型
- [x]  3	无重复字符的最长子串	基础滑窗模板
```cpp
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
```
- [x]  76	最小覆盖子串	滑窗+计数窗口

困难题竟然做出来了。

- [x]  438	找到字符串中所有字母异位词	固定窗口匹配

和上一题差不多

- [x]  567	字符串的排列	子串是否包含全排列

一个模板做好几道题

- [x]  1004	最大连续1的个数 III	滑窗 + 容忍限制
- [x]  424	替换后的最长重复字符	滑窗+频率控制
类似的套路
```cpp
    int characterReplacement(string s, int k) {
                vector<int> num(26);
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n) {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k) {
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
```
- [x]  11	盛最多水的容器	经典双指针
- [x]  42	接雨水	双指针/单调栈（进阶）
```cpp
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int MaxHeight=0;
        for (int i = 0; i < height.size(); i++) {
            if(height[i]>MaxHeight) {
                MaxHeight = height[i];
            }
            leftMax[i]=MaxHeight;
        }
        MaxHeight=0;
        for (int i = height.size()-1; i >= 0; i--) {
            if(height[i]>MaxHeight) {
                MaxHeight = height[i];
            }
            rightMax[i]=MaxHeight;
        }
        int result=0;
        for(int i=0;i<height.size();i++) {
            result+=min(leftMax[i],rightMax[i])-height[i];
        }
        return result;
    }
```
📌 建议顺序刷：3 → 438 → 76 → 1004 → 424 → 567 → 11 → 42