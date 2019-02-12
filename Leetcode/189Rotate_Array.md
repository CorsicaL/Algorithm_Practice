## 189Rotate_Array

给定一个数组，将数组中的元素向右移动 *k* 个位置，其中 *k* 是非负数。

暴力：往右移动k次

```c++
int n = nums.size(); //重复多次使用的，设为一个变量
k = k % n;
while (k--) {
    int tmp = nums[n - 1];
    for (int i = n - 1; i > 0; ++i) {
        nums[i] = nums[i - 1];
    }
    nums[0] = tmp;
}
```

```c++
//[1, 2, 3, 4, 5, 6, 7], k = 3

reverse(nums.begin(), nums.end());

//[7, 6, 5, 4, 3, 2, 1]

auto it1 = nums.begin();
auto it2 = nums.begin();
while (k--) {
	it1++;
    it2++;
}
reverse(nums.begin(), it1);

//[5, 6, 7, 4, 3, 2, 1]

reverse(it2, nums.end()); //iterator 最好只用一次，vector被改变之后，iterator可能指向意料之外的地方

//[5, 6, 7, 1, 2, 3, 4]
```

reverse的实现

```c
void reverse(int *l, int *r) {
    --r;
    for (; l < r; ++l, --r) {
        int tmp = *l;
        *l = *r;
        *r = tmp;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, nums + numsSize);
    reverse(nums, nums + k);
    reverse(nums + k, nums + numsSize);
}
```

