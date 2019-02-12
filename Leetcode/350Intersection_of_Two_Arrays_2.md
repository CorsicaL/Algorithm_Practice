## 350Intersection_of_Two_Arrays_2

给定两个数组，编写一个函数来计算它们的交集。

**示例 1:**

```
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
```

**示例 2:**

```
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
```

**说明：**

- 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
- 我们可以不考虑输出结果的顺序。

```c++
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size(); //方便使用和阅读
        vector<int> ret;
        for (int i = 0, j = 0; i < n && j < m; ) {
            if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                ++i;
                ++j;
                continue;
            }
            if (nums1[i] < nums2[j]) ++i;
            else ++j;
        }
        return ret;
}
```

