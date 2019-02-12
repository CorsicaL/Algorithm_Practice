## 215Kth_Largest_Element_in_an_Array

在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

```c++
sort(nums.begin(), nums.end());
return nums[nums.size() - k];
```

### nth_element(begin, nth, end)

在一个未排序的区间`[begin, end)`中，把第`nth`个位置放入大小正确的数（从小到大排列，排在第n个位置的数），这个数的左边都比他小，右边都比他大，但不是全部有序

```c++
auto it = nums.begin();
for (int i = 0; i < nums.size() - 1; ++i) {
    ++it;
}
nth_element(nums.begin(), it, nums.end());
return nums[nums.size() - k];
```

