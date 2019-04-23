## 55Jump_Game

**题目描述**：给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

**示例 1:**

```
输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
```

**示例 2:**

```
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
```

**解题思路**：动态规划

`pos`表示当前可到达的最远的位置，`i+nums[i]`表示当在`i`这个位置的时候，可以到达的最远的位置，每次决策`nums[i]`是否取用，取两者中大的来更新`pos`。`i`必须小于`nums.size()`且小于等于`pos`，`pos`后面的位置是无法到达的。

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return true;
        int pos = 0;
        for (int i = 0; i < nums.size() && i <= pos; ++i) {
            pos = max(pos, i+nums[i]);
            if (pos >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
```

