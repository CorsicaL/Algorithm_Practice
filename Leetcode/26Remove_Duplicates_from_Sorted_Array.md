## 26Remove_Duplicates_from_Sorted_Array

给定一个排序数组，你需要在**原地**删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在**原地修改输入数组**并在使用 O(1) 额外空间的条件下完成。

```c++
int i = 0, j = 1;
while (j < nums.size()) {
    if (nums[i] != nums[j]) {
        nums[++i] = nums[j];
    } else {
        ++j;
    }
}
```

### unique[l, r)

在排序数组的`[l, r)`区间中，把各不相同的元素放到前面排成`[l, a]`段各不相同的有序数组，返回`a+1`的指针或者iterator

### vector::erase[l, r)

删除`[l, r)`区间的元素

```
nums.erase(unique(nums.begin(), nums.end()), nums.end());
```

