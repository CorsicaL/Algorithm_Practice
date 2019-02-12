## 283Move_Zeroes

给定一个数组 `nums`，编写一个函数将所有 `0`移动到数组的末尾，同时保持非零元素的相对顺序。

**示例:**

```
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
```

**说明**:

1. 必须在原数组上操作，不能拷贝额外的数组。
2. 尽量减少操作次数。

```c++
void moveZeroes(vector<int>& nums) {
    if (!nums.size()) return;
    int i = 0, j = 1;
    int n = nums.size();
    while (i < n && j < n) {
        if (nums[i]) {
            ++i;
        } else if (!nums[j] || j <= i) { //else if (!nums[j])
            ++j;
        } else {
            int tmp = nums[i];
            nums[i++] = nums[j];
            nums[j++] = tmp;
        }
        //j = max(j, i + 1);
    }
}
```

